#pragma once

#include "UE/F/FDefaultDelegateUserPolicy.h"

namespace UE
{
	template <class T, class Policy = FDefaultDelegateUserPolicy>
	class TMulticastDelegate
	{
		static_assert(sizeof(T) == 0);
	};

	template <class R, class... Args, class Policy>
	class TMulticastDelegate<R(Args...), Policy>
	{
		static_assert(sizeof(R) == 0);
	};

	template <class... Args, class Policy>
	class TMulticastDelegate<void(Args...), Policy> :
		public Policy::FMulticastDelegateExtras
	{
	public:
		using InvocationListType = Policy::FMulticastDelegateExtras::InvocationListType;
	};

	using FSimpleMulticastDelegate = TMulticastDelegate<void(void)>;
}
