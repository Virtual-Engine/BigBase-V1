#include "Common.hpp"
#include "Self.hpp"

namespace Big {
	void SelfFeatures::Alpha(bool toggle, int alphalevel)
	{
		if (toggle)
		{
			ENTITY::SET_ENTITY_ALPHA(PLAYER::PLAYER_PED_ID(), alphalevel, 0);
		}
	}

	void SelfFeatures::Tick()
	{
		g_SelfFeatures.Alpha(g_SelfFeatures.AlphaToggle, g_SelfFeatures.AlphaLevel);
	}
}