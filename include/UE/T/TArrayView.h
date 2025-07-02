#pragma once

namespace UE
{
	template <class T, class S = std::int32_t>
	class TArrayView
	{
	public:
		// members
		T* dataPtr;   // 000
		S  arrayNum;  // 008
	};
}
