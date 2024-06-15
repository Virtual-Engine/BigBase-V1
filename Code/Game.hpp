#pragma once
#include <inttypes.h>
#include <intrin.h>
#include <stdio.h>

inline std::vector<__int64> g_Rockets;

namespace rage
{
	struct scrNativeRegistration;
}

class CPlayerInfo
{
public:
	char pad_0000[32]; //0x0000
	uint32_t m_internal_ip; //0x0020
	uint16_t m_internal_port; //0x0024
	char pad_0026[2]; //0x0026
	uint32_t m_relay_ip; //0x0028
	uint16_t m_relay_port; //0x002C
	char pad_002E[66]; //0x002E
	uint32_t N00000124; //0x0070
	uint32_t m_external_ip; //0x0074
	uint16_t m_external_port; //0x0078
	char pad_007A[22]; //0x007A
	uint64_t m_rockstar_id; //0x0090
	char pad_0098[12]; //0x0098
	char sName[20]; //0x00A4
	char pad_00B8[184]; //0x00B8
	float m_swim_speed; //0x0170
	char pad_0174[165]; //0x0174
	uint32_t m_frame_flags; //0x0218
	char pad_021D[1644]; //0x021D
	int32_t m_wanted_level; //0x0888
	int32_t m_wanted_level_2; //0x088C
	char pad_0890[1120]; //0x0890
	float m_run_speed; //0x0CF0
	float m_stamina; //0x0CF4
	float m_stamina_regen; //0x0CF8
}; //Size=0x0C08

#pragma pack(push, 1)
#	pragma warning(push)
#	pragma warning(disable : 4201) // nonstandard extension used: nameless struct/union
union netAddress
{
	uint32_t m_raw;
	struct
	{
		uint8_t m_field4;
		uint8_t m_field3;
		uint8_t m_field2;
		uint8_t m_field1;
	};
};
#	pragma warning(pop)

class netPlayerData
{
public:
	char pad_0000[8]; //0x0000
	int64_t m_rockstar_id_0; //0x0008
	char pad_0010[56]; //0x0010
	uint16_t N000005BF; //0x0048
	char pad_004A[2]; //0x004A
	netAddress m_online_ip; //0x0054
	int16_t m_online_port; //0x0058
	netAddress m_relay_ip; //0x004C
	int32_t m_relay_port; //0x0050
	char pad_005A[6]; //0x005A
	uint32_t m_host_token; //0x0060
	char pad_0064[12]; //0x0064
	int64_t m_rockstar_id; //0x0070
	char pad_0078[12]; //0x0078
	const char* m_name; //0x0084
}; //Size: 0x0098


class netPlayer
{
public:
	virtual ~netPlayer() = default;            // 0 (0x00)
	virtual void reset() = 0;                  // 1 (0x08)
	virtual bool is_valid() const = 0;         // 2 (0x10)
	virtual const char* get_name() const = 0;  // 3 (0x18)
	virtual void _0x20() = 0;                  // 4 (0x20)
	virtual bool is_host() = 0;                // 5 (0x28)
	virtual netPlayerData* get_net_data() = 0; // 6 (0x30)
	virtual void _0x38() = 0;                  // 7 (0x38)
};

class CNetGamePlayers : public netPlayer
{
public:
	char pad_0x0008[0x10]; //0x0008
	std::uint32_t msg_id; // 0x18
	char pad_0x001C[0x4]; //0x001C
	std::int8_t active_id; //0x0020 
	std::int8_t m_player_id; //0x0021 
	char pad_0x0022[0x6E]; //0x0022
	BYTE local_player_check;//0x0090
	char pad_0x00A1[0xF]; //0x0091
	CPlayerInfo* PlayerInfo; //0x00A0

	inline bool is_local_player()
	{
		return local_player_check & 1;
	}
};
enum eThreadState
{
	ThreadStateIdle = 0x0,
	ThreadStateRunning = 0x1,
	ThreadStateKilled = 0x2,
	ThreadState3 = 0x3,
	ThreadState4 = 0x4,
};

class scrThreadContext
{
public:
	int ThreadID;
	int ScriptHash;
	eThreadState State;
	int _IP;
	int FrameSP;
	int _SPP;
	float TimerA;
	float TimerB;
	int TimerC;
	int _mUnk1;
	int _mUnk2;
	int _f2C;
	int _f30;
	int _f34;
	int _f38;
	int _f3C;
	int _f40;
	int _f44;
	int _f48;
	int _f4C;
	int _f50;
	int pad1;
	int pad2;
	int pad3;
	int _set1;
	int pad[17];
};

