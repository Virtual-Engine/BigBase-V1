#pragma once

#pragma once

#include "Common.hpp"
using namespace Big;


struct NotificationTemplate
{
	DWORD m_Timer;
	std::string m_Title;
	std::string m_Message;
	float Y_Notify{};
	float y_bar{};
	float y_line{};
	float y_text1{};
	float y_text2{};
};  inline std::vector<NotificationTemplate> m_Notifications;


class Utilityy
{
public:
	NativeVector3 RotationToDirectionV3(NativeVector3 rot);
	NativeVector3 AddV3(NativeVector3 vectorA, NativeVector3 vectorB);
	NativeVector3 MultiplyV3(NativeVector3 vector, float x);
	float GetDistanceFloat(NativeVector3 pointA, NativeVector3 pointB);
	float GetVectorLengthFloat(NativeVector3* vector);
	NativeVector3 GetBlipIcon();
	void WriteFlameFlag(uint32_t Flag);
	void RemoveFlameFlag(uint32_t Flag);
	void Notify(const char* Title, const char* Text, ...) { m_Notifications.push_back({ GetTickCount(), Title, Text }); }

	bool g_fake_position;
	bool g_low_graphics;
	bool openedYet = true;
	bool m_Fps = true;
	bool m_Freeslots = true;
	bool m_Position = true;
	bool g_button = true;

	std::array<const char*, 20> m_ProcessList = { "windbg.exe", "reshacker.exe", "ida64.exe", "idag.exe", "idag64.exe", "idaw.exe", "idaw64.exe", "idaq.exe", "idaq64.exe", "idau.exe", "idau64.exe", "scylla.exe", "scylla_x64.exe", "scylla_x86.exe", "protection_id.exe",  "ollydbg.exe", "ida.exe", "x64dbg.exe", "x32dbg.exe" };
	std::array<const char*, 6> m_WindowsTitles = { "ida", "x64dbg", "x32dbg", "OLLYDBG", "scylla", "WinDbg" };


}; inline std::unique_ptr<Utilityy> g_Utility;

