#pragma once

#include "RE/B/BSExtraData.h"

namespace RE
{
	class ExtraCharge : public BSExtraData
	{
	public:
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::Charge;

		virtual ~ExtraCharge();

		float charge; // 18
	};

	static_assert(offsetof(ExtraCharge, charge) == 0x18);
}
