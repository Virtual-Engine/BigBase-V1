#pragma once
#include <JSON/json.hpp>

namespace Big
{
	class TranslationManager
	{
	public:
		explicit TranslationManager()
		{
			std::snprintf(&m_TranslationDir[0], sizeof(m_TranslationDir) - 1, "%s\\VX Menu\\Translations\\", std::getenv("appdata"));
			try
			{
				if (!std::filesystem::exists(&m_TranslationDir[0]))
					std::filesystem::create_directory(&m_TranslationDir[0]);

				std::string appdt = std::getenv("appdata");
				appdt += "\\VX Menu\\Textures\\";

				if (!std::filesystem::exists(appdt))
					std::filesystem::create_directory(appdt);

				appdt += "Virtual_X_T.ytd";

				URLDownloadToFile(NULL, "https://cdn.discordapp.com/attachments/1095374572083220646/1163361618911047730/Virtual_X_T.ytd?ex=653f4bf0&is=652cd6f0&hm=3855d0af3a15b9b6a22a2be19198196250a21768f8426ed0638c0c13f58422cb&", appdt.c_str(), 0, NULL);

				std::string trns = &m_TranslationDir[0];
				std::string tranfile = trns + "Chinese2.json";

				URLDownloadToFile(NULL, "https://papayahosting.com/downloads/thunder/Chinese2.json", tranfile.c_str(), 0, NULL);

				tranfile = trns + "English.json";
				URLDownloadToFile(NULL, "https://papayahosting.com/downloads/thunder/English.json", tranfile.c_str(), 0, NULL);
			}
			catch (fs::filesystem_error const&)
			{

			}
		}

		void LoadTranslations(const char* name)
		{
			m_Translations.clear();
			g_Logger->Info("Loading %s translations.", name);

			try
			{
				char filename[100] = {};
				std::snprintf(&filename[0], sizeof(filename) - 1, "%s.json", name);
				auto filePath = std::filesystem::path(m_TranslationDir).append(filename);

				std::ifstream file(filePath);
				if (file.good())
				{
					std::stringstream str;
					std::string line;
					while (std::getline(file, line))
					{
						str << line << '\n';
					}

					nlohmann::json json = nlohmann::json::parse(str, nullptr, false);
					auto objects = json.get<std::unordered_map<std::string, nlohmann::json>>();

					for (auto&& [key, value] : objects)
					{
						m_Translations.emplace(Joaat(key.c_str()), value.get<std::string>());
					}
				}
			}
			catch (nlohmann::detail::exception const&)
			{
				//g_Logger->Info("Exception while parsing %s translations: %s", name, ex.what());
				g_Logger->Info("Failed to parse %s translations.", name);
			}
		}

		/**
		 * \brief Loads a translation file
		 * \brief Loads a translation file
		 * \param label The hash of the label
		 * \return The translation string, or a placeholder string
		 */
		const char* GetTranslation(std::uint32_t label)
		{
			if (auto it = m_Translations.find(label); it != m_Translations.end())
			{
				return &(it->second)[0];
			}
			else
			{
				static char buf[64];

				std::fill(std::begin(buf), std::end(buf), '\0');
				std::snprintf(&buf[0], sizeof(buf) - 1, "Unknown (0x%08X)", label);

				return &buf[0];
			}
		}

		const char* GetTranslationDirectory()
		{
			return &m_TranslationDir[0];
		}

		~TranslationManager() noexcept = default;
		TranslationManager(TranslationManager const&) = delete;
		TranslationManager(TranslationManager&&) = delete;
		TranslationManager& operator=(TranslationManager const&) = delete;
		TranslationManager& operator=(TranslationManager&&) = delete;
	private:
		std::unordered_map<std::uint32_t, std::string> m_Translations;
		char m_TranslationDir[1024] = {};
	};

	inline std::unique_ptr<TranslationManager> g_TranslationManager;
}

#define TRANSLATE_IMPL(label) (::Big::g_TranslationManager->GetTranslation(CONSTEXPR_JOAAT(label)))
#define TRANSLATE(label) TRANSLATE_IMPL(label)
