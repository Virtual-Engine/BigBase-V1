#pragma once
#include "UI/UIManager.hpp"

namespace Big::Lists
{
	void ScriptImGuiMain();

	inline std::size_t walk2_id = 0;

	inline const char* HeaderTypesFrontend[]
	{
		"Virtual X",
		"VX",
		"VX Theme"
	};
	inline int ALL_WEAPON_HASHES[] =
	{
		0x92A27487, 0x958A4A8F,
		0xF9E6AA4B, 0x84BD7BFD,
		0xA2719263, 0x8BB05FD7,
		0x440E4788, 0x4E875F73,
		0xF9DCBF2D, 0xD8DF3C3C,
		0x99B507EA, 0xDD5DF8D9,
		0xDFE37640, 0xDFE37640,
		0x19044EE0, 0xCD274149,
		0x94117305, 0x3813FC08,

		0x1B06D571, 0xBFE256D4,
		0x5EF9FEC4, 0x22D8FE39,
		0x3656C8C1, 0x99AEEB3B,
		0xBFD21232, 0x88374054,
		0xD205520E, 0x83839C4,
		0x47757124, 0xDC4DB296,
		0xC1B3C3D1, 0xCB96392F,
		0x97EA20B8, 0xAF3696A1,
		0x2B5EF5EC, 0x917F6C8C,
		0x57A4368C, 0x45CD9CF3,

		0x13532244, 0x2BE6766B,
		0x78A97CD0, 0xEFE7E2DF,
		0x0A3D4D34, 0xDB1AA450,
		0xBD248B55, 0x476BF155,

		0x1D073A89, 0x555AF99A,
		0x7846A318, 0xE284C527,
		0x9D61E50F, 0xA89CB99E,
		0x3AABBBAA, 0xEF951FBB,
		0x12E82D3D, 0x5A96BA4,

		0xBFEFFF6D, 0x394F415C,
		0x83BF0278, 0xFAD1F1C9,
		0xAF113F99, 0xC0A3098D,
		0x969C3D67, 0x7F229F94,
		0x84D6FAFD, 0x624FE830,
		0x9D1F17E6, 0xC78D71B4,
		0xD1D5F52B,

		0x9D07F764, 0x7FD62962,
		0xDBBD7280, 0x61012683,

		0x05FC3C11, 0x0C472FE2,
		0xA914799, 0xC734385A,
		0x6A6C02E0, 0x6E7DDDEC,

		0xB1CA77B1, 0xA284510B,
		0x4DD2DC56, 0x42BF8A85,
		0x7F7497E5, 0x6D544C99,
		0x63AB0442, 0x0781FE4A,
		0xB62D1F67, 0xDB26713A,

		0x93E220BD, 0xA0973D5E,
		0x24B17070, 0x2C3731D9,
		0xAB564B93, 0x787F0BB,
		0xBA45E8B8, 0x23C9F95C,
		0xFDBC8A50, 0x497FACC3,

		0x34A67B97, 0xFBAB5776,
		0x060EC506, 0xBA536372,
		0x184140A1
	};
	inline UserInterface::HeaderType HeaderTypesBackend[]
	{
		UserInterface::HeaderType::Static
	};

	inline std::size_t HeaderTypesPosition = 0;

	inline const char* IntegratedGUI[2]{ "Native And Texture", "Full Texture" };
	inline std::size_t HeaderTypesIndex = 0;

	inline const char* DemoList[10]
	{
		"One",
		"Two",
		"Three",
		"Four",
		"Five",
		"Six",
		"Seven",
		"Eight",
		"Nine",
		"Ten"
	};

	class CVehicleList
	{
	public:

		inline static std::size_t VehicleListPos = 0;
		constexpr static inline std::array<const char*, 24> VehicleLists{ "Super", "Sports", "Sports Classic", "Sedans", "Motorcycles", "Cycles", "Helicopters", "Planes", "Boats", "Military", "Emergency", "Commercials", "Muscle", "OffRoad", "SUVs", "Open Wheel", "Trailer", "Trains", "Service", "Utlity", "Vans", "Industrial", "Coupes", "Compacts" };

