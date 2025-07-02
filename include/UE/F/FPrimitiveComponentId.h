#pragma once

namespace UE
{
	class FPrimitiveComponentId
	{
	public:
		// members
		std::uint32_t value;  // 000
	};
	static_assert(sizeof(FPrimitiveComponentId) == 0x4);
}
