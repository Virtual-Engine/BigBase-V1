#pragma once
#include "VMTHook.hpp"
#include "Game.hpp"

namespace Big
{
	inline bool m_EnableSCIDJoiner;
	inline __int64 m_SCIDJoiner;
	inline __int64 m_PlayerListPointer;

	class datBitBuffer
	{
	public:
		inline datBitBuffer(void* data, uint32_t size)
		{
			m_data = data;
			m_f8 = 0;
			m_maxBit = size * 8;
			m_bitsRead = 0;
			m_curBit = 0;
			m_unk2Bit = 0;
			m_flagBits = 0;
		}

		inline uint32_t GetPosition()
		{
			return m_bitsRead;
		}

		inline bool Seek(uint32_t bits)
		{
			if (bits >= 0)
			{
				uint32_t length = (m_flagBits & 1) ? m_maxBit : m_curBit;

				if (bits <= length)
				{
					m_bitsRead = bits;
				}
			}

			return false;
		}

		inline int GetDataLength()
		{
			int leftoverBit = (m_curBit % 8) ? 1 : 0;

			return (m_curBit / 8) + leftoverBit;
		}

		inline bool ReadByte(uint8_t* integer, int bits)
		{
			/*
			uint32_t read;
			if (big::g_pointers->m_read_bitbuf_dword(this, &read, bits))
			{
				*integer = read;
				return true;
			}
			return false;
			*/
		}

		inline bool ReadWord(uint16_t* integer, int bits)
		{
			/*
			uint32_t read;
			if (big::g_pointers->m_read_bitbuf_dword(this, &read, bits))
			{
				*integer = read;
				return true;
			}
			return false;
			*/
		}

		inline bool ReadDword(uint32_t* integer, int bits)
		{
			//return big::g_pointers->m_read_bitbuf_dword(this, integer, bits);
		}

		inline bool ReadInt32(int32_t* integer, int bits)
		{
			int32_t v8;
			int32_t v9;
			if (ReadDword((uint32_t*)&v8, 1u) && ReadDword((uint32_t*)&v9, bits - 1))
			{
				*integer = v8 + (v9 ^ -v8);
				return true;
			}
			return false;
		}

		inline bool ReadQWord(uint64_t* integer, int bits)
		{
			if (bits <= 32)
			{
				uint32_t v10{};
				if (ReadDword(&v10, bits))
				{
					*integer = v10;
					return true;
				}
				return false;
			}
			else
			{
				uint32_t v10{}, v11{};
				if (ReadDword(&v11, 32u) && ReadDword(&v10, bits - 32u))
				{
					*integer = v11 | ((uint64_t)v10 << 32);
					return true;
				}
				return false;
			}
		}

		inline bool ReadInt64(int64_t* integer, int bits)
		{
			uint32_t v8;
			uint64_t v9;
			if (ReadDword(&v8, 1u) && ReadQWord(&v9, bits - 1))
			{
				*integer = v8 + (v9 ^ -(int64_t)v8);
				return true;
			}
			return false;
		}

		inline bool ReadArray(PVOID array, int size)
		{
			//return big::g_pointers->m_read_bitbuf_array(this, array, size, 0);
		}

	public:
		void* m_data; //0x0000
		uint32_t m_f8; //0x0008
		uint32_t m_maxBit; //0x000C
		uint32_t m_bitsRead; //0x0010
		uint32_t m_curBit; //0x0014
		uint32_t m_unk2Bit; //0x0018
		uint8_t m_flagBits; //0x001C
		char pad_0x01D[3];
		uint32_t m_f20;
	};