		constexpr static inline std::array<const char*, 52> Super = { "adder", "autarch", "banshee2", "bullet", "champion", "cheetah", "cyclone", "deveste", "entity2", "entityxf", "emerus", "fmj", "furia", "gp1", "ignus", "infernus", "italigtb", "italigtb2", "krieger", "le7b", "nero", "nero2", "osiris", "penetrator", "pfister811", "prototipo", "prototipo", "reaper", "s80", "sc1", "scramjet", "sheava", "sultanrs", "t20", "taipan", "tempesta", "tezeract", "thrax", "tigon", "turismor", "tyrant", "tyrus", "vacca", "vagner", "vigilante", "visione", "voltic", "voltic2", "xa21", "zeno", "zentorno", "zorrusso" };
		constexpr static inline std::array<const char*, 95> Sports = { "alpha", "banshee", "bestiagts", "blista2", "blista3", "buffalo", "buffalo2", "buffalo3", "calico", "carbonizzare", "comet2", "comet3", "comet4", "comet5", "comet7", "coquette", "coquette4", "cypher", "drafter", "deveste", "euros", "elegy", "elegy2", "feltzer2", "flashgt", "furoregt", "fusilade", "futo", "futo2", "gb200", "growler", "hotring", "komoda", "imorgon", "issi7", "italigto", "jugular", "jester", "jester2", "jester3", "jester4", "khamelion", "kuruma", "kuruma2", "locust", "lynx", "massacro", "massacro2", "neo", "neon", "ninef", "ninef2", "omnis", "paragon", "paragon2", "pariah", "penumbra", "penumbra2", "raiden", "rapidgt", "rapidgt2", "raptor", "remus", "revolter", "rt3000", "ruston", "schafter2", "schafter3", "schafter4", "schafter5", "schafter6", "schlagen", "schwarzer", "sentinel3", "seven70", "specter", "specter2", "streiter", "sugoi", "sultan", "sultan2", "sultan3", "surano", "tampa2", "tropos", "vectre", "verlierer2", "vstr", "zr380", "zr3802", "zr3803", "italirsx", "veto", "veto2", "vstr" };
		constexpr static inline std::array<const char*, 46> SportsClassic = { "ardent", "btype", "btype2", "btype3", "casco", "cheetah2", "coquette2", "deluxo", "dynasty", "fagaloa", "feltzer3", "gt500", "infernus2", "jb700", "jb7002", "mamba", "manana", "manana2", "michelli", "monroe", "nebula", "peyote", "peyote3", "pigalle", "rapidgt3", "retinue", "retinue2", "savestra", "stinger", "stingergt", "stromberg", "swinger", "torero", "tornado", "tornado2", "tornado3", "tornado4" ,"tornado5", "tornado6", "turismo2", "viseris", "z190", "ztype", "zion3","cheburek", "toreador" };
		constexpr static inline std::array<const char*, 34> Sedans = { "asea", "asea2", "asterope", "cinquemila", "cog55", "cog552", "cognoscenti", "cognoscenti2", "deity", "emperor", "emperor2", "emperor3", "fugitive", "glendale", "glendale2", "ingot", "intruder", "limo2", "premier", "primo", "primo2", "regina", "romero", "stafford", "stanier", "stratum", "stretch", "superd", "surge", "tailgater", "tailgater2", "warrener", "warrener2", "washington" };
		constexpr static inline std::array<const char*, 54> Motorcycles = { "akuma", "avarus", "bagger", "bati", "bati2", "bf400", "carbonrs", "chimera", "cliffhanger", "daemon", "daemon2", "defiler", "deathbike", "deathbike2", "deathbike3", "diablous", "diablous2", "double", "enduro", "esskey", "faggio", "faggio2", "faggio3", "fcr", "fcr2", "gargoyle", "hakuchou", "hakuchou2", "hexer", "innovation", "lectro", "manchez", "nemesis", "nightblade", "oppressor", "oppressor2", "pcj", "ratbike", "ruffian", "rrocket", "sanchez", "sanchez2", "sanctus", "shotaro", "sovereign", "stryder", "thrust", "vader", "vindicator", "vortex", "wolfsbane", "zombiea", "zombieb", "manchez2" };
		constexpr static inline std::array<const char*, 7>  Cycles = { "bmx", "cruiser", "fixter", "scorcher", "tribike", "tribike2", "tribike3" };
		constexpr static inline std::array<const char*, 1> Helicopters = { "annihilator" };
		constexpr static inline std::array<const char*, 1> Planes = { "besra" };
		constexpr static inline std::array<const char*, 1> Boats = { "jetmax" };
		/*constexpr static inline std::array<const char*, 26> Helicopters = {"akula", "annihilator", "buzzard", "buzzard2", "cargobob", "cargobob2", "cargobob3", "cargobob4", "frogger", "frogger2", "havok", "hunter", "maverick", "savage", "seasparrow", "skylift", "supervolito", "supervolito2", "swift", "swift2", "valkyrie", "valkyrie2", "volatus", "annihilator2", "seasparrow2", "seasparrow3"};
		constexpr static inline std::array<const char*, 39> Planes = { "alphaz1", "avenger", "avenger2", "besra", "blimp", "blimp2", "blimp3", "bombushka",	"cargoplane", "cuban800", "dodo", "duster", "howard", "hydra", "jet", "lazer","luxor", "luxor2", "mammatus", "microlight", "miljet", "mogul", "molotok", "nimbus", "nokota", "pyro", "rogue", "seabreeze", "shamal", "starling", "strikeforce", "stunt", "titan", "tula", "velum", "velum2", "vestra", "volatol", "alkonost" };
		constexpr static inline std::array<const char*, 23> Boats = { "avisa", "dinghy", "jetmax", "marquis", "seashark", "seashark2", "seashark3", "speeder", "speeder2", "squalo", "submersible", "submersible2", "suntrap", "toro", "toro2", "tropic", "tropic2", "tug", "avisa", "dinghy5", "kosatka", "longfin", "patrolboat" };*/
		constexpr static inline std::array<const char*, 17> Military = { "apc", "barracks", "barracks2", "barracks3", "barrage", "chernobog", "crusader", "halftrack", "khanjali", "minitank", "rhino", "scarab", "scarab2", "scarab3", "thruster", "trailersmall2", "vetir" };
		constexpr static inline std::array<const char*, 21> Emergency = { "ambulance", "fbi", "fbi2", "firetruck", "lguard", "pbus", "police", "police2", "police3", "police4", "policeb", "polmav", "policeold1", "policeold2", "policet", "pranger", "predator", "riot", "riot2", "sheriff", "sheriff2" };
		constexpr static inline std::array<const char*, 20> Commercials = { "benson", "biff", "cerberus", "cerberus2", "cerberus3", "hauler", "hauler2", "mule", "mule2", "mule3", "mule4", "packer", "phantom", "phantom2", "phantom3", "pounder", "pounder2", "stockade", "stockade3", "terbyte" };
		constexpr static inline std::array<const char*, 71> Muscle = { "blade", "buccaneer", "buccaneer2", "chino", "chino2", "clique", "coquette3", "deviant", "dominator", "dominator2", "dominator3", "dominator4", "dominator5", "dominator6", "dukes", "dukes2", "dukes3", "faction", "faction2", "faction3", "ellie", "gauntlet","gauntlet2", "gauntlet3", "gauntlet4", "gauntlet5", "hermes", "hotknife", "hustler", "impaler", "impaler2", "impaler3","impaler4", "imperator", "imperator2", "imperator3", "lurcher", "moonbeam", "moonbeam2", "nightshade", "peyote2", "phoenix", "picador", "ratloader", "ratloader2", "ruiner", "ruiner2", "ruiner3", "sabregt", "sabregt2", "slamvan", "slamvan2", "slamvan3", "slamvan4", "slamvan5", "slamvan6", "stalion", "stalion2", "tampa", "tampa3", "tulip", "vamos", "vigero", "virgo", "virgo2", "virgo3", "voodoo", "voodoo2", "yosemite", "yosemite2","yosemite3" };
		constexpr static inline std::array<const char*, 58> OffRoad = { "bfinjection", "bifta", "blazer", "blazer2", "blazer3", "blazer4", "blazer5", "bodhi2", "brawler", "bruiser", "bruiser2", "bruiser3", "brutus", "brutus2", "brutus3", "caracara", "caracara2", "dloader", "dubsta3", "dune", "dune2", "dune3", "dune4", "dune5", "everon", "freecrawler", "hellion", "insurgent", "insurgent2", "insurgent3", "kalahari", "kamacho", "marshall", "mesa3", "monster", "monster3", "monster4", "monster5", "menacer", "outlaw", "nightshark", "rancherxl", "rancherxl2", "rebel", "rebel2", "rcbandito", "riata", "sandking", "sandking2", "technical", "technical2", "technical3", "trophytruck", "trophytruck2", "vagrant", "zhaba", "verus", "winky" };
		constexpr static inline std::array<const char*, 34> SUVs = { "baller", "baller2", "baller3", "baller4", "baller5", "baller6", "bjxl", "cavalcade", "cavalcade2", "contender", "dubsta", "dubsta2", "fq2", "granger", "gresley", "habanero", "huntley", "landstalker", "landstalker2", "mesa", "mesa2", "movak", "patriot", "patriot2", "radi", "rebla", "rocoto", "seminole", "seminole2", "serrano", "toros", "xls", "xls2", "squaddie" };
		constexpr static inline std::array<const char*, 4>  OpenWheel = { "formula", "formula2", "openwheel1", "openwheel2" };
		constexpr static inline std::array<const char*, 25> Trailer = { "armytanker", "armytrailer", "armytrailer2", "baletrailer", "boattrailer", "cablecar", "docktrailer", "freighttrailer", "graintrailer", "proptrailer", "raketrailer", "tr2", "tr3", "tr4", "trflat", "tvtrailer", "tanker", "tanker2", "trailerlarge", "trailerlogs", "trailersmall", "trailers", "trailers2", "trailers3", "trailers4" };
		constexpr static inline std::array<const char*, 7>  Trains = { "freight", "freightcar", "freightcont1", "freightcont2", "freightgrain", "metrotrain", "tankercar" };
		constexpr static inline std::array<const char*, 12> Service = { "airbus", "brickade", "bus", "coach", "pbus2", "rallytruck", "rentalbus", "taxi", "tourbus", "trash", "trash2", "wastelander" };
		constexpr static inline std::array<const char*, 20> Utility = { "airtug", "caddy", "caddy2", "caddy3", "docktug", "forklift", "mower", "ripley", "sadler", "sadler2", "scrap", "towtruck", "towtruck2", "tractor", "tractor2", "tractor3", "utillitruck", "utillitruck2", "utillitruck3", "slamtruck" };
		constexpr static inline std::array<const char*, 35> Vans = { "bison", "bison2", "bison3", "bobcatxl", "boxville", "boxville2", "boxville3", "boxville4", "boxville5", "burrito", "burrito2", "burrito3", "burrito4", "burrito5", "camper", "gburrito", "gburrito2", "journey", "minivan", "minivan2", "paradise", "pony", "pony2", "rumpo", "rumpo2", "rumpo3", "speedo", "speedo2", "speedo4", "surfer", "surfer2", "taco", "youga", "youga2", "youga3" };
		constexpr static inline std::array<const char*, 11> Industrial = { "bulldozer", "cutter", "dump", "flatbed", "guardian", "handler", "mixer", "mixer2", "rubble", "tiptruck", "tiptruck2", };
		constexpr static inline std::array<const char*, 14> Coupes = { "cogcabrio", "exemplar", "f620", "felon", "felon2", "jackal", "oracle", "oracle2", "sentinel", "sentinel2", "windsor", "windsor2", "zion", "zion2" };
		constexpr static inline std::array<const char*, 17> Compacts = { "asbo", "blista", "brioso", "club", "dilettante", "dilettante2", "kanjo", "issi2", "issi3", "issi4", "issi5", "issi6", "panto", "prairie", "rhapsody", "brioso2", "weevil" };

	}; inline std::unique_ptr<CVehicleList> g_VehicleList;

	class CPedList
	{
	public:

		inline static std::size_t PedListPos = 0;
		constexpr static inline std::array<const char*, 3> PedLists{ "Male", "Female", "Animal"};

