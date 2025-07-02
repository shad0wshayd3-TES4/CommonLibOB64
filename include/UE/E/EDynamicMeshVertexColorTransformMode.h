#pragma once

namespace UE
{
	enum class EDynamicMeshVertexColorTransformMode : std::uint8_t
	{
		NoTransform,
		LinearToSRGB,
		SRGBToLinear
	};
}
