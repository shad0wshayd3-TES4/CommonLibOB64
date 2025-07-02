#pragma once

namespace UE
{
	enum class EDynamicMeshComponentColorOverrideMode : std::uint8_t
	{
		None,
		VertexColors,
		Polygroups,
		Constant
	};
}