class tlsContext;

class datBase
{
public:
	virtual ~datBase() = default;
};

class pgBase
{
public:
	virtual ~pgBase() = default;
private:
	void* m_pgunk;
};

template <typename T, typename Base = datBase>
class atDNode : public Base
{
public:
	T m_data;
	void* m_unk;
	atDNode<T, Base>* m_next;
};

template <typename Node>
class atDList
{
public:
	Node* m_head;
	Node* m_tail;
};

class scriptResource
{
public:
	virtual ~scriptResource() = default;
};

class scriptHandlerObject;

class netLoggingInterface;

class scriptIdBase
{
public:
	virtual ~scriptIdBase() = default;                            // 0 (0x00)

	// Assumes the script thread's identity.
//	virtual void assume_thread_identity(scrThread*) {};           // 1 (0x08)

	// Returns whether the hash of the script id is valid.
	virtual bool is_valid() {};                                   // 2 (0x10)

	// Gets the hash of the script id.
	virtual uint32_t* get_hash(uint32_t* out) {};                 // 3 (0x18)

	// Gets an unknown value from the script id.
	virtual std::uint32_t* get_hash2(std::uint32_t* out) {};      // 4 (0x20)

	// Gets the name of the script id.
	virtual const char* get_name() {};                            // 5 (0x28)

	// Calculates some information with the position hash & instance id.
	virtual std::uint32_t _0x40() {};                             // 8 (0x40)

	// Calls _0x40 and returns it's value added to another value.
	virtual std::uint32_t _0x48() {};                             // 9 (0x48)

	// Logs some information about the script id.
	virtual void log_information(netLoggingInterface* logger) {}; // 10 (0x50)

	// Copies the information of other to this object.
	virtual void copy_data(scriptIdBase* other) {}                // 11 (0x58)

	// Returns whether the other script id is equal.
	virtual bool operator==(scriptIdBase*) {};                    // 12 (0x60)

	virtual bool _0x68(void*) {};                                 // 13 (0x68)
};

class scriptId : public scriptIdBase
{
public:
	uint32_t m_hash;          // 0x08
	char m_name[0x20];        // 0x0C
};

class scriptHandler;

class scriptHandlerMgr
{
public:
	virtual ~scriptHandlerMgr() = default;

	// Initializes some scripting-related pools.
	virtual bool initialize() = 0;                                                          // 1 (0x08)

	// Called every tick.
	virtual void _0x10() = 0;                                                               // 2 (0x10)

	// Frees some scripting-related pools.
	virtual void shutdown() = 0;                                                            // 3 (0x18)

	virtual void _0x20() = 0;                                                               // 4 (0x20)
	virtual void _0x28() = 0;                                                               // 5 (0x28)
	virtual void _0x30() = 0;                                                               // 6 (0x30)

	// Generates a rage::scriptId from the thread and copies it over to a global structure.

	// Allocates and constructs a script handler.
	virtual scriptHandler* create_script_handler() = 0;                                     // 8 (0x40)

	// Finds the script handler for a given script id.
	virtual scriptHandler* get_script_handler(scriptId*) = 0;                               // 9 (0x48)

	// Attaches a script thread.
									   // 10 (0x50)

	// Detaches a script thread.

	// Called when a player joins.
	virtual void on_player_join(netPlayer*) = 0;                                            // 12 (0x60)

	// Called when a player leaves.
	virtual void on_player_left(netPlayer*) = 0;                                            // 13 (0x68)

	virtual std::int32_t _0x70() = 0;                                                       // 14 (0x70)
	virtual void* _0x78() = 0;                                                              // 15 (0x78)
public:
	char m_padding1[0x28];                         // 0x08
	bool m_initialized;                            // 0x30
	bool m_initialized2;                           // 0x31
	char m_padding2[0x0E];                         // 0x32
	netLoggingInterface* m_logger;				   // 0x40
};

class CGameScriptHandlerMgr : public scriptHandlerMgr
{
};

class scriptHandlerNetComponent
{
public:
	virtual ~scriptHandlerNetComponent() = default;

	scriptHandler* m_script_handler; // 0x08
};

