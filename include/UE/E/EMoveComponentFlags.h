#pragma once

namespace UE
{
	enum class EMoveComponentFlags : std::int32_t
	{
		NoFlags = 0x0000,
		IgnoreBases = 0x0001,
		SkipPhysicsMove = 0x0002,
		NeverIgnoreBlockingOverlaps = 0x0004,
		DisableBlockingOverlapDispatch = 0x0008,
	};
	REX_DEFINE_ENUM_CLASS_FLAGS(EMoveComponentFlags);
}
