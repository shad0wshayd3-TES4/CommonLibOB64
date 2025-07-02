#pragma once

namespace UE
{
	enum class ELODStreamingCallbackResult : std::int32_t
	{
		Success = 0,
		TimedOut = 1,
		AssetRemoved = 2,
		ComponentRemoved = 3,
		StreamingDisabled = 4,
		NotImplemented = 5
	};
}
