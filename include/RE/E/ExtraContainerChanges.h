#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSTList.h"

namespace RE
{
	class InventoryEntryData;

	class ExtraContainerChanges : public BSExtraData
	{
	public:
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::ContainerChanges;

		struct InventoryChanges
		{
			BSSimpleList<InventoryEntryData*>* objects;      // 00
			TESObjectREFR*                     owner;        // 08
			float                              totalWeight;  // 10
			float                              wornWeight;   // 14
		};

		virtual ~ExtraContainerChanges();

		[[nodiscard]] InventoryChanges*                   GetInventoryChanges() const { return changes; }
		[[nodiscard]] BSSimpleList<InventoryEntryData*>*  GetObjectList() const { return changes ? changes->objects : nullptr; }
		[[nodiscard]] TESObjectREFR*                      GetOwner() const { return changes ? changes->owner : nullptr; }
		[[nodiscard]] float                               GetTotalWeight() const { return changes ? changes->totalWeight : 0.0f; }
		[[nodiscard]] float                               GetWornWeight() const { return changes ? changes->wornWeight : 0.0f; }

		InventoryChanges* changes;  // 18
	};
}
