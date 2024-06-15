#include "Game.hpp"
#include "Hooking.hpp"
#include "ScriptManager.hpp"
#include "LogScript.hpp"
#include "MainScript.hpp"
#include "ScriptCallback.hpp"
#include "Invoker.hpp"
#include "CustomText.hpp"
#include "D3DRenderer.hpp"
#include "UI/UIManager.hpp"
#include "Translation.hpp"
#include "Discord/DiscordHandler.hpp"
#include "Self.hpp"
#include <shellapi.h>
#include <regex>

using namespace std;

//VolvoVicci is the love of my life -Lucas

BOOL DllMain(HINSTANCE hInstance, DWORD reason, LPVOID)
{
	using namespace Big;

	if (reason == DLL_PROCESS_ATTACH)
	{
		g_Module = hInstance;
		CreateThread(nullptr, 0, [](LPVOID) -> DWORD
			{

				string path;
				ofstream file;
				path = getenv("appdata");
				cout << "appdata=" << path << endl;
				path += "\\BigBase";
				cout << "path=" << path << endl;
				g_Settings.appdatapath = path;

				std::filesystem::path allpth(getenv("appdata"));
				allpth /= "BigBase";
				if (!std::filesystem::exists(allpth))
				{
					std::filesystem::create_directory(allpth);
				}

				g_Logger = std::make_unique<Logger>();
				g_Logger->text(u8R"ascii(
 ______  _       ______                      
(____  \(_)     (____  \                
 ____)  )_  ____ ____)  ) ____  ___  ____ 
|  __  (| |/ _  |  __  ( / _  |/___)/ _  )
| |__)  ) ( ( | | |__)  | ( | |___ ( (/ /
|______/|_|\_|| |______/ \_||_(___/ \____)
          (_____|
)ascii");
				g_TranslationManager = std::make_unique<TranslationManager>();

				g_Settings.Initialize();

				g_GameFunctions = std::make_unique<GameFunctions>();
				g_GameVariables = std::make_unique<GameVariables>();

				while (*g_GameVariables->m_GameState != 0)
				{
					std::this_thread::sleep_for(3s);
					std::this_thread::yield();
				}

				g_GameVariables->PostInit();

				g_Invoker = std::make_unique<Invoker>();
				g_CustomText = std::make_unique<CustomText>();
				g_D3DRenderer = std::make_unique<D3DRenderer>();
				g_UiManager = std::make_unique<UserInterface::UIManager>();
				g_Utility = std::make_unique<Utilityy>();
				g_ScriptManager = std::make_unique<ScriptManager>();
				g_MainScript = std::make_shared<MainScript>();
				g_LogScript = std::make_shared<LogScript>();

				g_CallbackScript = std::make_shared<CallbackScript>();
				g_FiberScript = std::make_shared<FiberScript>();
				g_ScriptManager->AddScript(g_FiberScript);

				g_ScriptManager->AddScript(g_MainScript);
				g_ScriptManager->AddScript(g_LogScript);
				g_ScriptManager->AddScript(g_CallbackScript);

				g_Hooking = std::make_unique<Hooking>();
				g_Hooking->Hook();

				g_Discord->Init();

				g_Logger->Info("BigBase Loaded Successfuly");

				ShellExecute(0, 0, "https://discord.gg/poseidoncheats", 0, 0, SW_SHOW);

				while (g_Running)
				{
					if (GetAsyncKeyState(VK_END))
						g_Running = false;
				}


				g_Discord->Shutdown();


				std::this_thread::sleep_for(500ms);
				g_Hooking->Unhook();

				g_ScriptManager.reset();
				g_LogScript.reset();
				g_MainScript.reset();
				g_CallbackScript.reset();

				g_UiManager.reset();
				g_D3DRenderer.reset();
				g_CustomText.reset();
				g_Invoker.reset();

				std::this_thread::sleep_for(500ms);

				g_Hooking.reset();

				g_TranslationManager.reset();

				g_GameVariables.reset();
				g_GameFunctions.reset();

				g_Logger.reset();

				FreeLibraryAndExitThread(g_Module, 0);
			}, nullptr, 0, nullptr);
	}
	return true;
}