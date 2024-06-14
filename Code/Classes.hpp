#pragma once 
#include "Logger.hpp"

namespace rage
{
	// Classes: 
	class sysMemAllocator;
	class tlsContext;
	class scrThreadContext;
	class scrThread;
	class scriptResource;
	class scriptResourceEntry;
	class scriptHandlerNetComponent;
	class scriptHandlerObject;
	class scriptHandler;
	class scriptHandlerMgr;
	class scriptId;
	class netPlayer;
	class netLoggingInterface;

	class tlsContext
	{
	public:
		char m_padding1[0xC8]; // 0x00
		sysMemAllocator* m_allocator; // 0xC8
		char m_padding2[0x770]; // 0xD0
		scrThread* m_script_thread; // 0x828
		bool m_is_script_thread_active; // 0x830

		static tlsContext* get()
		{
			return *reinterpret_cast<tlsContext**>(__readgsqword(0x58));
		}
	};

	enum class eThreadState : std::uint32_t
	{
		idle,
		running,
		killed,
		unk_3,
		unk_4,
	};

	class scrThreadContext
	{
	public:
		std::uint32_t m_thread_id;           // 0x00
		std::uint32_t m_script_hash;         // 0x04
		eThreadState m_state;                // 0x08
		std::uint32_t m_instruction_pointer; // 0x0C
		std::uint32_t m_frame_pointer;       // 0x10
		std::uint32_t m_stack_pointer;       // 0x14
		float m_timer_a;                     // 0x18
		float m_timer_b;                     // 0x1C
		float m_timer_c;                     // 0x20
		char m_padding1[0x2C];               // 0x24
		std::uint32_t m_stack_size;          // 0x50
		char m_padding2[0x54];               // 0x54
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
			return tlsContext::get()->m_script_thread;
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

	class scriptResource
	{
	public:
		virtual ~scriptResource() = default;
	};

	class scriptResourceEntry
	{
	public:
		scriptResource* m_data;      // 0x00
		std::uint32_t m_unk;         // 0x04
		char m_padding[0x0C];        // 0x0C
		scriptResourceEntry* m_next; // 0x18
	};

	class scriptHandlerNetComponent
	{
	public:
		virtual ~scriptHandlerNetComponent() = default;

	public:
		scriptHandler* m_script_handler; // 0x08
	};

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
		scrThread* m_script_thread;                  // 0x18
		atDList<atDScriptObjectNode> m_objects;      // 0x20
		scriptResource* m_resource_list_head;        // 0x30
		scriptResource* m_resource_list_tail;        // 0x38
		void* m_0x40;                                // 0x40
		scriptHandlerNetComponent* m_net_component;  // 0x48
		std::uint32_t m_0x50;                        // 0x50
		std::uint32_t m_0x54;                        // 0x54
		std::uint32_t m_0x58;                        // 0x58
		std::uint32_t m_0x60;                        // 0x5C
	};

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
		virtual void _0x38(scrThread*) = 0;                                                     // 7 (0x38)

		// Allocates and constructs a script handler.
		virtual scriptHandler* create_script_handler() = 0;                                     // 8 (0x40)

		// Finds the script handler for a given script id.
		virtual scriptHandler* get_script_handler(scriptId*) = 0;                               // 9 (0x48)

		// Attaches a script thread.
		virtual void attach_thread(scrThread*) = 0;                                             // 10 (0x50)

		// Detaches a script thread.
		virtual void detach_thread(scrThread*) = 0;                                             // 11 (0x58)

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
		netLoggingInterface* m_logger;                 // 0x40
	};

	class sysMemAllocator
	{
	public:
		virtual ~sysMemAllocator() = 0;

		virtual void SetQuitOnFail(bool) = 0;
		virtual void* Allocate(size_t size, size_t align, int subAllocator) = 0;

		inline void* allocate(size_t size, size_t align, int subAllocator)
		{
			return Allocate(size, align, subAllocator);
		}

		virtual void* TryAllocate(size_t size, size_t align, int subAllocator) = 0;

		virtual void Free(void* pointer) = 0;

		virtual void free(void* pointer)
		{
			return Free(pointer);
		}

		virtual void TryFree(void* pointer) = 0;

		virtual void Resize(void* pointer, size_t size) = 0;

		virtual sysMemAllocator* GetAllocator(int allocator) const = 0;

		virtual sysMemAllocator* GetAllocator(int allocator) = 0;

		virtual sysMemAllocator* GetPointerOwner(void* pointer) = 0;

		virtual size_t GetSize(void* pointer) const = 0;

		virtual size_t GetMemoryUsed(int memoryBucket) = 0;

		virtual size_t GetMemoryAvailable() = 0;

	public:

		static sysMemAllocator* UpdateAllocatorValue()
		{
			// B9 ? ? ? ? 48 8B 0C 01 45 33 C9 49 8B D2 48
			auto g_gtaTlsEntry = *(sysMemAllocator**)(*(uintptr_t*)(__readgsqword(88)) + 0xC8);

			if (g_gtaTlsEntry == nullptr)
				Big::g_Logger->Error("Failed to find tlsEntry within GTA5.exe via __readgsqword");

			*(sysMemAllocator**)(*(uintptr_t*)(__readgsqword(88)) + 0xC8) = g_gtaTlsEntry;
			*(sysMemAllocator**)(*(uintptr_t*)(__readgsqword(88)) + 0xC8 - 8) = g_gtaTlsEntry;

			return g_gtaTlsEntry;
		}
	};

	inline sysMemAllocator* GetAllocator()
	{
		sysMemAllocator* allocator = *(sysMemAllocator**)(*(uintptr_t*)(__readgsqword(88)) + 0xC8);

		if (!allocator)
		{
			return sysMemAllocator::UpdateAllocatorValue();
		}

		return allocator;
	}

	//WORK OR I'LL CRY
	// Static Assertions: 
	static_assert(sizeof(tlsContext) == 0x850), "Failed to validate size of tlsContext");
	static_assert(sizeof(scrThreadContext) == 0xA8, "Failed to validate size of scrThreadContext");
	static_assert(sizeof(scrThread) == 0x120, "Failed to validate size of scrThread");
	static_assert(sizeof(scriptHandler) == 0x60, "Failed to validate size of scriptHandler");

	// Array
