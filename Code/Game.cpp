#include "Game.hpp"
#include "Invoker.hpp"

uintptr_t m_bytesss;

void(*rage::scrNativeCallContext::SetVectorResults)(rage::scrNativeCallContext*) = nullptr;
int Join = 0;
bool Joiner;
template <size_t size>
struct bytes
{
	BYTE byte[size];
};

namespace Big
{
	GameVariables::GameVariables() :

		m_GameState(Signature("GS", "83 3D ? ? ? ? ? 75 17 8B 43 20 2").Scan().Add(2).Rip().Add(1).As<decltype(m_GameState)>()),
		m_FrameCount(Signature("FC", "8B 15 ? ? ? ? 41 FF CF").Scan().Add(2).As<decltype(m_GameState)>()),
		m_GameWindow(FindWindowA("grcWindow", "Grand Theft Auto V")),
		m_Swapchain(Signature("S", "48 8B 0D ? ? ? ? 48 8B 01 44 8D 43 01 33 D2 FF 50 40 8B C8").Scan().Add(3).Rip().As<decltype(m_Swapchain)&>()),
		m_NativeRegistrations(Signature("NR", "48 83 EC 20 48 8D 0D ? ? ? ? E8 ? ? ? ? 0F B7 15 ? ? ? ? 33 FF").Scan().Add(7).Rip().As<decltype(m_NativeRegistrations)>()),
		m_NativeReturn(Signature("NRT", "FF E3").Scan().Add(0).As<decltype(m_NativeReturn)>()),
		m_GlobalBase(Signature("GBS", "48 8D 15 ? ? ? ? 4C 8B C0 E8 ? ? ? ? 48 85 FF 48 89 1D").Scan().Add(3).Rip().As<decltype(m_GlobalBase)>())
	{
		//get_gtav_version();
		auto sig = Signature("GB", "48 83 EC 60 48 8D 0D ? ? ? ? E8").Scan().Sub(17);
		m_GameBuild = sig.Add(265 + 3).Rip().As<decltype(m_GameBuild)>();

		char* c_location = nullptr;
		//World Pointer
		auto p_worldPtr = Memory::pattern("48 8B 05 ? ? ? ? 45 ? ? ? ? 48 8B 48 08 48 85 C9 74 07");
		c_location = p_worldPtr.count(1).get(0).get<char>(0);
		m_WorldPtr = reinterpret_cast<uint64_t>(c_location) + *reinterpret_cast<int*>(reinterpret_cast<uint64_t>(c_location) + 3) + 7;

		auto p_fixVector3Result = Memory::pattern("83 79 18 00 48 8B D1 74 4A FF 4A 18");
		auto void_location = p_fixVector3Result.count(1).get(0).get<void>(0);
		if (void_location != nullptr) rage::scrNativeCallContext::SetVectorResults = (void(*)(rage::scrNativeCallContext*))(void_location);
	}

	void GameVariables::PostInit()
	{

	}
	enum eGtavVersion : int {
		version_unknown = -1,
		version_socialclub = 0,
		version_steam = 1,
		version_epicgames = 2,
	};
	
