#pragma once

#include "UE/E/EComponentSocketType.h"
#include "UE/F/FName.h"
#include "UE/T/TEnumAsByte.h"

namespace UE
{
	class FComponentSocketDescription
	{
	public:
		// members
		FName                             name;  // 000
		TEnumAsByte<EComponentSocketType> type;  // 008
	};
	static_assert(sizeof(FComponentSocketDescription) == 0xC);
}