		constexpr static inline std::array<const char*, 3> Male = { "s_m_y_cop_01", "A_C_shepherd", "s_m_m_fibsec_01" };
		constexpr static inline std::array<const char*, 1> Female = { "s_f_y_cop_01" };
		constexpr static inline std::array<const char*, 32> Animal = { "a_c_boar", "a_c_cat_01", "a_c_chickenhawk", "a_c_chimp", "a_c_chop", "a_c_cormorant", "a_c_cow", "a_c_coyote", "a_c_crow", "a_c_deer", "a_c_dolphin", "a_c_fish", "a_c_hen", "a_c_humpback", "a_c_husky", "a_c_killerwhale", "a_c_mtlion", "a_c_pig", "a_c_pigeon", "a_c_poodle", "a_c_pug", "a_c_rabbit_01", "a_c_rat", "a_c_retriever", "a_c_rhesus", "a_c_rottweiler", "a_c_seagull", "a_c_sharkhammer", "a_c_sharktiger", "a_c_shepherd", "a_c_stingray", "a_c_westy" };
		constexpr static inline std::array<const char*, 670> All = {
		"A_F_M_Beach_01","A_F_M_BevHills_01","A_F_M_BevHills_02","A_F_M_BodyBuild_01","A_F_M_Business_02","A_F_M_Downtown_01","A_F_M_EastSA_01",
		"A_F_M_EastSA_02","A_F_M_FatBla_01","A_F_M_FatCult_01","A_F_M_FatWhite_01","A_F_M_KTown_01","A_F_M_KTown_02","A_F_M_ProlHost_01","A_F_M_Salton_01","A_F_M_SkidRow_01","A_F_M_SouCentMC_01","A_F_M_SouCent_01","A_F_M_SouCent_02",
		"A_F_M_Tourist_01","A_F_M_TrampBeac_01","A_F_M_Tramp_01","A_F_O_GenStreet_01","A_F_O_Indian_01","A_F_O_KTown_01","A_F_O_Salton_01","A_F_O_SouCent_01","A_F_O_SouCent_02","A_F_Y_Beach_01","A_F_Y_BevHills_01","A_F_Y_BevHills_02",
		"A_F_Y_BevHills_03","A_F_Y_BevHills_04","A_F_Y_Business_01","A_F_Y_Business_02","A_F_Y_Business_03","A_F_Y_Business_04","A_F_Y_EastSA_01","A_F_Y_EastSA_02","A_F_Y_EastSA_03","A_F_Y_Epsilon_01","A_F_Y_Fitness_01",
		"A_F_Y_Fitness_02","A_F_Y_GenHot_01","A_F_Y_Golfer_01","A_F_Y_Hiker_01","A_F_Y_Hippie_01","A_F_Y_Hipster_01","A_F_Y_Hipster_02","A_F_Y_Hipster_03","A_F_Y_Hipster_04","A_F_Y_Indian_01","A_F_Y_Juggalo_01","A_F_Y_Runner_01",
		"A_F_Y_RurMeth_01","A_F_Y_SCDressy_01","A_F_Y_Skater_01","A_F_Y_SouCent_01","A_F_Y_SouCent_02","A_F_Y_SouCent_03","A_F_Y_Tennis_01","A_F_Y_Topless_01","A_F_Y_Tourist_01","A_F_Y_Tourist_02","A_F_Y_Vinewood_01",
		"A_F_Y_Vinewood_02","A_F_Y_Vinewood_03","A_F_Y_Vinewood_04","A_F_Y_Yoga_01","A_M_M_ACult_01","A_M_M_AfriAmer_01","A_M_M_Beach_01","A_M_M_Beach_02","A_M_M_BevHills_01","A_M_M_BevHills_02","A_M_M_Business_01",
		"A_M_M_EastSA_01","A_M_M_EastSA_02","A_M_M_Farmer_01","A_M_M_FatLatin_01","A_M_M_GenFat_01","A_M_M_GenFat_02","A_M_M_Golfer_01","A_M_M_HasJew_01","A_M_M_Hillbilly_01","A_M_M_Hillbilly_02","A_M_M_Indian_01",
		"A_M_M_KTown_01","A_M_M_Malibu_01","A_M_M_MexCntry_01","A_M_M_MexLabor_01","A_M_M_OG_Boss_01","A_M_M_Paparazzi_01","A_M_M_Polynesian_01","A_M_M_ProlHost_01","A_M_M_RurMeth_01","A_M_M_Salton_01","A_M_M_Salton_02",
		"A_M_M_Salton_03","A_M_M_Salton_04","A_M_M_Skater_01","A_M_M_Skidrow_01","A_M_M_SoCenLat_01","A_M_M_SouCent_01","A_M_M_SouCent_02","A_M_M_SouCent_03","A_M_M_SouCent_04","A_M_M_StLat_02","A_M_M_Tennis_01",
		"A_M_M_Tourist_01","A_M_M_TrampBeac_01","A_M_M_Tramp_01","A_M_M_TranVest_01","A_M_M_TranVest_02","A_M_O_ACult_01","A_M_O_ACult_02","A_M_O_Beach_01","A_M_O_GenStreet_01","A_M_O_KTown_01","A_M_O_Salton_01",
		"A_M_O_SouCent_01","A_M_O_SouCent_02","A_M_O_SouCent_03","A_M_O_Tramp_01","A_M_Y_ACult_01","A_M_Y_ACult_02","A_M_Y_BeachVesp_01","A_M_Y_BeachVesp_02","A_M_Y_Beach_01","A_M_Y_Beach_02","A_M_Y_Beach_03","A_M_Y_BevHills_01",
		"A_M_Y_BevHills_02","A_M_Y_BreakDance_01","A_M_Y_BusiCas_01","A_M_Y_Business_01","A_M_Y_Business_02","A_M_Y_Business_03","A_M_Y_Cyclist_01","A_M_Y_DHill_01","A_M_Y_Downtown_01","A_M_Y_EastSA_01","A_M_Y_EastSA_02",
		"A_M_Y_Epsilon_01","A_M_Y_Epsilon_02","A_M_Y_Gay_01","A_M_Y_Gay_02","A_M_Y_GenStreet_01","A_M_Y_GenStreet_02","A_M_Y_Golfer_01","A_M_Y_HasJew_01","A_M_Y_Hiker_01","A_M_Y_Hippy_01","A_M_Y_Hipster_01","A_M_Y_Hipster_02",
		"A_M_Y_Hipster_03","A_M_Y_Indian_01","A_M_Y_Jetski_01","A_M_Y_Juggalo_01","A_M_Y_KTown_01","A_M_Y_KTown_02","A_M_Y_Latino_01","A_M_Y_MethHead_01","A_M_Y_MexThug_01","A_M_Y_MotoX_01","A_M_Y_MotoX_02","A_M_Y_MusclBeac_01",
		"A_M_Y_MusclBeac_02","A_M_Y_Polynesian_01","A_M_Y_RoadCyc_01","A_M_Y_Runner_01","A_M_Y_Runner_02","A_M_Y_Salton_01","A_M_Y_Skater_01","A_M_Y_Skater_02","A_M_Y_SouCent_01","A_M_Y_SouCent_02","A_M_Y_SouCent_03","A_M_Y_SouCent_04",
		"A_M_Y_StBla_01","A_M_Y_StBla_02","A_M_Y_StLat_01","A_M_Y_StWhi_01","A_M_Y_StWhi_02","A_M_Y_Sunbathe_01","A_M_Y_Surfer_01","A_M_Y_VinDouche_01","A_M_Y_Vinewood_01","A_M_Y_Vinewood_02","A_M_Y_Vinewood_03","A_M_Y_Vinewood_04",
		"A_M_Y_Yoga_01","CSB_Abigail","CSB_Anita","CSB_Anton","CSB_BallasOG","CSB_Bride","CSB_BurgerDrug","CSB_Car3guy1","CSB_Car3guy2","CSB_Chef","CSB_Chin_goon","CSB_Cletus","CSB_Cop","CSB_Customer","CSB_Denise_friend",
		"CSB_FOS_rep","CSB_G","CSB_Groom","CSB_Grove_str_dlr","CSB_Hao","CSB_Hugh","CSB_Imran","CSB_Janitor","CSB_Maude","CSB_MWeather","CSB_Ortega","CSB_Oscar","CSB_PornDudes","CSB_PrologueDriver","CSB_ProlSec","CSB_Ramp_gang",
		"CSB_Ramp_hic","CSB_Ramp_hipster","CSB_Ramp_marine","CSB_Ramp_mex","CSB_Reporter","CSB_RoccoPelosi","CSB_Screen_Writer","CSB_Stripper_01","CSB_Stripper_02","CSB_Tonya","CSB_TrafficWarden","CS_AmandaTownley","CS_Andreas",
		"cs_ashley","CS_Bankman","CS_Barry","CS_Beverly","CS_Brad","CS_BradCadaver","CS_Carbuyer","CS_Casey","CS_ChengSr","CS_ChrisFormage","CS_Clay","CS_Dale","CS_DaveNorton","cs_debra","cs_denise","CS_Devin","CS_Dom","CS_Dreyfuss",
		"CS_DrFriedlander","CS_Fabien","CS_FBISuit_01","CS_Floyd","CS_Guadalope","cs_gurk","CS_Hunter","CS_Janet","CS_JewelAss","CS_JimmyBoston","CS_JimmyDiSanto","CS_JoeMinuteMan","CS_JohnnyKlebitz","CS_Josef","CS_Josh","CS_LamarDavis",
		"CS_Lazlow","CS_LesterCrest","CS_LifeInvad_01","CS_Magenta","CS_Manuel","CS_Marnie","CS_MartinMadrazo","CS_MaryAnn","CS_Michelle","CS_Milton","CS_Molly","CS_MovPremF_01","CS_MovPremMale","CS_MRK","CS_MrsPhillips","CS_MRS_Thornhill",
		"CS_Natalia","CS_NervousRon","CS_Nigel","CS_Old_Man1A","CS_Old_Man2","CS_Omega","CS_Orleans","CS_Paper","CS_Patricia","CS_Priest","CS_ProlSec_02","CS_RussianDrunk","CS_SiemonYetarian","CS_Solomon","CS_SteveHains","CS_Stretch",
		"CS_Tanisha","CS_TaoCheng","CS_TaosTranslator","CS_TennisCoach","CS_Terry","CS_Tom","CS_TomEpsilon","CS_TracyDiSanto","CS_Wade","CS_Zimbor","G_F_Y_ballas_01","G_F_Y_Families_01","G_F_Y_Lost_01","G_F_Y_Vagos_01","G_M_M_ArmBoss_01",
		"G_M_M_ArmGoon_01","G_M_M_ArmLieut_01","G_M_M_ChemWork_01","G_M_M_ChiBoss_01","G_M_M_ChiCold_01","G_M_M_ChiGoon_01","G_M_M_ChiGoon_02","G_M_M_KorBoss_01","G_M_M_MexBoss_01","G_M_M_MexBoss_02","G_M_Y_ArmGoon_02","G_M_Y_Azteca_01",
		"G_M_Y_BallaEast_01","G_M_Y_BallaOrig_01","G_M_Y_BallaSout_01","G_M_Y_FamCA_01","G_M_Y_FamDNF_01","G_M_Y_FamFor_01","G_M_Y_Korean_01","G_M_Y_Korean_02","G_M_Y_KorLieut_01","G_M_Y_Lost_01","G_M_Y_Lost_02","G_M_Y_Lost_03",
		"G_M_Y_MexGang_01","G_M_Y_MexGoon_01","G_M_Y_MexGoon_02","G_M_Y_MexGoon_03","G_M_Y_PoloGoon_01","G_M_Y_PoloGoon_02","G_M_Y_SalvaBoss_01","G_M_Y_SalvaGoon_01","G_M_Y_SalvaGoon_02","G_M_Y_SalvaGoon_03","G_M_Y_StrPunk_01","G_M_Y_StrPunk_02",
		"HC_Driver","HC_Gunman","HC_Hacker","IG_Abigail","IG_AmandaTownley","IG_Andreas","IG_Ashley","IG_BallasOG","IG_Bankman","IG_Barry","IG_BestMen","IG_Beverly","IG_Brad","IG_Bride","IG_Car3guy1","IG_Car3guy2","IG_Casey",
		"IG_Chef","IG_ChengSr","IG_ChrisFormage","IG_Clay","IG_ClayPain","IG_Cletus","IG_Dale","IG_DaveNorton","IG_Denise","IG_Devin","IG_Dom","IG_Dreyfuss","IG_DrFriedlander","IG_Fabien","IG_FBISuit_01","IG_Floyd","IG_Groom",
		"IG_Hao","IG_Hunter","IG_Janet","ig_JAY_Norris","IG_JewelAss","IG_JimmyBoston","IG_JimmyDiSanto","IG_JoeMinuteMan","ig_JohnnyKlebitz","IG_Josef","IG_Josh","IG_KerryMcIntosh","IG_LamarDavis","IG_Lazlow","IG_LesterCrest",
		"IG_LifeInvad_01","IG_LifeInvad_02","IG_Magenta","IG_Manuel","IG_Marnie","IG_MaryAnn","IG_Maude","IG_Michelle","IG_Milton","IG_Molly","IG_MRK","IG_MrsPhillips","IG_MRS_Thornhill","IG_Natalia","IG_NervousRon","IG_Nigel",
		"IG_Old_Man1A","IG_Old_Man2","IG_Omega","IG_ONeil","IG_Orleans","IG_Ortega","IG_Paper","IG_Patricia","IG_Priest","IG_ProlSec_02","IG_Ramp_Gang","IG_Ramp_Hic","IG_Ramp_Hipster","IG_Ramp_Mex","IG_RoccoPelosi","IG_RussianDrunk",
		"IG_Screen_Writer","IG_SiemonYetarian","IG_Solomon","IG_SteveHains","IG_Stretch","IG_Talina","IG_Tanisha","IG_TaoCheng","IG_TaosTranslator","ig_TennisCoach","IG_Terry","IG_TomEpsilon","IG_Tonya","IG_TracyDiSanto","IG_TrafficWarden",
		"IG_TylerDix","IG_Wade","IG_Zimbor","MP_F_DeadHooker","MP_F_Freemode_01","MP_F_Misty_01","MP_F_StripperLite","MP_G_M_Pros_01","MP_HeadTargets","MP_M_Claude_01","MP_M_ExArmy_01","MP_M_FamDD_01","MP_M_FIBSec_01","MP_M_Freemode_01",
		"MP_M_Marston_01","MP_M_Niko_01","MP_M_ShopKeep_01","MP_S_M_Armoured_01","Player_One","Player_Two","Player_Zero","slod_human","slod_large_quadped","slod_small_quadped","S_F_M_Fembarber","S_F_M_Maid_01","S_F_M_Shop_HIGH",
		"S_F_M_SweatShop_01","S_F_Y_AirHostess_01","S_F_Y_Bartender_01","S_F_Y_Baywatch_01","S_F_Y_Cop_01","S_F_Y_Factory_01","S_F_Y_Hooker_01","S_F_Y_Hooker_02","S_F_Y_Hooker_03","S_F_Y_Migrant_01","S_F_Y_MovPrem_01","S_F_Y_Ranger_01",
		"S_F_Y_Scrubs_01","S_F_Y_Sheriff_01","S_F_Y_Shop_LOW","S_F_Y_Shop_MID","S_F_Y_StripperLite","S_F_Y_Stripper_01","S_F_Y_Stripper_02","S_F_Y_SweatShop_01","S_M_M_AmmuCountry","S_M_M_Armoured_01","S_M_M_Armoured_02","S_M_M_AutoShop_01",
		"S_M_M_AutoShop_02","S_M_M_Bouncer_01","S_M_M_ChemSec_01","S_M_M_CIASec_01","S_M_M_CntryBar_01","S_M_M_DockWork_01","S_M_M_Doctor_01","S_M_M_FIBOffice_01","S_M_M_FIBOffice_02","S_M_M_Gaffer_01","S_M_M_Gardener_01","S_M_M_GenTransport",
		"S_M_M_HairDress_01","S_M_M_HighSec_01","S_M_M_HighSec_02","S_M_M_Janitor","S_M_M_LatHandy_01","S_M_M_LifeInvad_01","S_M_M_Linecook","S_M_M_LSMetro_01","S_M_M_Mariachi_01","S_M_M_Marine_01","S_M_M_Marine_02","S_M_M_Migrant_01",
		"S_M_M_MovAlien_01","S_M_M_MovPrem_01","S_M_M_MovSpace_01","S_M_M_Paramedic_01","S_M_M_Pilot_01","S_M_M_Pilot_02","S_M_M_Postal_01","S_M_M_Postal_02","S_M_M_PrisGuard_01","S_M_M_Scientist_01","S_M_M_Security_01","S_M_M_SnowCop_01",
		"S_M_M_StrPerf_01","S_M_M_StrPreach_01","S_M_M_StrVend_01","S_M_M_Trucker_01","S_M_M_UPS_01","S_M_M_UPS_02","S_M_O_Busker_01","S_M_Y_AirWorker","S_M_Y_AmmuCity_01","S_M_Y_ArmyMech_01","S_M_Y_Autopsy_01","S_M_Y_Barman_01","S_M_Y_BayWatch_01",
		"S_M_Y_BlackOps_01","S_M_Y_BlackOps_02","S_M_Y_BlackOps_03","S_M_Y_BusBoy_01","S_M_Y_Chef_01","S_M_Y_Clown_01","S_M_Y_Construct_01","S_M_Y_Construct_02","S_M_Y_Cop_01","S_M_Y_Dealer_01","S_M_Y_DevinSec_01","S_M_Y_DockWork_01","S_M_Y_Doorman_01",
		"S_M_Y_DWService_01","S_M_Y_DWService_02","S_M_Y_Factory_01","S_M_Y_Fireman_01","S_M_Y_Garbage","S_M_Y_Grip_01","S_M_Y_HwayCop_01","S_M_Y_Marine_01","S_M_Y_Marine_02","S_M_Y_Marine_03","S_M_Y_Mime","S_M_Y_PestCont_01",
		"S_M_Y_Pilot_01","S_M_Y_PrisMuscl_01","S_M_Y_Prisoner_01","S_M_Y_Ranger_01","S_M_Y_Robber_01","S_M_Y_Sheriff_01","S_M_Y_Shop_MASK","S_M_Y_StrVend_01","S_M_Y_Swat_01","S_M_Y_USCG_01","S_M_Y_Valet_01","S_M_Y_Waiter_01",
		"S_M_Y_WinClean_01","S_M_Y_XMech_01","S_M_Y_XMech_02","U_F_M_Corpse_01","U_F_M_Miranda","U_F_M_ProMourn_01","U_F_O_MovieStar","U_F_O_ProlHost_01","U_F_Y_BikerChic","U_F_Y_COMJane","U_F_Y_corpse_01","U_F_Y_corpse_02",
		"U_F_Y_HotPosh_01","U_F_Y_JewelAss_01","U_F_Y_Mistress","U_F_Y_PoppyMich","U_F_Y_Princess","U_F_Y_SpyActress","U_M_M_Aldinapoli","U_M_M_BankMan","U_M_M_BikeHire_01","U_M_M_FIBArchitect","U_M_M_FilmDirector","U_M_M_GlenStank_01",
		"U_M_M_Griff_01","U_M_M_Jesus_01","U_M_M_JewelSec_01","U_M_M_JewelThief","U_M_M_MarkFost","U_M_M_PartyTarget","U_M_M_ProlSec_01","U_M_M_ProMourn_01","U_M_M_RivalPap","U_M_M_SpyActor","U_M_M_WillyFist","U_M_O_FinGuru_01",
		"U_M_O_TapHillBilly","U_M_O_Tramp_01","U_M_Y_Abner","U_M_Y_AntonB",	"U_M_Y_BabyD","U_M_Y_Baygor","U_M_Y_BurgerDrug_01","U_M_Y_Chip","U_M_Y_Cyclist_01","U_M_Y_FIBMugger_01","U_M_Y_Guido_01","U_M_Y_GunVend_01","U_M_Y_Hippie_01",
		"U_M_Y_ImpoRage","U_M_Y_Justin","U_M_Y_Mani","U_M_Y_MilitaryBum","U_M_Y_Paparazzi","U_M_Y_Party_01","U_M_Y_Pogo_01","U_M_Y_Prisoner_01","U_M_Y_ProlDriver_01","U_M_Y_RSRanger_01","U_M_Y_SBike","U_M_Y_StagGrm_01","U_M_Y_Tattoo_01",
		"U_M_Y_Zombie_01",
		};
	}; inline std::unique_ptr<CPedList> g_PedList;