class scriptHandler
{
public:
	class atDScriptObjectNode : public atDNode<scriptHandlerObject*>
	{
	};
public:
	virtual ~scriptHandler() = default;                                                                   //  0 (0x00)

	virtual bool _0x08() = 0;                                                                             //  1 (0x08)

	virtual void _0x10() = 0;                                                                             //  2 (0x10)

	virtual void cleanup_objects() = 0;                                                                   //  3 (0x18)

	virtual scriptId* _0x20() = 0;                                                                        //  4 (0x20)

	virtual scriptId* get_id() = 0;                                                                       //  5 (0x28)

	// Returns whether the script handler belongs to a networked script.
	virtual bool is_networked() = 0;                                                                      //  6 (0x30)

	// Initializes the network component for the script handler.
	virtual void init_net_component() = 0;                                                                //  7 (0x38)

	// Deletes the script handler's network component, if it exists.
	virtual void reset_net_component() = 0;                                                               //  8 (0x40)

	// Destroys the script handler.
	virtual bool destroy() = 0;                                                                           //  9 (0x48)

	// Adds the object to the script handler's list of objects.
	virtual void add_object(scriptHandlerObject*, bool is_network, bool is_network_and_scriptcheck) = 0; // 10 (0x50)

	// Something related to reservations.
	virtual void _0x58(void*) = 0;                                                                        // 11 (0x58)

	virtual void register_resource(scriptResource*, void*) = 0;                                           // 12 (0x60)

	virtual void _0x68() = 0;                                                                             // 13 (0x68)

	virtual void _0x70() = 0;                                                                             // 14 (0x70)

	virtual void _0x78() = 0;                                                                             // 15 (0x78)

	virtual void _0x80() = 0;                                                                             // 16 (0x80)

	virtual void _0x88() = 0;                                                                             // 17 (0x88)

	virtual void _0x90() = 0;                                                                             // 18 (0x90)

	virtual void _0x98() = 0;                                                                             // 19 (0x98)
public:
	void* m_0x08;                                // 0x08
	void* m_0x10;                                // 0x10
	atDNode<atDScriptObjectNode> m_objects;      // 0x20
	scriptResource* m_resource_list_head;        // 0x30
	scriptResource* m_resource_list_tail;        // 0x38
	void* m_0x40;                                // 0x40
	scriptHandlerNetComponent* m_net_component;  // 0x48
	std::uint32_t m_0x50;                        // 0x50
	std::uint32_t m_0x54;                        // 0x54
	std::uint32_t m_0x58;                        // 0x58
	std::uint32_t m_0x60;                        // 0x5C
};






class CGameScriptId : public scriptId
{
public:
	char m_padding[0x04];         // 0x2C
	std::int32_t m_timestamp;     // 0x30
	std::int32_t m_position_hash; // 0x34
	std::int32_t m_instance_id;   // 0x38
	std::int32_t m_unk;           // 0x3C
};

class CGameScriptHandler : public scriptHandler
{
public:
	CGameScriptId m_script_id; // 0x60
};


class scrThread
{
public:
	virtual ~scrThread() = default;                                                                 // 0 (0x00)
	virtual void reset(std::uint32_t script_hash, void* args, std::uint32_t arg_count) = 0;         // 1 (0x08)
	virtual eThreadState run() = 0;                                                                 // 2 (0x10)
	virtual eThreadState tick(std::uint32_t ops_to_execute) = 0;                                    // 3 (0x18)
	virtual void kill() = 0;                                                                        // 4 (0x20)

	static scrThread* get()
	{
		return reinterpret_cast<scrThread*>(*(reinterpret_cast<int**>(__readgsqword(0x58)) + 0x830));
	}
public:
	scrThreadContext m_context;                 // 0x08
	void* m_stack;                              // 0xB0
	char m_padding[0x10];                       // 0xB8
	const char* m_exit_message;                 // 0xC8
	char m_name[0x40];                          // 0xD0
	scriptHandler* m_handler;                   // 0x110
	scriptHandlerNetComponent* m_net_component; // 0x118
};

class ScriptThread : scrThread
{
public:
	const char Name[64];
	void* m_pScriptHandler;
	const char gta_pad2[40];
	const char flag1;
	const char m_networkFlag;
	bool bool1;
	bool bool2;
	bool bool3;
	bool bool4;
	bool bool5;
	bool bool6;
	bool bool7;
	bool bool8;
	bool bool9;
	bool bool10;
	bool bool11;
	bool bool12;
	const char gta_pad3[10];
};

