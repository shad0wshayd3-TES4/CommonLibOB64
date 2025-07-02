#pragma once

namespace UE
{
	enum class EDOFMode : std::uint8_t
	{
		Default = 0,
		SixDOF = 1,
		YZPlane = 2,
		XZPlane = 3,
		XYPlane = 4,
		CustomPlane = 5,
		None = 6,
	};
}
