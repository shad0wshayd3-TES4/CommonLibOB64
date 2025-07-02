#pragma once

#include "RE/E/ExtraDataType.h"

namespace RE
{
	class BSExtraData
	{
	public:
		virtual ~BSExtraData();

		//virtual bool IsNotEqual(BSExtraData* a_other) const;

		ExtraDataType type;
		BSExtraData*  next;
	};

	static_assert(offsetof(BSExtraData, type) == 0x08);
	static_assert(offsetof(BSExtraData, next) == 0x10);
}