class GtaThread : public scrThread
{
public:
	uint32_t m_script_hash;						// 0x120
	char m_padding3[0x14];                      // 0x124
	std::int32_t m_instance_id;                 // 0x138
	char m_padding4[0x04];                      // 0x13C
	std::uint8_t m_flag1;                       // 0x140
	bool m_safe_for_network_game;               // 0x141
	char m_padding5[0x02];                      // 0x142
	bool m_is_minigame_script;                  // 0x144
	char m_padding6[0x02];                      // 0x145
	bool m_can_be_paused;                       // 0x147
	bool m_can_remove_blips_from_other_scripts; // 0x148
	char m_padding7[0x0F];                      // 0x149
};

template <typename T>
class atArrayBig
{
public:
	T* begin()
	{
		return m_data;
	}

	T* end()
	{
		return m_data + m_size;
	}

	const T* begin() const
	{
		return m_data;
	}

	const T* end() const
	{
		return m_data + m_size;
	}

	T* data()
	{
		return m_data;
	}

	const T* data() const
	{
		return m_data;
	}

	std::uint16_t size() const
	{
		return m_size;
	}

	std::uint16_t capacity() const
	{
		return m_capacity;
	}

	T& operator[](std::uint16_t index)
	{
		return m_data[index];
	}

	const T& operator[](std::uint16_t index) const
	{
		return m_data[index];
	}
private:
	T* m_data;
	std::uint16_t m_size;
	std::uint16_t m_capacity;
};

enum class NetObjEntityType
{
	Automobile = 0,
	Bike = 1,
	Boat = 2,
	Door = 3,
	Heli = 4,
	Object = 5,
	Ped = 6,
	Pickup = 7,
	PickupPlacement = 8,
	Plane = 9,
	Submarine = 10,
	Player = 11,
	Trailer = 12,
	Train = 13,
	Max = 14
};

class fwEntity
{
public:
	char pad_0000[32]; //0x0000
	void* m_model_info; //0x0020
	int8_t m_invisible; //0x0028
	char pad_0029[7]; //0x0029
	void* m_navigation; //0x0030
	char pad_0038[1]; //0x0038
	int8_t m_entity_type; //0x0039
	char pad_003A[150]; //0x003A
	void* m_net_object; //0x00D0
	char pad_00D8[176]; //0x00D8
	uint32_t m_damage_bits; //0x0188
}; //Size: 0x018C
//static_assert(sizeof(fwEntity) == 0x18C, "fwEntity is not properly sized");

struct netObject
{
	char pad[64]; // +0
	uint16_t objectType; // +64
	uint16_t objectId; // +66
	char pad2[3]; // +68 
	bool isRemote; // +71
	char pad3[16]; // +72
	fwEntity* gameObject; // +88
};

class netSyncTree
{
public:
	virtual ~netSyncTree() = 0;

	virtual void WriteTree(int flags, int objFlags, netObject* object, void* buffer, uint32_t time, void* logger, uint8_t targetPlayer, void* outNull) = 0;

	virtual void ApplyToObject(netObject* object, void*) = 0;

	virtual void m_18() = 0;

	virtual void m_20(uint32_t, uint32_t, void*, void*) = 0;

	virtual void m_28() = 0;

	virtual void m_30() = 0;

	virtual void m_38() = 0;

	virtual void m_40() = 0;

	virtual void m_48() = 0;

	virtual void m_50() = 0;

	virtual void m_58() = 0;

	virtual void m_60(netObject* object, void*, uint8_t) = 0;

	virtual void m_68() = 0;

	virtual void m_70() = 0;

	virtual void m_78() = 0;

	virtual void m_80() = 0;

	virtual void m_88() = 0;

	virtual void m_90() = 0;

	virtual void m_98() = 0;

	virtual void m_A0() = 0;

	virtual void m_A8() = 0;

	virtual void m_B0() = 0;

	virtual void m_B8() = 0;

	virtual void m_C0() = 0;

	virtual void m_C8() = 0;

	virtual bool m_D0(int) = 0;

	virtual void m_D8() = 0;

public:
	bool CanApplyToObject(netObject* object);

