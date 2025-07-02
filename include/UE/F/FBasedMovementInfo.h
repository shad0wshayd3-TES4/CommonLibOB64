#pragma once

#include "UE/F/FName.h"
#include "UE/F/FRotator.h"
#include "UE/F/FVector_NetQuantize.h"
#include "UE/T/TObjectPtr.h"

namespace UE
{
	class UPrimitiveComponent;

	class FBasedMovementInfo
	{
	public:
		// members
		std::uint16_t                   baseID;                  // 00
		TObjectPtr<UPrimitiveComponent> movementBase;            // 08
		FName                           boneName;                // 10
		FVector_NetQuantize100          location;                // 18
		FRotator                        rotation;                // 30
		bool                            serverHasBaseComponent;  // 48
		bool                            relativeRotation;        // 49
		bool                            serverHasVelocity;       // 4A
	};
	static_assert(sizeof(FBasedMovementInfo) == 0x50);
}
