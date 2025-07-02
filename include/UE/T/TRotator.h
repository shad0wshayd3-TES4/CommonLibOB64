#pragma once

namespace UE::Math
{
	template <typename T>
	class TRotator
	{
	public:
		// members
		T pitch;  // 00
		T yaw;    // ??
		T roll;   // ??
	};
	static_assert(sizeof(TRotator<double>) == 0x18);
}
