#pragma once

namespace UE
{
	enum class ERelativeTransformSpace : std::uint8_t
	{
		World = 0,
		Actor = 1,
		Component = 2,
		ParentBoneSpace = 3,
	};
}