	static struct {
		const char* vehiclePreviewDict;
		const char* vehicleName;
	} VehiclePreviews[332] = {
		{ "lgm_default", "adder" },
		{ "lgm_default", "banshee" },
		{ "lgm_default", "bullet" },
		{ "lgm_default", "carbon" },
		{ "lgm_default", "carboniz" },
		{ "lgm_default", "cheetah" },
		{ "lgm_default", "cogcabri" },
		{ "lgm_default", "comet2" },
		{ "lgm_default", "coquette" },
		{ "lgm_default", "elegy2" },
		{ "lgm_default", "entityxf" },
		{ "lgm_default", "exemplar" },
		{ "lgm_default", "feltzer" },
		{ "lgm_default", "hotknife" },
		{ "lgm_default", "infernus" },
		{ "lgm_default", "jb700" },
		{ "lgm_default", "khamel" },
		{ "lgm_default", "monroe" },
		{ "lgm_default", "ninef" },
		{ "lgm_default", "ninef2" },
		{ "lgm_default", "rapidgt" },
		{ "lgm_default", "rapidgt2" },
		{ "lgm_default", "stinger" },
		{ "lgm_default", "stingerg" },
		{ "lgm_default", "superd" },
		{ "lgm_default", "surano_convertable" },
		{ "lgm_default", "vacca" },
		{ "lgm_default", "voltic_tless" },
		{ "lgm_default", "ztype" },
		{ "lgm_dlc_apartments", "baller3" },
		{ "lgm_dlc_apartments", "baller4" },
		{ "lgm_dlc_apartments", "voltic_tless" },
		{ "lgm_dlc_apartments", "cog55" },
		{ "lgm_dlc_apartments", "cognosc" },
		{ "lgm_dlc_apartments", "mamba" },
		{ "lgm_dlc_apartments", "niteshad" },
		{ "lgm_dlc_apartments", "schafter3" },
		{ "lgm_dlc_apartments", "schafter4" },
		{ "lgm_dlc_apartments", "verlier" },
		{ "lgm_dlc_arena", "cliquexmas" },
		{ "lgm_dlc_arena", "deveste" },
		{ "lgm_dlc_arena", "deviant" },
		{ "lgm_dlc_arena", "italigto" },
		{ "lgm_dlc_arena", "schlagen" },
		{ "lgm_dlc_arena", "toros" },
		{ "lgm_dlc_arena", "clique" },
		{ "lgm_dlc_assault", "flashgt" },
		{ "lgm_dlc_assault", "gb200" },
		{ "lgm_dlc_assault", "jester3" },
		{ "lgm_dlc_assault", "taipan" },
		{ "lgm_dlc_assault", "tezeract" },
		{ "lgm_dlc_assault", "tyrant" },
		{ "lgm_dlc_assault", "entity2" },
		{ "lgm_dlc_battle", "freecrawler" },
		{ "lgm_dlc_battle", "stafford" },
		{ "lgm_dlc_battle", "swinger" },
		{ "lgm_dlc_biker", "hakuchou2" },
		{ "lgm_dlc_biker", "raptor" },
		{ "lgm_dlc_biker", "shotaro" },
		{ "lgm_dlc_business", "alpha" },
		{ "lgm_dlc_business", "jester" },
		{ "lgm_dlc_business", "turismor" },
		{ "lgm_dlc_business2", "banshee_tless" },
		{ "lgm_dlc_business2", "coquette_tless" },
		{ "lgm_dlc_business2", "huntley" },
		{ "lgm_dlc_business2", "massacro" },
		{ "lgm_dlc_business2", "stinger_tless" },
		{ "lgm_dlc_business2", "thrust" },
		{ "lgm_dlc_business2", "voltic_htop" },
		{ "lgm_dlc_business2", "zentorno" },
		{ "lgm_dlc_casinoheist", "imorgon" },
		{ "lgm_dlc_casinoheist", "komoda" },
		{ "lgm_dlc_casinoheist", "rebla" },
		{ "lgm_dlc_casinoheist", "stryder" },
		{ "lgm_dlc_casinoheist", "vstr" },
		{ "lgm_dlc_casinoheist", "formula" },
		{ "lgm_dlc_casinoheist", "formula2" },
		{ "lgm_dlc_casinoheist", "furia" },
		{ "lgm_dlc_executive1", "bestiagts" },
		{ "lgm_dlc_executive1", "fmj" },
		{ "lgm_dlc_executive1", "pfister811" },
		{ "lgm_dlc_executive1", "prototipo" },
		{ "lgm_dlc_executive1", "reaper" },
		{ "lgm_dlc_executive1", "seven70" },
		{ "lgm_dlc_executive1", "windsor2" },
		{ "lgm_dlc_executive1", "xls_web_vehicle_regular_b" },
		{ "lgm_dlc_gunrunning", "vagner" },
		{ "lgm_dlc_gunrunning", "xa21" },
		{ "lgm_dlc_gunrunning", "cheetah2" },
		{ "lgm_dlc_gunrunning", "torero" },
		{ "lgm_dlc_heist", "casco" },
		{ "lgm_dlc_heist", "lectro" },
		{ "lgm_dlc_heist4", "italirsx" },
		{ "lgm_dlc_importexport", "penetrator" },
		{ "lgm_dlc_importexport", "tempesta" },
		{ "lgm_dlc_lts_creator", "furore" },
		{ "lgm_dlc_luxe", "brawler" },
		{ "lgm_dlc_luxe", "chino" },
		{ "lgm_dlc_luxe", "coquette3" },
		{ "lgm_dlc_luxe", "feltzer3" },
		{ "lgm_dlc_luxe", "osiris" },
		{ "lgm_dlc_luxe", "t20" },
		{ "lgm_dlc_luxe", "vindicator" },
		{ "lgm_dlc_luxe", "virgo" },
		{ "lgm_dlc_luxe", "windsor_windsor_lgm_1_b" },
		{ "lgm_dlc_pilot", "coquette2" },
		{ "lgm_dlc_pilot", "coquette2_tless" },
		{ "lgm_dlc_specialraces", "gp1" },
		{ "lgm_dlc_specialraces", "infernus2" },
		{ "lgm_dlc_specialraces", "ruston" },
		{ "lgm_dlc_specialraces", "turismo2" },
		{ "lgm_dlc_security", "baller7" },
		{ "lgm_dlc_security", "champion" },
		{ "lgm_dlc_security", "cinquemila" },
		{ "lgm_dlc_security", "comet7" },
		{ "lgm_dlc_security", "deity" },
		{ "lgm_dlc_security", "ignus" },
		{ "lgm_dlc_security", "jubilee" },
		{ "lgm_dlc_security", "reever" },
		{ "lgm_dlc_security", "shinobi" },
		{ "lgm_dlc_security", "zeno" },
		{ "lgm_dlc_security", "astron" },
		{ "lgm_dlc_smuggler", "cyclone" },
		{ "lgm_dlc_smuggler", "rapidgt3" },
		{ "lgm_dlc_smuggler", "visione" },
		{ "lgm_dlc_stunt", "le7b_lms_le7b_livery_1_b" },
		{ "lgm_dlc_stunt", "lynx_lms_lynx_livery_2_b" },
		{ "lgm_dlc_stunt", "sheava_lms_sheava_livery_2_b" },
		{ "lgm_dlc_stunt", "tyrus_lms_tyrus_livery_1_b" },
		{ "lgm_dlc_summer2020", "openwheel2" },
		{ "lgm_dlc_summer2020", "tigon" },
		{ "lgm_dlc_summer2020", "coquette4" },
		{ "lgm_dlc_summer2020", "openwheel1" },
		{ "lgm_dlc_tuner", "cypher" },
		{ "lgm_dlc_tuner", "euros" },
		{ "lgm_dlc_tuner", "growler" },
		{ "lgm_dlc_tuner", "jester4" },
		{ "lgm_dlc_tuner", "tailgater2" },
		{ "lgm_dlc_tuner", "vectre" },
		{ "lgm_dlc_tuner", "zr350" },
		{ "lgm_dlc_tuner", "comet6" },
		{ "lgm_dlc_valentines", "roosevelt" },
		{ "lgm_dlc_valentines2", "roosevelt2" },
		{ "lgm_dlc_vinewood", "jugular" },
		{ "lgm_dlc_vinewood", "krieger" },
		{ "lgm_dlc_vinewood", "locust" },
		{ "lgm_dlc_vinewood", "neo" },
		{ "lgm_dlc_vinewood", "novak" },
		{ "lgm_dlc_vinewood", "paragon" },
		{ "lgm_dlc_vinewood", "rrocket" },
		{ "lgm_dlc_vinewood", "s80" },
		{ "lgm_dlc_vinewood", "thrax" },
		{ "lgm_dlc_vinewood", "zorrusso" },
		{ "lgm_dlc_vinewood", "drafter" },
		{ "lgm_dlc_vinewood", "emerus" },
		{ "lsc_default", "buccaneer2" },
		{ "lsc_default", "chino2" },
		{ "lsc_default", "faction2" },
		{ "lsc_default", "moonbeam2" },
		{ "lsc_default", "primo2" },
		{ "lsc_default", "voodoo" },
		{ "lsc_dlc_import_export", "comet3" },
		{ "lsc_dlc_import_export", "diablous2" },
		{ "lsc_dlc_import_export", "elegy" },
		{ "lsc_dlc_import_export", "fcr2" },
		{ "lsc_dlc_import_export", "italiagtb2" },
		{ "lsc_dlc_import_export", "nero2" },
		{ "lsc_dlc_import_export", "specter2" },
		{ "lsc_jan2016", "banshee2" },
		{ "lsc_jan2016", "sultan2" },
		{ "lsc_lowrider2", "faction3" },
		{ "lsc_lowrider2", "minivan2" },
		{ "lsc_lowrider2", "sabregt2" },
		{ "lsc_lowrider2", "slamvan3" },
		{ "lsc_lowrider2", "tornado5" },
		{ "lsc_lowrider2", "virgo2" },
		{ "sssa_default", "akuma" },
		{ "sssa_default", "baller2" },
		{ "sssa_default", "banshee" },
		{ "sssa_default", "bati" },
		{ "sssa_default", "bati2_sss_cerveza_b" },
		{ "sssa_default", "bfinject" },
		{ "sssa_default", "bifta" },
		{ "sssa_default", "bison" },
		{ "sssa_default", "blazer" },
		{ "sssa_default", "bodhi" },
		{ "sssa_default", "cavcade" },
		{ "sssa_default", "comet2" },
		{ "sssa_default", "dilettan" },
		{ "sssa_default", "double" },
		{ "sssa_default", "dune" },
		{ "sssa_default", "exemplar" },
		{ "sssa_default", "faggio" },
		{ "sssa_default", "felon" },
		{ "sssa_default", "felon2" },
		{ "sssa_default", "feltzer" },
		{ "sssa_default", "fugitive" },
		{ "sssa_default", "gauntlet" },
		{ "sssa_default", "hexer" },
		{ "sssa_default", "infernus" },
		{ "sssa_default", "issi2" },
		{ "sssa_default", "kalahari" },
		{ "sssa_default", "ninef" },
		{ "sssa_default", "oracle" },
		{ "sssa_default", "paradise_sss_logger_b" },
		{ "sssa_default", "pcj" },
		{ "sssa_default", "rebel" },
		{ "sssa_default", "rocoto" },
		{ "sssa_default", "ruffian" },
		{ "sssa_default", "sadler" },
		{ "sssa_default", "sanchez_sss_atomic_b" },
		{ "sssa_default", "sanchez2" },
		{ "sssa_default", "sandkin2" },
		{ "sssa_default", "sandking" },
		{ "sssa_default", "schwarze" },
		{ "sssa_default", "superd" },
		{ "sssa_default", "surano" },
		{ "sssa_default", "vacca" },
		{ "sssa_default", "vader" },
		{ "sssa_default", "vigero" },
		{ "sssa_default", "zion" },
		{ "sssa_default", "zion2" },
		{ "sssa_dlc_biker", "avarus" },
		{ "sssa_dlc_biker", "bagger" },
		{ "sssa_dlc_biker", "blazer4" },
		{ "sssa_dlc_biker", "chimera" },
		{ "sssa_dlc_biker", "daemon2" },
		{ "sssa_dlc_biker", "defiler" },
		{ "sssa_dlc_biker", "esskey" },
		{ "sssa_dlc_biker", "faggio3" },
		{ "sssa_dlc_biker", "faggion" },
		{ "sssa_dlc_biker", "manchez" },
		{ "sssa_dlc_biker", "nightblade" },
		{ "sssa_dlc_biker", "ratbike" },
		{ "sssa_dlc_biker", "sanctus" },
		{ "sssa_dlc_biker", "tornado6" },
		{ "sssa_dlc_biker", "vortex" },
		{ "sssa_dlc_biker", "woflsbane" },
		{ "sssa_dlc_biker", "youga2" },
		{ "sssa_dlc_biker", "zombiea" },
		{ "sssa_dlc_biker", "zombieb" },
		{ "sssa_dlc_business", "asea" },
		{ "sssa_dlc_business", "astrope" },
		{ "sssa_dlc_business", "bobcatxl" },
		{ "sssa_dlc_business", "cavcade2" },
		{ "sssa_dlc_business", "granger" },
		{ "sssa_dlc_business", "ingot" },
		{ "sssa_dlc_business", "intruder" },
		{ "sssa_dlc_business", "minivan" },
		{ "sssa_dlc_business", "premier" },
		{ "sssa_dlc_business", "radi" },
		{ "sssa_dlc_business", "rancherx" },
		{ "sssa_dlc_business", "stanier" },
		{ "sssa_dlc_business", "stratum" },
		{ "sssa_dlc_business", "washingt" },
		{ "sssa_dlc_business2", "dominato" },
		{ "sssa_dlc_business2", "f620" },
		{ "sssa_dlc_business2", "fusilade" },
		{ "sssa_dlc_business2", "penumbra" },
		{ "sssa_dlc_business2", "sentinel" },
		{ "sssa_dlc_business2", "sentinel_convertable" },
		{ "sssa_dlc_christmas_2", "jester2" },
		{ "sssa_dlc_christmas_2", "massacro2" },
		{ "sssa_dlc_christmas_2", "rloader2" },
		{ "sssa_dlc_christmas_2", "slamvan" },
		{ "sssa_dlc_christmas_3", "tampa" },
		{ "sssa_dlc_executive_1", "rumpo3" },
		{ "sssa_dlc_halloween", "btype2_sss_death_b" },
		{ "sssa_dlc_halloween", "lurcher_sss_hangman_b" },
		{ "sssa_dlc_heist", "blade" },
		{ "sssa_dlc_heist", "enduro" },
		{ "sssa_dlc_heist", "gburrito2" },
		{ "sssa_dlc_heist", "gresley" },
		{ "sssa_dlc_heist", "guardian" },
		{ "sssa_dlc_heist", "innovation" },
		{ "sssa_dlc_heist", "jackal" },
		{ "sssa_dlc_heist", "kuruma" },
		{ "sssa_dlc_heist", "kuruma2" },
		{ "sssa_dlc_heist", "landstalker" },
		{ "sssa_dlc_heist", "nemesis" },
		{ "sssa_dlc_heist", "oracle1" },
		{ "sssa_dlc_heist", "rumpo" },
		{ "sssa_dlc_heist", "schafter2" },
		{ "sssa_dlc_heist", "seminole" },
		{ "sssa_dlc_heist", "surge" },
		{ "sssa_dlc_hipster", "blade" },
		{ "sssa_dlc_hipster", "blazer3" },
		{ "sssa_dlc_hipster", "buffalo" },
		{ "sssa_dlc_hipster", "buffalo2" },
		{ "sssa_dlc_hipster", "glendale" },
		{ "sssa_dlc_hipster", "panto" },
		{ "sssa_dlc_hipster", "picador" },
		{ "sssa_dlc_hipster", "pigalle" },
		{ "sssa_dlc_hipster", "primo" },
		{ "sssa_dlc_hipster", "rebel2" },
		{ "sssa_dlc_hipster", "regina" },
		{ "sssa_dlc_hipster", "rhapsody" },
		{ "sssa_dlc_hipster", "surfer" },
		{ "sssa_dlc_hipster", "tailgater" },
		{ "sssa_dlc_hipster", "warrener" },
		{ "sssa_dlc_hipster", "youga" },
		{ "sssa_dlc_independence", "sovereign" },
		{ "sssa_dlc_lts_creator", "hakuchou" },
		{ "sssa_dlc_lts_creator", "innovation" },
		{ "sssa_dlc_lts_creator", "kalahari_topless" },
		{ "sssa_dlc_mp_to_sp", "blista2" },
		{ "sssa_dlc_mp_to_sp", "buffalo3" },
		{ "sssa_dlc_mp_to_sp", "dominator2" },
		{ "sssa_dlc_mp_to_sp", "dukes" },
		{ "sssa_dlc_mp_to_sp", "gauntlet2" },
		{ "sssa_dlc_mp_to_sp", "stalion2" },
		{ "sssa_dlc_mp_to_sp", "stallion" },
		{ "sssa_dlc_stunt", "bf400_sss_bf400_livery_1_b" },
		{ "sssa_dlc_stunt", "brioso_sss_brioso_livery_1_b" },
		{ "sssa_dlc_stunt", "cliffhanger_sss_cliffhanger_livery_1_b" },
		{ "sssa_dlc_stunt", "contender" },
		{ "sssa_dlc_stunt", "gargoyle_sss_gargoyle_livery_1_b" },
		{ "sssa_dlc_stunt", "omnis_sss_omnis_livery_1_b" },
		{ "sssa_dlc_stunt", "rallytruck_sss_dune_livery_1_b" },
		{ "sssa_dlc_stunt", "tampa2_sss_tampa2_livery_1_b" },
		{ "sssa_dlc_stunt", "trophy_sss_trophy_livery_1_b" },
		{ "sssa_dlc_stunt", "trophy2_sss_trophy2_livery_1_b" },
		{ "sssa_dlc_stunt", "tropos_sss_tropos_livery_1_b" },
		{ "sssa_dlc_valentines", "rloader" },
		{ "candc_gunrunning", "apc" },
		{ "candc_gunrunning", "ardent" },
		{ "candc_gunrunning", "dune3" },
		{ "candc_gunrunning", "halftrack" },
		{ "candc_gunrunning", "nightshark" },
		{ "candc_gunrunning", "oppressor" },
		{ "candc_gunrunning", "tampa3" },
		{ "candc_gunrunning", "trsmall2" },
	};