	bool WriteTreeCfx(int flags, int objFlags, netObject* object, void** buffer, uint32_t time, void* logger, uint8_t targetPlayer, void* outNull, uint32_t* lastChangeTime);

	void AckCfx(netObject* object, uint32_t timestamp);

	/*inline void WriteTreeCfx(int flags, int objFlags, netObject* object, netBuffer* buffer, uint32_t time, void* logger, uint8_t targetPlayer, void* outNull)
	{
		WriteTree(flags, objFlags, object, buffer, time, logger, targetPlayer, outNull);
	}*/

public:
	static netSyncTree* GetForType(NetObjEntityType type);
};

class netPlayerMgrBase
{
public:
	char pad[232 - 8];
	CNetGamePlayers* localPlayer;

public:
	virtual ~netPlayerMgrBase() = 0;

	virtual void Initialize() = 0;

	virtual void Shutdown() = 0;

	virtual void m_18() = 0;

private:
	virtual CNetGamePlayers* AddPlayer_raw(void* scInAddr, void* unkNetValue, void* addedIn1290, void* playerData, void* nonPhysicalPlayerData) = 0;

public:


	virtual void RemovePlayer(CNetGamePlayers* player) = 0;
};

class CVehicle
{
public:
	char pad_0x0000[0x30]; //0x0000
	//CNavigation* pCNavigation; //0x0030 
	char pad_0x0038[0x10]; //0x0038
	//CVehicleMods* pCVehicleMods; //0x0048 
	char pad_0x0050[0x40]; //0x0050
	//	Vector3 v3VisualPos; //0x0090 
	char pad_0x009C[0x3C]; //0x009C
	BYTE btState; //0x00D8 
	char pad_0x00D9[0xB0]; //0x00D9
	BYTE btGodMode; //0x0189 
	char pad_0x018A[0xF6]; //0x018A
	float fHealth; //0x0280 
	char pad_0x0284[0x1C]; //0x0284
	float fHealthMax; //0x02A0 
	char pad_0x02A4[0x4]; //0x02A4
	//CAttacker* pCAttacker; //0x02A8 
	char pad_0x02B0[0x6A]; //0x02B0
	BYTE btVolticRocketState; //0x031A 
	char pad_0x031B[0x1]; //0x031B
	float fVolticRocketEnergy; //0x031C 
	char pad_0x0320[0x430]; //0x0320
	//Vector3 v3Velocity; //0x0750 
	char pad_0x075C[0xF0]; //0x075C
	float fHealth2; //0x084C 
	char pad_0x0850[0x28]; //0x0850
	//CVehicleHandling* pCVehicleHandling; //0x0878 
	char pad_0x0880[0x3]; //0x0880
	BYTE btBulletproofTires; //0x0883 
	char pad_0x0884[0x4]; //0x0884
	BYTE btStolen; //0x0888 
	char pad_0x0889[0x11]; //0x0889
	BYTE N00000954; //0x089A 
	char pad_0x089B[0x41]; //0x089B
	float N0000081E; //0x08DC 
	char pad_0x08E0[0x58]; //0x08E0
	float fDirtLevel; //0x0938			max = 15.f
	char pad_0x093C[0xA8]; //0x093C
	DWORD dwCarAlarmLength; //0x09E4 
	char pad_0x09E8[0x148]; //0x09E8
	BYTE btOpenableDoors; //0x0B30 
	char pad_0x0B31[0x4B]; //0x0B31
	float fGravity; //0x0B7C
	BYTE btMaxPassengers; //0x0B80 
	char pad_0x0B81[0x1]; //0x0B81
	BYTE btNumOfPassengers; //0x0B82 
	char pad_0x0B83[0x3D]; //0x0B83

	bool isGod()
	{
		return (btGodMode & 0x01) ? true : false;
	}

	bool hasBulletproofTires()
	{
		return (btBulletproofTires & 0x20) ? true : false;
	}

	bool disabledDoors()
	{
		return (btOpenableDoors == 0) ? true : false;
	}

	void giveHealth()
	{
		if (fHealth < fHealthMax)
			fHealth = fHealthMax;
		if (fHealth2 < fHealthMax)
			fHealth2 = fHealthMax;
	}

	//btState & 7    0 = inside of vehicle, 2 = outside of vehicle, 3 = vehicle blown up
	bool isVehicleDestroyed()
	{
		return (btState & 7) == 3;
	}

