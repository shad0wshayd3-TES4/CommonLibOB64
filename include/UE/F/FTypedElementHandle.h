#pragma once

namespace UE
{
	class FTypedElementInternalData;

	class FTypedElementHandle
	{
	public:
		FTypedElementHandle() = default;

		// members
		const FTypedElementInternalData* dataPtr{ nullptr };  // 000
	};
	static_assert(sizeof(FTypedElementHandle) == 0x8);
}