#pragma pack(push, 8)
	template <typename T>
	class atArray
	{
	public:
		atArray()
		{
			m_data = nullptr;
			m_count = 0;
			m_size = 0;
		}

		atArray(const atArray& right)
		{
			m_count = right.m_count;
			m_size = right.m_size;

			m_data = (T*)rage::GetAllocator()->allocate(m_size * sizeof(T), 16, 0);
			std::uninitialized_copy(right.m_data, right.m_data + right.m_count, m_data);
		}

		atArray(int capacity)
		{
			m_data = (T*)rage::GetAllocator()->allocate(capacity * sizeof(T), 16, 0);
			m_count = 0;
			m_size = capacity;
		}

		void clear()
		{
			m_count = 0;
			m_size = 0;

			if (m_data)
			{
				rage::GetAllocator()->free(m_data);

				m_data = nullptr;
			}
		}

		void append(atArray<T> array_value)
		{
			auto value_array_size = array_value.size();
			auto old_capacity = m_count;

			if ((value_array_size + m_count) > std::numeric_limits<uint16_t>::max())
				Big::g_Logger->Error("RAGE atArray::append was given too large of an atArray to append");

			auto size = (uint16_t)value_array_size;
			expand(m_count + size);
			m_size += size;

			auto i = old_capacity;
			for (auto weapon_hash : array_value)
			{
				m_data[i] = weapon_hash;
				i++;
			}
		}

		void append(std::vector<T> value_array)
		{
			auto value_array_size = value_array.size();
			auto old_capacity = m_count;

			if ((value_array_size + m_count) > std::numeric_limits<uint16_t>::max())
				Big::g_Logger->Error("RAGE atArray::append was given too large of a vector to append");

			auto size = (uint16_t)value_array_size;
			expand(m_count + size);
			m_size += size;

			auto i = old_capacity;
			for (auto weapon_hash : value_array)
			{
				m_data[i] = weapon_hash;
				i++;
			}
		}

		void append(const std::initializer_list<T> value_array)
		{
			auto value_array_size = value_array.size();
			auto old_capacity = m_count;

			if ((value_array_size + m_count) > std::numeric_limits<uint16_t>::max())
				Big::g_Logger->Error("RAGE atArray::append was given too large of a list to append");

			auto size = (uint16_t)value_array_size;
			expand(m_count + size);
			m_size += size;

			auto i = old_capacity;
			for (const T* it = value_array.begin(); it != value_array.end(); ++it)
			{
				m_data[i] = *it;
				i++;
			}
		}

		void append(T value)
		{
			set(m_count, value);
		}

		void set(uint16_t offset, const T& value)
		{
			if (offset >= m_count)
			{
				expand(offset + 1);
			}

			if (offset >= m_size)
			{
				m_size = offset + 1;
			}

			m_data[offset] = value;
		}

		void expand(uint16_t newSize)
		{
			if (m_count >= newSize)
			{
				return;
			}

			T* newOffset = (T*)rage::GetAllocator()->allocate(newSize * sizeof(T), 16, 0);

			// initialize the new entries
			std::uninitialized_fill(newOffset, newOffset + newSize, T());

			// copy the existing entries
			if (m_data)
			{
				std::copy(m_data, m_data + m_size, newOffset);

				rage::GetAllocator()->free(m_data);
			}

			m_data = newOffset;
			m_count = newSize;
		}

		T* begin() const
		{
			return &m_data[0];
		}

		T* end() const
		{
			return &m_data[m_size];
		}

		T* data() const
		{
			return m_data;
		}

		std::uint16_t size() const
		{
			return m_size;
		}

		std::uint16_t count() const
		{
			return m_count;
		}

		T& operator[](std::uint16_t index) const
		{
			return m_data[index];
		}

		friend std::ostream& operator<<(std::ostream& o, const atArray<T>& j)
		{
			o << "Array Size: " << j.size() << std::endl;
			for (int i = 0; i < j.size(); i++)
			{
				T item = j[i];
				if (std::is_pointer<T>())
					o << "\tArray Pointer: " << HEX_TO_UPPER(item) << " Item: [" << HEX_TO_UPPER(*(T*)item) << "]";
				else
					o << "\tArray Item: " << item;
				if (i != j.size() - 1)
					o << std::endl;
			}
			return o;
		}

	private:
		T* m_data;
		std::uint16_t m_size;
		std::uint16_t m_count;
	};
	static_assert(sizeof(rage::atArray<std::uint32_t>) == 0x10, "rage::atArray is not properly sized");
#pragma pack(pop)
}

class GtaThread : public rage::scrThread
{
public:
	std::uint32_t m_script_hash;                // 0x120
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

static_assert(sizeof(GtaThread) == 0x158, "Failed to validate size of GtaThread");