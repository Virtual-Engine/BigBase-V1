#include "Hooking.hpp"
#include "Game.hpp"
#include "ScriptManager.hpp"
#include "CustomText.hpp"
#include "Util.hpp"
#include "D3DRenderer.hpp"
#include "UI/UIManager.hpp"
#include <MinHook/MinHook.h>
#include "ScriptCallback.hpp"
#include "MainScript.hpp"
#include <chrono>
#include "Lists.hpp"
#include "ImGui/imgui.h"

#ifdef BIGBASE_DEBUG
#  pragma comment(lib, "MinHook-Debug.lib")
#else
#  pragma comment(lib, "MinHook-Release.lib")
#endif

namespace Big
{
	namespace
	{
		std::uint32_t g_HookFrameCount{};
	}

	bool Hooks::IsDlcPresent(std::uint32_t hash)
	{
		if (g_Running && g_HookFrameCount != (ImGui::GetIO().Framerate / 2))
		{
			g_HookFrameCount = ImGui::GetIO().Framerate / 2;
			g_ScriptManager->OnGameTick();
		}
		return static_cast<decltype(&IsDlcPresent)>(g_Hooking->m_OriginalIsDlcPresent)(hash);
	}

	const char* Hooks::GetLabelText(void* unk, const char* label)
	{
		if (g_Running)
			if (auto text = g_CustomText->GetText(Joaat(label)))
				return text;

		return static_cast<decltype(&GetLabelText)>(g_Hooking->m_OriginalGetLabelText)(unk, label);
	}

	void Hooks::TransactionErrorHandler(char* entryHeader, char* entryLine1, int instructionalKey, char* entryLine2, BOOL p4, Any p5, Any* p6, Any* p7, BOOL background)
	{
		return static_cast<decltype(&TransactionErrorHandler)>(g_Hooking->m_OriginalDisableTransactionError)(entryHeader, entryLine1, instructionalKey, entryLine2, p4, p5, p6, p7, background);
	}

	bool Hooks::GetEventData(std::int32_t eventGroup, std::int32_t eventIndex, std::int64_t* args, std::uint32_t argCount)
	{
		auto result = static_cast<decltype(&GetEventData)>(g_Hooking->m_OriginalGetEventData)(eventGroup, eventIndex, args, argCount);
		return result;
	}

	void Hooks::SendCloneSync(uint64_t a1, __int64 net_game_player, uint64_t net_obj, uint64_t a4, uint64_t a5, bool a6)
	{
		BYTE player = *reinterpret_cast<BYTE*>(net_game_player + 0x21);
		return static_cast<decltype(&SendCloneSync)>(g_Hooking->m_OriginalSendCloneSync)(a1, net_game_player, net_obj, a4, a5, a6);
	}

	bool Hooks::WriteSyncDataString(void* sync_data, const char* input, std::size_t length)
	{
		static bool bomuld{ true };

		if (bomuld)
		{
			std::string string_to_spoof = "Bomuld On Top";
			for (std::int32_t i = 0; i < 32; i++)
			{
				const char* raw_name = PLAYER::GET_PLAYER_NAME(i);
				if (raw_name != nullptr)
				{
					if (!strcmp(input, raw_name))
					{
						return  static_cast<decltype(&WriteSyncDataString)>(g_Hooking->m_OriginalSendCloneSync)(sync_data, string_to_spoof.c_str(), string_to_spoof.size() + 1);
					}
				}
			}
		}
		g_Logger->Info("Running");

		return static_cast<decltype(&WriteSyncDataString)>(g_Hooking->m_OriginalSendCloneSync)(sync_data, "Bomuld On Top", length);
	}

	bool Hooks::CanApplyToObject(netSyncTree* sync_tree, netObject* net_obj)
	{
		auto const root = *(void**)((uint8_t*)sync_tree + 0x10);
		auto const vehicle_creation_data = (void*)((uint8_t*)root + 0x11B8);
		auto model_hash = *(uint32_t*)((uint8_t*)vehicle_creation_data + 0xC8);
		auto model_info = g_GameFunctions->m_ModelInfo(model_hash, nullptr);
		std::int32_t model_type = (*(std::uint8_t*)(model_info + 0x9D) & 0x1F);
		std::uint8_t objOwner = *reinterpret_cast<std::uint8_t*>(net_obj + 0x49);
		std::int32_t vehicle_type = *(std::uint8_t*)(model_info + 0x340);
		return static_cast<decltype(&CanApplyToObject)>(g_Hooking->m_OriginalCanApplyToObject)(sync_tree, net_obj);
	}

