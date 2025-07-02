#pragma once

namespace UE::Math
{
	template <class T>
	class alignas(16) TMatrix
	{
	public:
		// members
		alignas(16) T m[4][4];  // 000
	};
}
