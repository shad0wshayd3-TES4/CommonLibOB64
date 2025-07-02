#pragma once

#include "UE/T/TVector.h"

namespace UE::Geometry
{
	template <class T>
	class TAxisAlignedBox3
	{
	public:
		// members
		Math::TVector<T> min;  // 000
		Math::TVector<T> max;  // ???
	};
}