	__int64* Hooks::game_invite(__int64* a1, __int64* a2, __int64 a3)
	{
		
		return static_cast<decltype(&game_invite)>(g_Hooking->m_OriginalGameInvite)(a1, a2, a3);
	}

	int Hooks::IncrementStatEvent(__int64 neteventclass, CNetGamePlayers* Source)
	{
		const auto StatHash = *reinterpret_cast<DWORD*>(neteventclass + 0x30);
		BYTE* IP = reinterpret_cast<BYTE*>(&Source->PlayerInfo->m_external_ip);
		return static_cast<decltype(&IncrementStatEvent)>(g_Hooking->m_OriginalIncrementStatEvent)(neteventclass, Source);
	}

	void Hooks::NetworkEventHandler(__int64 a1, CNetGamePlayers* a2, CNetGamePlayers* a3, unsigned __int16 a4, int a5, int a6, __int64 a7, __int64 a8)
	{
		auto ptr = Memory::pattern("66 83 FA ? 73 13 0F B7 C2 4C 89 84 C1 ? ? ? ? 4C 89 8C C1").count(1).get(0).get<char>(0);
		auto num_events = *(std::uint8_t*)(ptr + 3);
		auto name_offset = *(std::int32_t*)(ptr + 21);
		auto eventName = reinterpret_cast<char*>(*reinterpret_cast<__int64*>(a1 + 8 * a4 + name_offset));

		return static_cast<decltype(&NetworkEventHandler)>(g_Hooking->m_OriginalNetworkHandler)(a1, a2, a3, a4, a5, a6, a7, a8);
	}

	void Hooks::pls(__int64 a1, __int64 a2, __int64 PlayerMaybe, __int64 a4, char a5)
	{
		
	}

