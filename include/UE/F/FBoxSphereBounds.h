#pragma once

#include "UE/T/TBoxSphereBounds.h"

namespace UE
{
	using FBoxSphereBounds = Math::TBoxSphereBounds<double, double>;
	using FBoxSphereBounds3d = Math::TBoxSphereBounds<double, double>;
	using FBoxSphereBounds3f = Math::TBoxSphereBounds<float, float>;
}
