#pragma once

namespace UE
{
	enum class EUpdateTransformFlags : std::int32_t
	{
		None = 0,
		SkipPhysicsUpdate = 1 << 0,
		PropagateFromParent = 1 << 1,
		OnlyUpdateIfUsingSocket = 1 << 2
	};
	REX_DEFINE_ENUM_CLASS_FLAGS(EUpdateTransformFlags);
}
