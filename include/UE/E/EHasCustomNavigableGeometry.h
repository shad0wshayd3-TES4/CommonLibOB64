#pragma once

namespace UE
{
	enum class EHasCustomNavigableGeometry : std::int32_t
	{
		No,
		Yes,
		EvenIfNotCollidable,
		DontExport,
	};
}
