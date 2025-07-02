#pragma once

#include "UE/F/FStructOnScope.h"

namespace UE
{
	template <class T>
	class TStructOnScope :
		public FStructOnScope
	{
	public:
		TStructOnScope() = default;

		// override
		virtual ~TStructOnScope() = default;  // 000
	};
}