	static struct {
		const char* Name;
		float X;
		float Y;
		float Z;
	} TPLocationsOutdoor[56] = {
		{ "IAA Roof", 134.085,-637.859,262.851 },
		{ "FIB Roof", 150.126,-754.591,262.865 },
		{ "Maze Bank Roof", -75.015,-818.215,326.176 },
		{ "Top Of The Mt Chilad", 450.718,5566.614,806.183 },
		{ "Most Northerly Point", 24.775,7644.102,19.055 },
		{ "Vinewood Bowl Stage", 686.245,577.950,130.461 },
		{ "Sisyphus Theater Stage", 205.316,1167.378,227.005 },
		{ "Galileo Observatory Roof", -438.804,1076.097,352.411 },
		{ "Kortz Center", -2243.810,264.048,174.615 },
		{ "Chumash Historic", -3426.683,967.738,8.347 },
		{ "Paleto Bay Pier", -275.522,6635.835,7.425 },
		{ "God's thumb", -1006.402,6272.383,1.503 },
		{ "Calafia Train Bridge", -517.869,4425.284,89.795 },
		{ "Altruist Cult Camp", -1170.841,4926.646,224.295 },
		{ "Maze Bank Arena Roof", -324.300,-1968.545,67.002 },
		{ "Marlowe Vineyards", -1868.971,2095.674,139.115 },
		{ "Hippy Camp", 2476.712,3789.645,41.226 },
		{ "Devin Weston's House", -2639.872,1866.812,160.135 },
		{ "Abandon Mine", -595.342,2086.008,131.412 },
		{ "Weed Farm", 2208.777,5578.235,53.735 },
		{ "Stab City", 126.975,3714.419,46.827 },
		{ "Airplane Graveyard Airplane Tail", 2395.096,3049.616,60.053 },
		{ "Satellite Dish Antenna", 2034.988,2953.105,74.602 },
		{ "Satellite Dishes", 2062.123,2942.055,47.431 },
		{ "Windmill Top", 2026.677,1842.684,133.313 },
		{ "Sandy Shores Building Site Crane", 1051.209,2280.452,89.727 },
		{ "Rebel Radio", 736.153,2583.143,79.634 },
		{ "Quarry", 2954.196,2783.410,41.004 },
		{ "Palmer-Taylor Power Station Chimney", 2732.931,1577.540,83.671 },
		{ "Merryweather Dock", 486.417,-3339.692,6.070 },
		{ "Cargo Ship", 899.678,-2882.191,19.013 },
		{ "Del Perro Pier", -1850.127,-1231.751,13.017 },
		{ "Play Boy Mansion", -1475.234,167.088,55.841 },
		{ "Jolene Cranley-Evans Ghost", 3059.620,5564.246,197.091 },
		{ "NOOSE Headquarters", 2535.243,-383.799,92.993 },
		{ "Snowman", 971.245,-1620.993,30.111 },
		{ "Oriental Theater", 293.089,180.466,104.301 },
		{ "Beach Skatepark", -1374.881,-1398.835,6.141 },
		{ "Underpass Skatepark", 718.341,-1218.714,26.014 },
		{ "Casino", 925.329,46.152,80.908 },
		{ "University of San Andreas", -1696.866,142.747,64.372 },
		{ "La Puerta Freeway Bridge", -543.932,-2225.543,122.366 },
		{ "Land Act Dam", 1660.369,-12.013,170.020 },
		{ "Mount Gordo", 2877.633,5911.078,369.624 },
		{ "Little Seoul", -889.655,-853.499,20.566 },
		{ "Epsilon Building", -695.025,82.955,55.855 },
		{ "The Richman Hotel", -1330.911,340.871,64.078 },
		{ "Vinewood Sign", 711.362,1198.134,348.526 },
		{ "Los Santos Golf Club", -1336.715,59.051,55.246 },
		{ "Chicken", -31.010,6316.830,40.083 },
		{ "Little Portola", -635.463,-242.402,38.175 },
		{ "Pacific Bluffs Country Club", -3022.222,39.968,13.611 },
		{ "Paleto Forest Sawmill Chimney", -549.467,5308.221,114.146 },
		{ "Mirror Park", 1070.206,-711.958,58.483 },
		{ "Rocket", 1608.698,6438.096,37.637 },
		{ "El Gordo Lighthouse", 3430.155,5174.196,41.280 },
	};