	void set_stolen(bool toggle)
	{
		this->btStolen &= 0xFEu;
		this->btStolen |= toggle & 1;
	}
}; //Size=0x0BC0

class CVehHandle
{
public:
	CVehicle* pCVehicle; //0x0000 
	__int32 iHandle;
	char _pad0[0x4];

}; //Size=0x0010

class CVehList
{
public:
	CVehHandle vehs[300]; //0x0000 

}; //Size=0x1000

class CVehicleInterface
{
public:
	char pad_0x0000[0x180]; //0x0000
	CVehList* VehList; //0x0180 
	__int32 iMaxVehicles; //0x0188 
	char pad_0x018C[0x4]; //0x018C
	__int32 iCurVehicles; //0x0190 
	char pad_0x0194[0x74]; //0x0194

	CVehicle* get_vehicle(const int& index)
	{
		if (index < iMaxVehicles)
			return VehList->vehs[index].pCVehicle;
		return nullptr;
	}
}; //Size=0x0208


class CReplayInterface
{
public:
	void* N000006F5; //0x0000 
	//CCameraInterface* pCCameraInterface; //0x0008 
	CVehicleInterface* pCVehicleInterface; //0x0010 
	//CPedInterface* pCPedInterface; //0x0018 
	//CPickupInterface* pCPickupInterface; //0x0020 
	//CObjectInterface* pCObjectInterface; //0x0028 

}; //Size=0x0030

namespace Big
{
	class GameVariables
	{
	public:
		explicit GameVariables();
		~GameVariables() noexcept = default;
		GameVariables(GameVariables const&) = delete;
		GameVariables(GameVariables&&) = delete;
		GameVariables& operator=(GameVariables const&) = delete;
		GameVariables& operator=(GameVariables&&) = delete;

		void PostInit();
		//int get_gtav_version();
		uint64_t m_WorldPtr;
		std::uint32_t* m_GameState;
		std::uint32_t* m_FrameCount;
		HWND m_GameWindow;
		IDXGISwapChain* m_Swapchain;
		rage::scrNativeRegistration** m_NativeRegistrations;
		std::uint64_t** m_GlobalBase;
		char* m_GameBuild;
		char m_OriginalNativeRetn[2];

		PVOID m_NativeReturn;
	};

	class GameFunctions
	{
	public:
		explicit GameFunctions();
		~GameFunctions() noexcept = default;
		GameFunctions(GameFunctions const&) = delete;
		GameFunctions(GameFunctions&&) = delete;
		GameFunctions& operator=(GameFunctions const&) = delete;
		GameFunctions& operator=(GameFunctions&&) = delete;


		uint64_t m_DistanceToSun;
		uint64_t m_Saturation;
		uint64_t m_Fog; //0.00009999999747
		uint64_t m_SkyIntensity;
		std::uintptr_t m_WaterQuads;

		char* m_WeatherBypass;
		char* m_WeatherBypass2;
		char* m_WeatherBypass3;
		char* m_WeatherBypass4;
		char* m_WeatherBypass5;
		char* m_WeatherBypass6;
		char* m_WeatherBypass7;
		char* m_WeatherBypass8;
		char* m_WeatherBypass9;

		std::int64_t** m_ScriptGlobals;

		using presence_game_invite = __int64* (__int64* a1, __int64* a2, __int64 a3);
		presence_game_invite* m_presence_game_invite;

		using PointerToHandle = std::int32_t(uint64_t entity);
		PointerToHandle* m_PointerToHande;

		CReplayInterface* replay_interface;

		using ChatTest = void(__int64 a1, __int64 a2, __int64 PlayerMaybe, __int64 a4, char a5);
		ChatTest* m_ChatTest;
		//00 00 7a ? 00 00 80 3f ? 00 80 ? ? ? ? 3e 9a

		using IsDlcPresent = bool(std::uint32_t hash);
		IsDlcPresent* m_IsDlcPresent;

