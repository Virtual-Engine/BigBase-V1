#include "MainScript.hpp"
#include "ScriptCallback.hpp"
#include "Lists.hpp"
#include "Natives.hpp"
#include "Timer.hpp"
#include "Translation.hpp"
#include "CustomText.hpp"
#include "UI/UIManager.hpp"
#include "UI/BoolOption.hpp"
#include "UI/ChooseOption.hpp"
#include "UI/NumberOption.hpp"
#include "UI/RegularOption.hpp"
#include "UI/SubOption.hpp"
#include "UI/RegularSubmenu.hpp"
#include "UI/PlayerSubmenu.hpp"
#include "breakoption.hpp"
#include "Discord/DiscordHandler.hpp"
#include "obfuscator.h"
#include "meta_random.h"
#include "ImGui/imgui.h"
#include "ImGui/imconfig.h"
#include "ImGui/imgui_impl_win32.h"
//#include "Auth.h"

//#include <cpr/cpr.h>

void ScriptEventLog()
{
	HUD::_SET_NOTIFICATION_TEXT_ENTRY("STRING");
	HUD::_SET_NOTIFICATION_TEXT_ENTRY((char*)"STRING");
	HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME("Open Key ~b~[F5] VX Team wishes you good modding");
	HUD::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("Virtual_X_T", (char*)"notify", true, 5, (char*)"~p~Virtual X", (char*)"", 1.f, (char*)"", 5, 0);
	HUD::_DRAW_NOTIFICATION(false, false);
}
using namespace Big::Lists;
using namespace UserInterface;
namespace Big
{

	bool MainScript::IsInitialized()
	{
		return m_Initialized;
	}

	ScriptType MainScript::GetType()
	{
		return ScriptType::Game;
	}

	void MainScript::Initialize()
	{
		//Auth(); 

		if (true)
		{
			ScriptEventLog();
			m_Initialized = true;
			g_CustomText->AddText(CONSTEXPR_JOAAT("HUD_JOINING"), "Loading GTA Online with " BIGBASE_NAME "...");
			g_CustomText->AddText(CONSTEXPR_JOAAT("HUD_QUITTING"), "Leaving with " BIGBASE_NAME "...");

			g_UiManager->AddSubmenu<RegularSubmenu>(("Home"), Submenu::SubmenuHome, [](RegularSubmenu* sub)
				{
					sub->AddOption<SubOption>("Self", "Personal option", Submenu::SubmenuPlayer);
					sub->AddOption<SubOption>("Players", "Player in your session", Submenu::SubmenuPlayers);
					sub->AddOption<SubOption>("Network", "Network functionality", Submenu::SubmenuNetwork);
					sub->AddOption<SubOption>("Vehicle", "Setting up your vehicles", Submenu::SubmenuVehicle);
					sub->AddOption<SubOption>("Weapon", "Modify or donate weapons", Submenu::SubmenuWeapon);
					sub->AddOption<SubOption>("Recovery", "Money, rp and casino ...", Submenu::SubmenuRecovery);
					sub->AddOption<SubOption>("Teleports", "Teleport where you want", Submenu::SubmenuTeleports);
					sub->AddOption<SubOption>("Protection", "Protect yourself against modders ", Submenu::SubmenuProtection);
					sub->AddOption<SubOption>("World", "Changing the world of GTA V", Submenu::SubmenuWorld);
					sub->AddOption<SubOption>("Settings", "Edit and customize your menu", Submenu::SubmenuSettings);

				});

			g_UiManager->AddSubmenu<RegularSubmenu>(("Option"), Submenu::SubmenuHome, [](RegularSubmenu* sub)
				{
					
				});
		}
	}

	void MainScript::Destroy()
	{
		g_UiManager.reset();
	}

	void MainScript::Tick()
	{
		g_UiManager->OnTick();
		g_Discord->Tick();
	}
}