	static struct {
		const char* Name;
		float X;
		float Y;
		float Z;
	} TPLocationsIndoor[16] = {
		{ "Strip Club DJ Booth", 126.135,-1278.583,29.270 },
		{ "Blaine County Savings Bank", -109.299,6464.035,31.627 },
		{ "Police Station", 436.491,-982.172,30.699 },
		{ "Humane Labs Tunnel", 3525.495,3705.301,20.992 },
		{ "Ammunation Office", 12.494,-1110.130,29.797 },
		{ "Ammunation Gun Range", 22.153,-1072.854,29.797 },
		{ "Trevor's Meth Lab", 1391.773,3608.716,38.942 },
		{ "Pacific Standard Bank Vault", 255.851,217.030,101.683 },
		{ "Lester's House", 1273.898,-1719.304,54.771 },
		{ "Floyd's Apartment", -1150.703,-1520.713,10.633 },
		{ "FIB Top Floor", 135.733,-749.216,258.152 },
		{ "IAA Office", 117.220,-620.938,206.047 },
		{ "Pacific Standard Bank", 235.046,216.434,106.287 },
		{ "Fort Zancudo ATC Entrance", -2344.373,3267.498,32.811 },
		{ "Fort Zancudo ATC Top Floor", -2358.132,3249.754,101.451 },
		{ "Torture Room", 147.170,-2201.804,4.688 },
	};

