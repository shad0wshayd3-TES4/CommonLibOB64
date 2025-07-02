#pragma once

namespace UE::Math
{
	template <class T>
	class alignas(16) TVector4
	{
	public:
		// members
		T x;  // 000
		T y;  // ???
		T z;  // ???
		T w;  // ???
	};
}
