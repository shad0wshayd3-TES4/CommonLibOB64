#pragma once

#include "UE/F/FExec.h"

namespace UE
{
	class FSelfRegisteringExec :
		public FExec
	{
	public:
		FSelfRegisteringExec()
		{
			using func_t = void (FSelfRegisteringExec::*)();
			static REL::Relocation<func_t> func{ ID::FSelfRegisteringExec::Ctor };
			func(this);
		}

		// override
		virtual ~FSelfRegisteringExec()
		{
			using func_t = void (FSelfRegisteringExec::*)();
			static REL::Relocation<func_t> func{ ID::FSelfRegisteringExec::Dtor };
			func(this);
		}
	};
	static_assert(sizeof(FSelfRegisteringExec) == 0x8);
}