	LRESULT Hooks::WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		g_D3DRenderer->WndProc(hWnd, msg, wParam, lParam);
		return static_cast<decltype(&WndProc)>(g_Hooking->m_OriginalWndProc)(hWnd, msg, wParam, lParam);
	}

	HRESULT Hooks::Present(IDXGISwapChain* dis, UINT syncInterval, UINT flags)
	{
		if (g_Running)
		{
			g_D3DRenderer->BeginFrame();
			g_ScriptManager->OnD3DTick();
			g_D3DRenderer->EndFrame();
		}
		return g_Hooking->m_D3DHook.GetOriginal<decltype(&Present)>(PresentIndex)(dis, syncInterval, flags);
	}

	HRESULT Hooks::ResizeBuffers(IDXGISwapChain* dis, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags)
	{
		if (g_Running)
		{
			g_D3DRenderer->PreResize();
			auto hr = g_Hooking->m_D3DHook.GetOriginal<decltype(&ResizeBuffers)>(ResizeBuffersIndex)(dis, bufferCount, width, height, newFormat, swapChainFlags);
			if (SUCCEEDED(hr))
			{
				g_D3DRenderer->PostResize();
			}
			return hr;
		}
		return g_Hooking->m_D3DHook.GetOriginal<decltype(&ResizeBuffers)>(ResizeBuffersIndex)(dis, bufferCount, width, height, newFormat, swapChainFlags);
	}

	__int64* Hooks::PlayerWildCardHandler(std::int32_t friendIndex)
	{
		auto original = static_cast<decltype(&PlayerWildCardHandler)>(g_Hooking->m_OriginalRIDFunction)(friendIndex);
		if (m_EnableSCIDJoiner)
		{
			*original = m_SCIDJoiner;
			return original;
		}
		return static_cast<decltype(&PlayerWildCardHandler)>(g_Hooking->m_OriginalRIDFunction)(friendIndex);
	}

	__int64 Hooks::CPlayerListMenuConstructor(__int64 a1, __int64 a2, __int64 a3)
	{
		auto result = static_cast<decltype(&CPlayerListMenuConstructor)>(g_Hooking->m_OriginalJoinSessionHook)(a1, a2, a3);
		m_PlayerListPointer = result;
		return result;
	}

	bool Hooks::ScriptedGameEvent(void* events, CNetGamePlayers* SourcePlayer, CNetGamePlayers* ReceivingPlayer)
	{
		auto args = (std::int64_t*)(((std::uintptr_t)events) + 0x70);
		auto argCount = *(std::uint32_t*)(((std::uintptr_t)events) + 0x224) / sizeof(std::int64_t);
		static bool log{ true };
		
		return static_cast<decltype(&ScriptedGameEvent)>(g_Hooking->m_OriginalScriptedGameEvent)(events, SourcePlayer, ReceivingPlayer);
	}

	__int64 Hooks::GetModelInfo(__int64 a1, DWORD* a2)
	{
		return static_cast<decltype(&GetModelInfo)>(g_Hooking->m_OriginalGetModelInfo)(a1, a2);
	}

	void Hooks::BlockInvalidObjects()
	{
		
	}

	int Hooks::ChatBypassHook(__int64 ChatType, const char* Input, const char** Output)
	{
		return static_cast<decltype(&ChatBypassHook)>(g_Hooking->m_OriginalBypassChat)(ChatType, Input, Output);
	}

	void Hooks::ChatMessage(void* thisptr, __int64  unk1, __int64  unk2, const char* message)
	{
		return static_cast<decltype(&ChatMessage)>(g_Hooking->m_OriginalChatMessage)(thisptr, unk1, unk2, message);
	}

	bool Hooks::ProcessNetObject(std::uint64_t sync_tree, std::uint64_t net_obj)
	{
		
		
		return static_cast<decltype(&ProcessNetObject)>(g_Hooking->m_OriginalProcessNetObject)(sync_tree, net_obj);
	}

	bool Hooks::SendNetInfo(netPlayerData* player, __int64 a2, __int64 a3, DWORD* a4)
	{
		if (scidstuff)
		{
			player->m_rockstar_id = 12345678;
		}

		if (ipstuff)
		{
			player->m_online_ip.m_field1 = 1;
			player->m_online_ip.m_field2 = 3;
			player->m_online_ip.m_field3 = 3;
			player->m_online_ip.m_field4 = 7;
		}

		return static_cast<decltype(&SendNetInfo)>(g_Hooking->m_OriginalSendNetInfo)(player, a2, a3, a4);
	}

	bool Hooks::PickupRewardMoneyIsApplicableToPlayer(void* thisptr, void* unk, void* ped)
	{
		return false;
	}

	Hooking::Hooking() :
		m_D3DHook(g_GameVariables->m_Swapchain, 18),
		m_ObjectBypass(Signature("50", "74 48 E8 ? ? ? ? 48 8B 48 48").Scan().Add(3).Rip().Add(30).As<char*>())
	{

		std::copy_n(m_ObjectBypass, 2, m_OriginalObjectBypass);

		g_Logger->Pattern("Succesfuly pattern scan");
		//g_Logger->Hooking("started hooking");
		MH_Initialize();
		MH_CreateHook(g_GameFunctions->m_IsDlcPresent, &Hooks::IsDlcPresent, &m_OriginalIsDlcPresent);
		MH_CreateHook(g_GameFunctions->m_GetLabelText, &Hooks::GetLabelText, &m_OriginalGetLabelText);
		MH_CreateHook(g_GameFunctions->m_GetEventData, &Hooks::GetEventData, &m_OriginalGetEventData);
		MH_CreateHook(g_GameFunctions->m_WndProc, &Hooks::WndProc, &m_OriginalWndProc); 		MH_Initialize();
		//MH_CreateHook(g_GameFunctions->m_AssignPhysicalIndexHandler, &Hooks::AssignNewPhysicalIndexHandler, &m_OriginalAssignPhysicalIndex);
		MH_CreateHook(g_GameFunctions->m_PlayerListMenuConstructor, &Hooks::CPlayerListMenuConstructor, &m_OriginalJoinSessionHook);
		MH_CreateHook(g_GameFunctions->m_PlayerWildcard, &Hooks::PlayerWildCardHandler, &m_OriginalRIDFunction);
		MH_CreateHook(g_GameFunctions->m_NetworkEvents, &Hooks::NetworkEventHandler, &m_OriginalNetworkHandler);
		MH_CreateHook(g_GameFunctions->m_TransactionError, &Hooks::TransactionErrorHandler, &m_OriginalDisableTransactionError);
		MH_CreateHook(g_GameFunctions->m_ModelInfo, &Hooks::GetModelInfo, &m_OriginalGetModelInfo);
		//MH_CreateHook(g_GameFunctions->m_BypassChat, &Hooks::ChatBypassHook, &m_OriginalBypassChat); 		
		MH_CreateHook(g_GameFunctions->m_PickupRewardMoneyIsApplicableToPlayer, &Hooks::PickupRewardMoneyIsApplicableToPlayer, &m_OriginalPickupRewardMoneyIsApplicableToPlayer);
		//MH_CreateHook(g_GameFunctions->m_ChatMessage, &Hooks::ChatMessage, &m_OriginalChatMessage); 	
		//MH_CreateHook(g_GameFunctions->m_SendNetInfo, &Hooks::SendNetInfo, &m_OriginalSendNetInfo);
		MH_CreateHook(g_GameFunctions->m_ProcessNetObject, &Hooks::ProcessNetObject, &m_OriginalProcessNetObject);
		MH_CreateHook(g_GameFunctions->m_CanApplyToObject, &Hooks::CanApplyToObject, &m_OriginalCanApplyToObject);
		MH_CreateHook(g_GameFunctions->m_presence_game_invite, &Hooks::game_invite, &m_OriginalGameInvite);
		//	MH_CreateHook(g_GameFunctions->m_WriteSyncDataString, &Hooks::WriteSyncDataString, &m_OriginalWriteSyncDataString);
		//	MH_CreateHook(g_GameFunctions->m_SendCloneSync, &Hooks::SendCloneSync, &m_OriginalSendCloneSync);
			//MH_CreateHook(g_GameFunctions->m_ScriptedGameEvent, &Hooks::ScriptedGameEvent, &m_OriginalScriptedGameEvent); wouldn't recommend future me using this
		m_D3DHook.Hook(&Hooks::Present, Hooks::PresentIndex);
		m_D3DHook.Hook(&Hooks::ResizeBuffers, Hooks::ResizeBuffersIndex);
	}

	Hooking::~Hooking() noexcept
	{
		MH_RemoveHook(g_GameFunctions->m_WndProc);
		MH_RemoveHook(g_GameFunctions->m_GetEventData);
		MH_RemoveHook(g_GameFunctions->m_GetLabelText);
		MH_RemoveHook(g_GameFunctions->m_IsDlcPresent);
		MH_RemoveHook(g_GameFunctions->m_AssignPhysicalIndexHandler);
		MH_RemoveHook(g_GameFunctions->m_PlayerListMenuConstructor);
		MH_RemoveHook(g_GameFunctions->m_PlayerWildcard);
		MH_RemoveHook(g_GameFunctions->m_NetworkEvents);
		MH_RemoveHook(g_GameFunctions->m_TransactionError);
		MH_RemoveHook(g_GameFunctions->m_ModelInfo);
		MH_RemoveHook(g_GameFunctions->m_BypassChat);
		MH_RemoveHook(g_GameFunctions->m_ChatMessage);
		MH_RemoveHook(g_GameFunctions->m_SendNetInfo);
		MH_RemoveHook(g_GameFunctions->m_PickupRewardMoneyIsApplicableToPlayer);
		MH_RemoveHook(g_GameFunctions->m_ProcessNetObject);
		MH_RemoveHook(g_GameFunctions->m_CanApplyToObject);
		MH_RemoveHook(g_GameFunctions->m_presence_game_invite);
		//MH_RemoveHook(g_GameFunctions->m_WriteSyncDataString);
		//MH_RemoveHook(g_GameFunctions->m_SendCloneSync);
		//MH_RemoveHook(g_GameFunctions->m_ScriptedGameEvent);
		MH_Uninitialize();
	}

	void Hooking::Hook()
	{
		std::fill_n(m_ObjectBypass, 2, '\x90');
		m_D3DHook.Enable();

		MH_EnableHook(MH_ALL_HOOKS);
	}

	void Hooking::Unhook()
	{
		std::copy_n(m_OriginalObjectBypass, 2, m_ObjectBypass);
		m_D3DHook.Disable();
		g_GameFunctions->small_host_token_patch = false;
		MH_DisableHook(MH_ALL_HOOKS);
	}
}
