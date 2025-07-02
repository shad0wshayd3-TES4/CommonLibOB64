#pragma once

#include "UE/F/FOutputDevice.h"

namespace UE
{
	class FOutputDeviceNull :
		public FOutputDevice
	{
	public:
		virtual void Serialize(const wchar_t*, ELogVerbosity, const FName&)
		{}
	};
}
