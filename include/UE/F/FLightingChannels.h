#pragma once

namespace UE
{
	class FLightingChannels
	{
	public:
		// members
		std::uint8_t channel0: 1;  // 000:0
		std::uint8_t channel1: 1;  // 000:1
		std::uint8_t channel2: 1;  // 000:2
	};
	static_assert(sizeof(FLightingChannels) == 0x1);
}
