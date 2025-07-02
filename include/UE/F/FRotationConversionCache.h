#pragma once

#include "UE/F/FQuat.h"
#include "UE/F/FRotator.h"

namespace UE
{
	class FRotationConversionCache
	{
	public:
		// members
		FQuat    cachedQuat;     // 000
		FRotator cachedRotator;  // 020
	};
	static_assert(sizeof(FRotationConversionCache) == 0x40);
}
