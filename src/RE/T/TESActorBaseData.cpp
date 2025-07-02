#include "RE/T/TESActorBaseData.h"

#include "RE/P/PlayerCharacter.h"

namespace RE
{
	std::int16_t TESActorBaseData::GetLevel(bool a_calculateFromPlayer) const
	{
		if (!HasPlayerLevelOffset())
			return actorData.level;

		std::int16_t level = actorData.level;
		if (a_calculateFromPlayer)
			level += static_cast<TESActorBase*>(PlayerCharacter::GetSingleton()->GetObjectReference())->actorData.level;

		if (level <= actorData.calcLevelMin)
			return actorData.calcLevelMin;

		// actorData.calcLevelMax == 0 => no level cap
		return actorData.calcLevelMax == 0 ? level : std::min(level, (std::int16_t)actorData.calcLevelMax);
	}
}
