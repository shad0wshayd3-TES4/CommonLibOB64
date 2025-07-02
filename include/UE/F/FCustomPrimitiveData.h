#pragma once

#include "UE/T/TArray.h"

namespace UE
{
	class FCustomPrimitiveData
	{
	public:
		// members
		TArray<float> data;  // 000
	};
	static_assert(sizeof(FCustomPrimitiveData) == 0x10);
}