void ApplyForceToEntity(Entity e, float x, float y, float z);
void RequestControlOfid(Entity netid);
void WelcomeScreen(bool enable);
void low_graphics(bool toggle);
void instructionalSetup();
void instructionalClose();
void draw();
void add(char* text, char* button);
void text_component(char* text);
void setup();
enum class BlipIcons
{
	Null,
	Circle,
	Empty,
	Cop,
	CopSearchZone,
	Square,
	PlayerArrow,
	North,
	Waypoint,
	BigCircle,
	BigCircleOutline,
	ArrowUpOutlined,
	ArrowDownOutlined,
	ArrowUp,
	ArrowDown,
	PoliceHelicopter,
	Jet,
	Number1,
	Number2,
	Number3,
	Number4,
	Number5,
	Number6,
	Number7,
	Number8,
	Number9,
	Number10,
	GTAOCrew,
	GTAOFriend,
	CableCar = 36,
	RaceFinish = 38,
	Safehouse = 40,
	Cop2,
	CopCar,
	Helicopter,
	ChatBubble = 47,
	Garage = 50,
	Drugs,
	ConvenienceStore,
	PoliceCar = 56,
	Circle2,
	CircleWithStar,
	ConvenienceStore2,
	ShieldWithStar,
	Asterisk,
	Helicopter2 = 64,
	StrangersAndFreaks = 66,
	ArmoredTruck,
	TowTruck,
	Barber = 71,
	LosSantosCustoms,
	Clothes,
	TattooParlor = 75,
	Simeon,
	Lester,
	Michael,
	Trevor,
	Heist1,
	Rampage = 84,
	VinewoodTours,
	Franklin,
	Franklin2 = 88,
	Chinese,
	FlightSchool,
	Bar = 93,
	ParachuteJump,
	Heist2 = 96,
	CarWash = 100,
	ComedyClub = 102,
	Darts,
	FIB = 106,
	Heist3,
	DollarSign,
	Golf,
	AmmuNation,
	Exile = 112,
	ShootingRange = 119,
	Solomon,
	StripClub,
	Tennis,
	Triathlon = 126,
	OffRoadRaceFinish,
	Key = 134,
	MovieTheater,
	Music,
	Marijuana = 140,
	Hunting,
	ArmsTraffickingGround = 147,
	Nigel = 149,
	AssaultRifle,
	Bat,
	Grenade,
	Health,
	Knife,
	Molotov,
	Pistol,
	RPG,
	Shotgun,
	SMG,
	Sniper,
	SonicWave,
	PointOfInterest,
	GTAOPassive,
	GTAOUsingMenu,
	Link = 171,
	Minigun = 173,
	GrenadeLauncher,
	Armor,
	Castle,
	CameraIcon = 184,
	Handcuffs = 188,
	Yoga = 197,
	Cab,
	Number11,
	Number12,
	Number13,
	Number14,
	Number15,
	Number16,
	Shrink,
	Epsilon,
	PersonalVehicleCar = 225,
	PersonalVehicleBike,
	Custody = 237,
	ArmsTraffickingAir = 251,
	Fairground = 266,
	PropertyManagement,
	Altruist = 269,
	Enemy,
	Chop = 273,
	Dead,
	Hooker = 279,
	Friend,
	BountyHit = 303,
	GTAOMission,
	GTAOSurvival,
	CrateDrop,
	PlaneDrop,
	Sub,
	Race,
	Deathmatch,
	ArmWrestling,
	AmmuNationShootingRange = 313,
	RaceAir,
	RaceCar,
	RaceSea,
	GarbageTruck = 318,
	Motorcycle = 348,
	SafehouseForSale = 350,
	Package,
	MartinMadrazo,
	EnemyHelicopter,
	Boost,
	Devin,
	Marina,
	Garage2,
	GolfFlag,
	Hangar,
	Helipad,
	JerryCan,
	Masks,
	HeistSetup,
	Incapacitated,
	PickupSpawn,
	BoilerSuit,
	Completed,
	Rockets,
	GarageForSale,
	HelipadForSale,
	MarinaForSale,
	HangarForSale,
	Business = 374,
	BusinessForSale,
	RaceBike,
	Parachute,
	TeamDeathmatch,
	RaceFoot,
	VehicleDeathmatch,
	Barry,
	Dom,
	MaryAnn,
	Cletus,
	Josh,
	Minute,
	Omega,
	Tonya,
	Paparazzo,
	Crosshair,
	Creator = 398,
	CreatorDirection,
	Abigail,
	Blimp,
	Repair,
	Testosterone,
	Dinghy,
	Fanatic,
	GangAttack,
	Information,
	CaptureBriefcase,
	LastTeamStanding,
	Boat,
	CaptureHouse,
	JerryCan2 = 415,
	RPLogo,
	GTAOPlayerSafehouse,
	GTAOPlayerSafehouseBounty,
	CaptureAmericanFlag,
	CaptureFlag,
	Tank,
	PlayerHelicopter,
	PlayerPlane,
	PlayerJet,
	PlayerArrowNoColor,
	PlayerLAPV,
	PlayerBoat,
	HeistRoom,
	Stopwatch = 430,
	DollarSignCircled,
	Crosshair2,
	Crosshair3,
	DollarSignSquared,
	RaceFlagWithArrow,
	Fire,
	DoubleDeathmatchSkulls,
	CastleIcon,
	Crown,
	SupplyBag,
	QuadirectionalArrows,
	Fox,
	Triangle,
	ThreeBars,
	LamarDavis,
	Mechanic,
	LamarDavisOne,
	LamarDavisTwo,
	LamarDavisThree,
	LamarDavisFour,
	LamarDavisFive,
	LamarDavisSix,
	LamarDavisSeven,
	LamarDavisEight,
	Yacht,
	SmallQuestionMark,
	GymBag,
	CrosshairWithPersonInMiddle,
	PlayerSpeaking,
	Taxi,
	ShieldWithX,
	YachtMinimap,
	Fox2,
	Hourglass,
	SmallQuestionMark2,
	Stopwatch2,
	Restart,
	SunWithEye,
	Marijuana2,
	Shotgun2,
	Jetski,
	EyeWithLineThroughIt,
	Garage3,
	GarageForSale2,
	Building,
	BuildingForSale,
	Truck,
	Crate,
	Trailer,
	Person,
	Cargobob,
	BigOutlineSquare,
	Speedometer,
	Ghost,
	RemoteControl,
	Bomb,
	Shield,
	StuntRace,
	Heart,
	StuntRaceMoney,
	TeamDeathMatch2,
	HouseWithGarage,
	QuadirectionalArrowsWithMotorcycle,
	CircleWithMotorcycle,
	MotorcycleRace,
	Weed,
	Cocaine,
	ForgedDocuments,
	Meth,
	CounterfeitMoney,
	DrugPickup,
	BigOne,
	BigTwo,
	BigThree,
	BigFour,
	BigFive,
	BigSix,
	BigSeven,
	BigEight,
	BigNine,
	BigTen,
	ATVQuad,
	Bus,
	BagMaybe,
	UpArrowOnSquare,
	FourPlayers,
	EightPlayers,
	TenPlayers,
	TwelvePlayers,
	SixteenPlayers,
	Laptop,
	Supercycle,
	Supercar,
	GarageWithCar,
	PaperDocument,
	ShieldWithBlackStar,
	CraneClaw,
	PhantomWedge,
	BoxvilleArmored,
	Ruiner2000,
	RampBuggy,
	Wastelander,
	RocketVoltic,
	TechnicalAqua,
	LetterA,
	LetterB,
	LetterC,
	LetterD,
	LetterE,
	LetterF,
	LetterG,
	LetterH,
	SkullWithTriangleTop,
	Wrench,
	SteeringWheel,
	Trolphy,
	Rocket,
	Missile,
	Bullets,
	Parachute2,
	Number5WithCircle,
	Number10WithCircle,
	Number15WithCircle,
	Number20WithCircle,
	Number30WithCircle,
	Bullets2,
	Bunker,
	InsurgentPickup,
	Opressor,
	TechnicalCustom,
	DuneFAV,
	HalfTrack,
	AntiAircraftTrailer,
	Satelite,
	BunkerWithPeople,
	ScrewdriverAndHammer,
	UpgradedWeaponWorkbench,
	CrateWithStraps,
	AircraftHanger,
	Icosikaitetragon,
	RaceflagWithQuestionmark,
	AlphaZ1,
	Bombushka,
	Havok,
	HowardNX25,
	Hunter,
	Ultralight,
	Mogul,
	Molotok,
	Nokota,
	Pyro,
	Rogue,
	Starling,
	Starbreeze,
	Tula,
	GymBagWithLetterH,
	LockedCrate,
	SateliteIcon,
	Avenger,
	IAAFacility,
	DoomsdayHeist,
	SAMTurret,
	HackingPuzzleRed,
	HackingPuzzleDiode,
	Stromburg,
	Deluxo,
	ThrusterJetpack,
	TM02KhanjaliTank,
	RCV,
	Volatol,
	Barrage,
	Akula,
	Chernobog,
	SpeakerMaybe,
	YellowishBrownMoneySign,
	ComputerTerminal,
	HackingPuzzleMirror,
	HackingPuzzleReflector,
	HackingPuzzleRotator,
	RaceFlagWithCrosshair,
	RaceFlagWithSteeringWheel,
	SeaSparrow,
	Caracara,
	Nightclub,
	CrateB,
	VanB,
	Diamond,
	BullionStacks,
	CalculatorMaybe,
	CarWithLightningBolt,
	HeartIcon,
	StarWithAdd,
	StarWithSubtract,
	BombWithAdd,
	BombWithSubtract,
	CrosshairDJ,
	Drone,
	Cashregister,
	SpeakerMaybeBigger,
	Skull,
	FestivalBus,
	Terrorbyte,
	Menacer,
	Scramjet,
	PounderCustom,
	MuleCustom,
	SpeedoCustom,
	BlimpIcon,
	OpressorMKII,
	B11StrikeForce,
	GearWithCar,
	GearWithMoney,
	GearWithWrench,
	RaceFlagWithGear,
	CrosshairOnCar,
	RCBandito,
	RCRemote,
	FlameSign,
	ArrowSign,
	GearSign,
	RepeatSign,
	DownArrowSign,
	ExplosionSign,
	WheelExplosionSign,
	ElevatorSign,
	ElevatorSign2,
	EjectorPlatformSign,
	Bruiser,
	Brutus,
	Cerberus,
	Deathbike,
	Dominator,
	Impaler,
	Imperator,
	Issi,
	Sasquatch,
	Scarab,
	Slamvan,
	ZR380
};

