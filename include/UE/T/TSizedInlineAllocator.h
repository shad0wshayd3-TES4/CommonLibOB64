#pragma once

#include "UE/F/FDefaultAllocator.h"
#include "UE/T/TSizedDefaultAllocator.h"
#include "UE/T/TTypeCompatibleBytes.h"

namespace UE
{
	template <std::uint32_t N, std::int32_t I, class A = FDefaultAllocator>
	class TSizedInlineAllocator
	{
	public:
		using SizeType = typename TBitsToSizeType<I>::Type;

		static constexpr bool NeedsElementType{ true };
		static constexpr bool RequireRangeCheck{ true };

		template <class T>
		class ForElementType
		{
		public:
			T* GetAllocation() const
			{
				return secondaryData.GetAllocation() ? secondaryData.GetAllocation() : GetInlineElements();
			}

			SizeType GetInitialCapacity() const
			{
				return N;
			}

			T* GetInlineElements() const
			{
				return (T*)inlineData;
			}

			bool HasAllocation() const
			{
				return secondaryData.HasAllocation();
			}

			// members
			TTypeCompatibleBytes<T>                inlineData[N];  // 00
			typename A::template ForElementType<T> secondaryData;  // ??
		};
		// static_assert(sizeof(ForElementType<std::uint32_t>) == 0x28);

		using ForAnyElementType = void;
	};
	static_assert(std::is_empty_v<TSizedInlineAllocator<4, 32>>);
}
