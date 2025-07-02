#pragma once

namespace UE
{
	enum class EShadowCacheInvalidationBehavior : std::uint8_t
	{
		Auto,
		Always,
		Rigid,
		Static,
	};
}
