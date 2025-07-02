#pragma once

#include "RE/B/BSTList.h"

namespace RE
{
	class ExtraDataList;
	class TESBoundObject;

	class InventoryEntryData
	{
	public:
		BSSimpleList<ExtraDataList*>* extraData;   // 00
		int                           countDelta;  // 08
		TESBoundObject*               object;      // 10
	};

	static_assert(offsetof(InventoryEntryData, object) == 0x10);
}
