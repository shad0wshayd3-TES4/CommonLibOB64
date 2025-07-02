#pragma once

#include "RE/A/ACTOR_BASE_DATA.h"
#include "RE/B/BSTList.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	class FACTION_RANK;
	class TESLevItem;

	struct TESActorBaseData :
		public BaseFormComponent
	{
	public:
		inline static constexpr auto RTTI = RTTI::TESActorBaseData;
		inline static constexpr auto VTABLE = VTABLE::TESActorBaseData;

		[[nodiscard]] bool IsFemale() const { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flags::Female); }
		[[nodiscard]] bool IsEssential() const { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flags::Essential); }
		[[nodiscard]] bool CanRespawn() const { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flags::Respawn); }
		[[nodiscard]] bool HasAutoCalculatedStats() const { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flags::AutoCalcStats); }
		[[nodiscard]] bool HasPlayerLevelOffset() const { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flags::PCLevelOffset); }
		[[nodiscard]] bool NoLowLevelProcessing() const { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flags::NoLowLevelProcessing); }
		[[nodiscard]] bool NoRumors() const { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flags::NoRumors); }
		[[nodiscard]] bool IsSummonable() const { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flags::Summonable); }
		[[nodiscard]] bool NoPersuasion() const { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flags::NoPersuasion); }
		[[nodiscard]] bool CanCheckCorpses() const { return actorData.actorBaseFlags.all(ACTOR_BASE_DATA::Flags::CanCorpseCheck); }

		[[nodiscard]] TESLevItem*  GetDeathItem() const { return deathItem; }
		[[nodiscard]] std::int16_t GetLevel(bool a_calculateFromPlayer = true) const;

		// members
		ACTOR_BASE_DATA             actorData;  // 08
		TESLevItem*                 deathItem;  // 18
		BSSimpleList<FACTION_RANK*> factions;   // 20
	};
	static_assert(sizeof(TESActorBaseData) == 0x30);
}
