#pragma once

#include "UE/F/FName.h"
#include "UE/F/FRotator.h"
#include "UE/F/FVector_NetQuantize.h"
#include "UE/T/TObjectPtr.h"

namespace UE
{
	class AActor;
	class USceneComponent;

	class FRepAttachment
	{
	public:
		// members
		TObjectPtr<AActor>          attachParent;     // 00
		FVector_NetQuantize100      locationOffset;   // 08
		FVector_NetQuantize100      relativeScale3D;  // 20
		FRotator                    rotationOffset;   // 38
		FName                       attachSocket;     // 50
		TObjectPtr<USceneComponent> attachComponent;  // 58
	};
	static_assert(sizeof(FRepAttachment) == 0x60);
}