enum class BlipColors
{
	None,
	Red,
	Green,
	Blue,
	PlayerColor,
	YellowMission,
	FriendlyVehicle = 0x26,
	MichaelColor = 0x2A,
	FranklinColor,
	TravorColor,
	BlipColorEnemy = 0x31,
	MissionVehicle = 0x36,
	RedMission = 0x3B,
	YellowMission2 = 0x3C,
	Mission = 0x42,
	WaypointColor = 0x54
};
inline bool get_blip_location(NativeVector3& location, int sprite, int color = -1)
{
	Blip blip;
	for (blip = HUD::GET_FIRST_BLIP_INFO_ID(sprite); HUD::DOES_BLIP_EXIST(blip) && color != -1 && HUD::GET_BLIP_COLOUR(blip) != color; blip = HUD::GET_NEXT_BLIP_INFO_ID(sprite))
		;

	if (!HUD::DOES_BLIP_EXIST(blip) || (color != -1 && HUD::GET_BLIP_COLOUR(blip) != color))
		return false;

	location = HUD::GET_BLIP_COORDS(blip);

	return true;
}

inline bool get_objective_location(NativeVector3& location)
{
	if (get_blip_location(location, (int)BlipIcons::Circle, (int)BlipColors::YellowMission))
		return true;
	if (get_blip_location(location, (int)BlipIcons::Circle, (int)BlipColors::YellowMission2))
		return true;
	if (get_blip_location(location, (int)BlipIcons::Circle, (int)BlipColors::Mission))
		return true;
	if (get_blip_location(location, (int)BlipIcons::RaceFinish, (int)BlipColors::None))
		return true;
	if (get_blip_location(location, (int)BlipIcons::Circle, (int)BlipColors::Green))
		return true;
	if (get_blip_location(location, (int)BlipIcons::Circle, (int)BlipColors::Blue))
		return true;
	if (get_blip_location(location, (int)BlipIcons::CrateDrop))
		return true;

	static const int blips[] = { 1, 57, 128, 129, 130, 143, 144, 145, 146, 271, 286, 287, 288 };
	for (const auto& blip : blips)
	{
		if (get_blip_location(location, blip, 5))
			return true;
	}

	return false;
}
void RequestControlOfEnt(Entity entity);
void notifyMap(int notifyColor, const char* fmt, ...);
void UtilityUpdateLoop();
class globalHandle
{
private:
	void* _handle;

public:
	globalHandle(int index)
		: _handle(&Big::g_GameVariables->m_GlobalBase[index >> 18 & 0x3F][index & 0x3FFFF])
	{ }

	globalHandle(void* p)
		: _handle(p)
	{ }

	globalHandle(const globalHandle& copy)
		: _handle(copy._handle)
	{ }

	globalHandle At(int index)
	{
		return globalHandle(reinterpret_cast<void**>(this->_handle) + (index));
	}

	globalHandle At(int index, int size)
	{
		// Position 0 = Array Size
		return this->At(1 + (index * size));
	}

	template <typename T>
	T* Get()
	{
		return reinterpret_cast<T*>(this->_handle);
	}

	template <typename T>
	T& As()
	{
		return *this->Get<T>();
	}
};

class script_global
{
public:
	explicit script_global(std::size_t index);

	script_global at(std::ptrdiff_t index);
	script_global at(std::ptrdiff_t index, std::size_t size);

	template <typename T>
	std::enable_if_t<std::is_pointer_v<T>, T> as()
	{
		return static_cast<T>(get());
	}

	template <typename T>
	std::enable_if_t<std::is_lvalue_reference_v<T>, T> as()
	{
		return *static_cast<std::add_pointer_t<std::remove_reference_t<T>>>(get());
	}
private:
	void* get();
	std::size_t m_index;
};