		using WndProc = LRESULT(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		WndProc* m_WndProc;

		using GetEventData = bool(std::int32_t eventGroup, std::int32_t eventIndex, std::int64_t* args, std::uint32_t argCount);
		GetEventData* m_GetEventData;

		using GetLabelText = const char* (void* unk, const char* label);
		GetLabelText* m_GetLabelText;

		using AssignPhysicalIndexHandler = __int64(void* NetworkPlayerMgr, uint8_t* NetGamePlayer, uint8_t NewIndex);
		AssignPhysicalIndexHandler* m_AssignPhysicalIndexHandler;

		using CPlayerWildCard = __int64* (std::int32_t friendindex);
		CPlayerWildCard* m_PlayerWildcard;
		using CPlayerListMenuConstructor = __int64(__int64 a1, __int64 a2, __int64 a3);
		CPlayerListMenuConstructor* m_PlayerListMenuConstructor;

		using TriggerScriptEvent = int(bool unk0, uint64_t* args, int32_t argCount, int32_t bitFlags);
		TriggerScriptEvent* m_Triggerscriptevent;

		/*using GetPlayerNetworkIds = CNetGamePlayers * (int player);
		GetPlayerNetworkIds* m_GetPlayerNetworkId;

		using GetNetPlayer = CNetGamePlayers * (int32_t index);
		GetNetPlayer* m_GetNetPlayer;*/

		netPlayerMgrBase** m_NetworkPlayerManager{};

		using ScriptedGameEventSig = bool(void* events, CNetGamePlayers* SourcePlayer, CNetGamePlayers* ReceivingPlayer);
		ScriptedGameEventSig* m_ScriptedGameEvent;

		using NetworkHandler = void(__int64 a1, __int64 a2, __int64 a3, unsigned __int16 a4, int a5, int a6, __int64 a7, __int64 a8);
		NetworkHandler* m_NetworkEvents;

		using TransactionBlock = void(char* entryHeader, char* entryLine1, int instructionalKey, char* entryLine2, BOOL p4, std::uint32_t p5, std::uint32_t* p6, std::uint32_t* p7, BOOL background);
		TransactionBlock* m_TransactionError;

		using ModelMgr = __int64(__int64 a1, DWORD* a2);
		ModelMgr* m_ModelInfo;

		using BypassChat = int(__int64 ChatType, const char* Input, const char** Output);
		BypassChat* m_BypassChat;

		//using GetEntityFromScriptGuild = double(std::int32_t player);
		//GetEntityFromScriptGuild* m_GetEntityFromScriptGuild;

		using SendCloneSync = void(uint64_t a1, __int64 net_game_player, uint64_t net_obj, uint64_t a4, uint64_t a5, bool a6);
		SendCloneSync* m_SendCloneSync;

		using ProcessNetObject = bool(uint64_t sync_tree, uint64_t net_obj);
		ProcessNetObject* m_ProcessNetObject;
		//E8 ? ? ? ? 84 C0 75 1C C6 44 AE ptr.add(1).rip().as<fpProcessNetObject>();

		using SendNetInfoo = bool(netPlayerData* player, __int64 a2, __int64 a3, DWORD* a4);
		SendNetInfoo* m_SendNetInfo;

		using ForceHostOfScript = void* (scriptHandlerNetComponent* component, CNetGamePlayers* id);
		ForceHostOfScript* m_ForceHostOfScript;
		atArrayBig<GtaThread*>* gta_threads;
		uintptr_t small_host_token_patch;

		using GetHostOfScript = CNetGamePlayers * (std::int32_t player);
		GetHostOfScript* m_GetHostOfScript;

		using netObjCanApplyToObject = bool(netSyncTree* self, netObject* obj);
		netObjCanApplyToObject* m_CanApplyToObject;

		using WriteSyncDataString = bool(void* sync_data, const char* input, std::size_t length);
		netObjCanApplyToObject* m_WriteSyncDataString;

		using GetSyncTreeFromCloneType = std::uint64_t(std::uint64_t networkobjectmgr, std::uint16_t clonetype);
		GetSyncTreeFromCloneType* m_GetSyncTreeFromCloneType;

		using ChatMessage = void(void* thisptr, __int64  unk1, __int64 unk2, const char* message);
		ChatMessage* m_ChatMessage;

		using ChatSender = CNetGamePlayers * (__int64 player);
		ChatSender* m_ChatSender;

		using PickupRewardMoneyIsApplicableToPlayer = bool(void* thisptr, void* unk, void* ped);
		PickupRewardMoneyIsApplicableToPlayer* m_PickupRewardMoneyIsApplicableToPlayer;

		

		uint8_t incompatible_version;

	};

	inline std::unique_ptr<GameVariables> g_GameVariables;
	inline std::unique_ptr<GameFunctions> g_GameFunctions;
}