	static struct {
		const char* Name;
		float X;
		float Y;
		float Z;
	} TPLocationsLSC[6] = {
		{ "Benny's Garage", -206.91985,-1300.7858,31.29598 },
		{ "Beekers Garage", 120.13485,6616.1055,31.850428 },
		{ "Sandy Shores", 1174.49,2658.1643,38.070953 },
		{ "Grand Senora Dust", -1136.742,-1982.3253,13.164545 },
		{ "Burton", -375.6223,-128.76067,38.684124 },
		{ "La Mesa", 707.62823,-1087.7771,22.433643 },
	};

	static struct {
		const char* Name;
		float X;
		float Y;
		float Z;
	} TPLocationsCS[13] = {
		{ "Paleto Bay", -4.509100,6521.252930,30.571024 },
		{ "Grapeseed", 1678.057495,4819.882324,41.299820 },
		{ "Grand Senora", 1179.679688,2691.378662,37.124043 },
		{ "Great Chaparral", -1089.404785,2697.033447,19.442095 },
		{ "Suburban Havick", 134.122055,-200.211334,53.864090 },
		{ "Ponsonbys Burton", -148.234741,-308.074463,38.104240 },
		{ "Ponsonbys Rockford Hills", -725.551453,-162.833710,36.570301 },
		{ "Ponsonbys Morningwood", -1460.654419,-227.550964,48.728519 },
		{ "Suburban Del Perro", -1210.620361,-784.160217,16.549015 },
		{ "Masks Vespucci Beach", -1342.185913,-1280.013428,4.443256 },
		{ "Binco Vespucci", -814.432800,-1085.986938,10.567306 },
		{ "Binco Strawberry", 411.403564,-806.654907,28.742212 },
		{ "Strawberry", 89.320786,-1392.317627,28.800083 },
	};

