#pragma once

#include "UE/F/FName.h"
#include "UE/F/FRootMotionSourceGroup.h"
#include "UE/F/FRotator.h"
#include "UE/F/FVector_NetQuantize.h"
#include "UE/T/TObjectPtr.h"

namespace UE
{
	class UAnimMontage;
	class UPrimitiveComponent;

	class FRepRootMotionMontage
	{
	public:
		// members
		bool                            isActive;                 // 000
		TObjectPtr<UAnimMontage>        animMontage;              // 008
		float                           position;                 // 010
		FVector_NetQuantize100          location;                 // 018
		FRotator                        rotation;                 // 030
		TObjectPtr<UPrimitiveComponent> movementBase;             // 048
		FName                           movementBaseBoneName;     // 050
		bool                            relativePosition;         // 058
		bool                            relativeRotation;         // 059
		FRootMotionSourceGroup          authoritativeRootMotion;  // 060
		FVector_NetQuantize10           acceleration;             // 0A8
		FVector_NetQuantize10           linearVelocity;           // 0C0
	};
	static_assert(sizeof(FRepRootMotionMontage) == 0x0D8);
}
