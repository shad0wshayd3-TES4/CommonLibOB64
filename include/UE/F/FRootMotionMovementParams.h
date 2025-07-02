#pragma once

#include "UE/F/FTransform.h"

namespace UE
{
	class FRootMotionMovementParams
	{
	public:
		// members
		bool       hasRootMotion;        // 000
		float      blendWeight;          // 004
		FTransform rootMotionTransform;  // 010
	};
	static_assert(sizeof(FRootMotionMovementParams) == 0x070);
}
