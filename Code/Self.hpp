#include "Common.hpp"

namespace Big {
	class SelfFeatures
	{
	public:

		static void Tick();

	public:
		void Alpha(bool toggle, int alphalevel);

	public:
		int AlphaLevel = 255;
		bool AlphaToggle = false;

		std::size_t iterator = 0;
		const char* name[3] = {
			"BigBase",
			"XIFI",
			"Poseidon"
		};
	};

	inline SelfFeatures g_SelfFeatures;
}