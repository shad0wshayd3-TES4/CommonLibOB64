#pragma once

#include "UE/F/FDefaultAllocator.h"
#include "UE/T/TArray.h"
#include "UE/T/TPair.h"

namespace UE
{
	template <class T>
	class TLess;

	template <class K, class V, class A = FDefaultAllocator, class P = TLess<K>>
	class TSortedMap
	{
	public:
		// members
		TArray<TPair<K, V>, A> pairs;  // 000
	};
}
