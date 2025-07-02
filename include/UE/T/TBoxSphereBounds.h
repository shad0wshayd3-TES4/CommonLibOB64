#pragma once

#include "UE/T/TVector.h"

namespace UE::Math
{
	template <class T1, class T2>
	class TBoxSphereBounds
	{
	public:
		// members
		TVector<T1> origin;        // 000
		TVector<T2> boxExtent;     // ???
		T2          sphereRadius;  // ???
	};
}

