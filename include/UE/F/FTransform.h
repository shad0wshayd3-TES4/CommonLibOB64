#pragma once

#include "UE/T/TTransform.h"

namespace UE
{
	using FTransform = Math::TTransform<double>;
	static_assert(sizeof(FTransform) == 0x60);

	using FTransform3d = Math::TTransform<double>;
	static_assert(sizeof(FTransform) == 0x60);

	using FTransform3f = Math::TTransform<float>;
	static_assert(sizeof(FTransform) == 0x60);
}