	static struct {
		const char* Name;
		float X;
		float Y;
		float Z;
	} TPLocationsTS[6] = {
		{ "Paleto Bay", -285.910400,6202.941895,30.626459 },
		{ "Sandy Shores", 1853.771851,3746.440918,32.395195 },
		{ "Chumash", -3155.888672,1073.844482,20.188726 },
		{ "Vinewood", 318.228790,164.457535,103.146561 },
		{ "Vespucci", -1163.504639,-1413.232788,4.360025 },
		{ "El Burro Heights", 1318.160889,-1642.176147,51.787762 },
	};

	static struct {
		const char* Name;
		float X;
		float Y;
		float Z;
	} TPLocationsStores[9] = {
		{ "Banham Canyon", -3037.177246, 590.165283, 7.78449 },
		{ "Chumash", -3237.171387, 1004.163879, 12.354364 },
		{ "Grand Senora Desert", 2683.951172, 3281.507324, 55.347145 },
		{ "Harmony", 543.490784, 2675.008301, 42.162228 },
		{ "Mount Chiliad", 1730.461914, 6410.027344, 35.384476 },
		{ "Sandy Shores", 1966.198853, 3738.300537, 32.251864 },
		{ "Strawberry", 28.123456, -1351.123456, 29.123456 },
		{ "Tataviam Mountains", 2561.452881, 384.998932, 108.532890 },
		{ "Vinewood", 376.287079, 322.833252, 103.418564 },
	};

	static struct {
		const char* Name;
		float X;
		float Y;
		float Z;
	} TPLocationsAmmo[11] = {
		{ "Paleto Bay", -318.859039,6074.433105,30.614943 },
		{ "Sandy Shores", 1704.671997,3748.880615,33.286053 },
		{ "Great Chaparral", -1108.600830,2685.694092,18.177374 },
		{ "Chumash", -3155.888672,1073.844482,20.188726 },
		{ "Palomino Fwy", 2571.371826,313.879608,107.970573 },
		{ "Hawick", 235.666794,-42.263149,69.221313 },
		{ "Morningwood", -1328.592896,-387.114410,36.126881 },
		{ "Little Seoul", -665.232727,-952.522522,20.866556 },
		{ "La Mesa", 844.439026,-1009.422424,27.511728 },
		{ "Pillbox Hill", 17.377790,-1122.183105,28.469843 },
		{ "Cypress Flats", 814.442017,-2130.448486,28.867798 },
	};

	static struct {
		const char* Name;
		float X;
		float Y;
		float Z;
	} TPLocationsBS[6] = {
		{ "Paleto Bay", -286.639038,6239.389648,30.567659 },
		{ "Sandy Shores", 1938.357910,3717.808350,31.607185 },
		{ "Havick", -27.791309,-136.863708,56.515392 },
		{ "Rockford Hills", -829.426392,-191.582718,36.921909 },
		{ "Vespucci", -1294.995239,-1117.641724,6.157444 },
		{ "Mirror Park", 1198.025757,-471.814178,65.670250 },
	};

	static struct {
		const char* Name;
		float X;
		float Y;
		float Z;
	} TPLocationsAirport[7] = {
		{ "Los Santos Airport", -1070.906250,-2972.122803,13.773568 },
		{ "Flight School", -1142.084229,-2697.341553,13.324973 },
		{ "Sandy Shores", 1682.196411,3279.987793,40.647972 },
		{ "McKenzie Airfield", -1682.196411,3279.987793,40.647972 },
		{ "Fort Zancudo", -2446.711182,3142.811035,32.194775 },
		{ "Fort Zancudo Front", -1563.743286,2769.382080,16.819347 },
		{ "LS Airport Hangar", -978.708496,-3001.840820,13.317889 },
	};
}