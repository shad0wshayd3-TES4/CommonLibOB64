#pragma once

namespace UE
{
	enum class ETextureStreamingBuildType : std::int32_t
	{
		MapBuild,
		ActorBuild,
		ValidationOnly,
		ViewMode
	};
}
