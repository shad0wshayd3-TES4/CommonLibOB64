#pragma once

namespace UE
{
	enum class EDynamicMeshComponentTangentsMode : std::uint8_t
	{
		NoTangents = 0,
		AutoCalculated = 1,
		ExternallyProvided = 2,
		Default = 255
	};
}