	GameFunctions::GameFunctions() :
		m_IsDlcPresent(Signature("IDP", "84 C0 74 0D 8D 53 0C").Scan().Sub(63).As<decltype(m_IsDlcPresent)>()),
		m_GetEventData(Signature("GED", "48 85 C0 74 14 4C 8B 10").Scan().Sub(28).As<decltype(m_GetEventData)>()),
		m_GetLabelText(Signature("GXT", "75 ? E8 ? ? ? ? 8B 0D ? ? ? ? 65 48 8B 04 25 ? ? ? ? BA ? ? ? ? 48 8B 04 C8 8B 0C 02 D1 E9").Scan().Sub(19).As<decltype(m_GetLabelText)>()),
		m_AssignPhysicalIndexHandler(Signature("APIH", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 54 41 55 41 56 41 57 48 83 EC 20 41 8A E8").Scan().As<decltype(m_AssignPhysicalIndexHandler)>()),
		m_PlayerWildcard(Signature("PW", "75 1C E8 ? ? ? ? 48 85").Scan().Sub(11).As<decltype(m_PlayerWildcard)>()),                //Game.hpp WildCardCaller Sig: 48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC 20 48 8B F9 48 8B 0D ? ? ? ? 8B 51 20 
		m_PlayerListMenuConstructor(Signature("PLMC", "75 1B 48 8D 4F").Scan().Sub(248).As<decltype(m_PlayerListMenuConstructor)>()), //CPlayerListMenu 8th func
		m_DistanceToSun(Signature("DTS", "F3 0F 59 0D ? ? ? ? 45 8A C1 ").Scan().As<decltype(m_DistanceToSun)>()),
		m_PointerToHande(Signature("PTH", "48 8B F9 48 83 C1 10 33 DB").Scan().Sub(0x15).As<decltype(m_PointerToHande)>()),
		replay_interface(Signature("RI", "48 8D 0D ? ? ? ? 48 8B D7 E8 ? ? ? ? 48 8D 0D ? ? ? ? 8A D8 E8 ? ? ? ? 84 DB 75 13 48 8D 0D ? ? ? ?").Scan().As<decltype(replay_interface)>()),
		m_ScriptedGameEvent(Signature("SGE", "40 53 48 81 EC ? ? ? ? 44 8B 81 ? ? ? ? 4C 8B CA 41 8D 40 FF 3D ? ? ? ? 77 42").Scan().As<decltype(m_ScriptedGameEvent)>()),
		m_NetworkEvents(Signature("NE", "66 41 83 F9 ? 0F 83 ? ? ? ?").Scan().As<decltype(m_NetworkEvents)>()),
		m_TransactionError(Signature("TE", "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 56 41 57 48 83 EC 60 4C 8B F2 48 8B 94 24 ? ? ? ? 33 DB").Scan().As<decltype(m_TransactionError)>()),
		m_ModelInfo(Signature("MI", "0F B7 05 ? ? ? ? 45 33 C9 4C 8B DA 66 85 C0 0F 84 ? ? ? ? 44 0F B7 C0 33 D2 8B C1 41 F7 F0 48 8B 05 ? ? ? ? 4C 8B 14 D0 EB 09 41 3B 0A 74 54").Scan().As<decltype(m_ModelInfo)>()),
		m_BypassChat(Signature("BC", "E8 ? ? ? ? 83 F8 FF 75 B9").Scan().Add(1).Rip().As<decltype(m_BypassChat)>()),
		m_ScriptGlobals(Signature("SG", "48 8D 15 ? ? ? ? 4C 8B C0 E8 ? ? ? ? 48 85 FF 48 89 1D").Scan().Add(3).Rip().As<decltype(m_ScriptGlobals)>()),
		m_ProcessNetObject(Signature("PNO", "48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 48 89 78 20 41 56 48 83 EC 20 4C 8B F2 48 8B E9 BB 01 00 00 00").Scan().As<decltype(m_ProcessNetObject)>()),
		m_ForceHostOfScript(Signature("FHOS", "48 89 5C 24 ? 57 48 83 EC 50 48 8B FA 48 8B D9 E8 ? ? ? ? 83 7B 10 08").Scan().As<decltype(m_ForceHostOfScript)>()),
		gta_threads(Signature("GT", "48 8B C8 EB 03 49 8B CD 48 8B 05").Scan().Add(11).Rip().As<decltype(gta_threads)>()),
		small_host_token_patch(Signature("SHTP", "C6 05 ? ? ? ? ? 48 8B CB E8 ? ? ? ? 84 C0 75 08").Scan().As<decltype(small_host_token_patch)>()),
		m_GetHostOfScript(Signature("GHOSCRIPT", "83 F9 1F 77 05").Scan().Sub(14).As<decltype(m_GetHostOfScript)>()),
		m_NetworkPlayerManager(Signature("NPM", "48 8B 0D ? ? ? ? 8A D3 48 8B 01 FF 50 ? 4C 8B 07 48 8B CF").Scan().Add(3).Rip().As<netPlayerMgrBase**>()),
		m_CanApplyToObject(Signature("CATB", "48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 48 89 78 20 41 56 48 83 EC 20 4C 8B F2 48 8B E9 BB ? ? ? ?").Scan().As<decltype(m_CanApplyToObject)>()),
		m_GetSyncTreeFromCloneType(Signature("GSTFCT", "0F B7 CA 83 F9 07").Scan().As<decltype(m_GetSyncTreeFromCloneType)>()),
		m_ChatSender(Signature("CS", "E8 ? ? ? ? 83 BD ? ? ? ? ? 48 8B D8 0F 8D ? ? ? ? 48 8B ? ? ?").Scan().Add(0x1).Rip().As<decltype(m_ChatSender)>()),
		m_ChatMessage(Signature("CM", "40 88 B3 ? ? ? ? 89 73 08 48 39 B3 ? ? ? ? 75 24 48 8D 05 ? ? ? ? 48 8B CB 48 89 B3").Scan().Add(0x16).Rip().As<decltype(m_ChatMessage)>()),
		m_WeatherBypass(Signature("WB", "0F 29 62 20").Scan().As<decltype(m_WeatherBypass)>()),
		m_Triggerscriptevent(Signature("TSE", "48 8B C4 48 89 58 08 48 89 68 10 48 89 70 18 48 89 78 20 41 56 48 81 EC ? ? ? ? 45 8B F0 41 8B F9").Scan().As<decltype(m_Triggerscriptevent)>()),
		m_WeatherBypass2(Signature("WB2", "0F 14 E3 0F 29 62 50").Scan().As<decltype(m_WeatherBypass2)>()),//AzimuthWest
		m_WeatherBypass3(Signature("WB3", "0F 29 82 50 05 00 00").Scan().As<decltype(m_WeatherBypass3)>()),//Moon
		m_WeatherBypass4(Signature("WB4", "0F 29 82 C0 01 00 00").Scan().As<decltype(m_WeatherBypass4)>()),//Sun
		m_WeatherBypass5(Signature("WB5", "0F 29 A2 80 00 00 00").Scan().As<decltype(m_WeatherBypass5)>()),//Azimuth Transition
		m_WeatherBypass6(Signature("WB6", "0F 29 8B 60 03 00 00").Scan().As<decltype(m_WeatherBypass6)>()),//CloudBase
		m_WeatherBypass7(Signature("WB7", "0F 29 A2 80 03 00 00").Scan().As<decltype(m_WeatherBypass7)>()),//CloudMid
		m_WeatherBypass8(Signature("WB8", "0F 29 A2 B0 00 00 00").Scan().As<decltype(m_WeatherBypass8)>()),//Zenith
		m_WeatherBypass9(Signature("WB9", "0F 29 A2 E0 00 00 00").Scan().As<decltype(m_WeatherBypass9)>()),//Zenith Transition
		m_WaterQuads(Signature("WT", "4D 8B E0 4C 8B 05 ? ? ? ?").Scan().As<decltype(m_WaterQuads)>()), //4D 8B E0 4C 8B 05 ? ? ? ?
		m_SendNetInfo(Signature("SNI", "48 89 5C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 48 81 EC ? ? ? ? 4C 8B F1 48 8D 4C 24 ?").Scan().As<decltype(m_SendNetInfo)>()),
		m_PickupRewardMoneyIsApplicableToPlayer(Signature("PRMIATP", "49 8B 80 ? ? ? ? 48 85 C0 74 0C F6 80 ? ? ? ? ? 75 03").Scan().As<decltype(m_PickupRewardMoneyIsApplicableToPlayer)>()),
		m_presence_game_invite(Signature("PGINVITE", "4C 8B DA 48 8B C1").Scan().As<decltype(m_presence_game_invite)>())

	{

	}
}