	struct Hooks
	{
		static __int64* game_invite(__int64* a1, __int64* a2, __int64 a3);
		static void ChatMessage(void* thisptr, __int64 unk1, __int64 unk2, const char* message);
		static bool SendNetInfo(netPlayerData* player, __int64 a2, __int64 a3, DWORD* a4);
		static bool PickupRewardMoneyIsApplicableToPlayer(void* thisptr, void* unk, void* ped);
		static bool CanApplyToObject(netSyncTree* self, netObject* obj);
		static bool IsDlcPresent(std::uint32_t hash);
		static const char* GetLabelText(void* unk, const char* label);
		static bool GetEventData(std::int32_t eventGroup, std::int32_t eventIndex, std::int64_t* args, std::uint32_t argCount);
		static void pls(__int64 a1, __int64 a2, __int64 PlayerMaybe, __int64 a4, char a5);
		static LRESULT WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		static void TransactionErrorHandler(char* entryHeader, char* entryLine1, int instructionalKey, char* entryLine2, BOOL p4, Any p5, Any* p6, Any* p7, BOOL background);
		static void SendCloneSync(uint64_t a1, __int64 net_game_player, uint64_t net_obj, uint64_t a4, uint64_t a5, bool a6);
		static bool ProcessNetObject(std::uint64_t sync_tree, std::uint64_t net_obj);
		static bool WriteSyncDataString(void* sync_data, const char* input, std::size_t length);
		static int IncrementStatEvent(__int64 neteventclass, CNetGamePlayers* Source);
		static void NetworkEventHandler(__int64 a1, CNetGamePlayers* a2, CNetGamePlayers* a3, unsigned __int16 a4, int a5, int a6, __int64 a7, __int64 a8);
		static __int64* PlayerWildCardHandler(std::int32_t friendIndex);
		static __int64 CPlayerListMenuConstructor(__int64 a1, __int64 a2, __int64 a3);
		static bool ScriptedGameEvent(void* events, CNetGamePlayers* SourcePlayer, CNetGamePlayers* ReceivingPlayer);
		static 	__int64 GetModelInfo(__int64 a1, DWORD* a2);
		static int ChatBypassHook(__int64 ChatType, const char* Input, const char** Output);

		static constexpr auto PresentIndex = 8;
		static HRESULT Present(IDXGISwapChain* dis, UINT syncInterval, UINT flags);

		static constexpr auto ResizeBuffersIndex = 13;
		static HRESULT ResizeBuffers(IDXGISwapChain* dis, UINT bufferCount, UINT width, UINT height, DXGI_FORMAT newFormat, UINT swapChainFlags);

		//static void* AssignNewPhysicalIndexHandler(void* NetworkPlayerMgr, CNetGamePlayers* NetGamePlayer, uint8_t NewIndex);
		void BlockInvalidObjects();
	};

	class Hooking
	{
	public:
		explicit Hooking();
		~Hooking() noexcept;
		Hooking(Hooking const&) = delete;
		Hooking(Hooking&&) = delete;
		Hooking& operator=(Hooking const&) = delete;
		Hooking& operator=(Hooking&&) = delete;

		void Hook();
		void Unhook();

		friend struct Hooks;
	private:
		void* m_NtQueryVirtualMemory{};

		void* m_OriginalIsDlcPresent{};
		void* m_OriginalGetLabelText{};
		void* m_OriginalGetEventData{};
		void* m_OriginalAssignPhysicalIndex{};
		void* aaaaaaa{};
		void* m_OriginalWndProc{};
		void* m_OriginalJoinSessionHook{};
		void* m_OriginalRIDFunction{};
		void* m_OriginalSendNetInfo{};
		void* m_OriginalScriptedGameEvent{};
		void* m_OriginalIncrementStatEvent{};
		void* m_OriginalSendCloneSync{};
		void* m_OriginalNetworkHandler{};
		void* m_OriginalDisableTransactionError{};
		void* m_OriginalGetModelInfo{};
		void* m_OriginalPickupRewardMoneyIsApplicableToPlayer{};
		void* m_OriginalBypassChat{};
		void* m_OriginalProcessNetObject{};
		void* m_OriginalCanApplyToObject{};
		void* m_OriginalNewtArrayHandler{};
		void* m_OriginalWriteSyncDataString{};
		void* m_OriginalChatMessage{};
		void* m_OriginalGameInvite{};
		VMTHook m_D3DHook;
		char* m_ObjectBypass;
		char m_OriginalObjectBypass[2];
	};

	inline std::unique_ptr<Hooking> g_Hooking;
}
