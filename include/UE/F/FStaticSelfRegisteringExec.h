#pragma once

#include "UE/F/FSelfRegisteringExec.h"

namespace UE
{
	class FStaticSelfRegisteringExec :
		public FSelfRegisteringExec
	{
		using Func = bool (*)(UWorld* a_world, const wchar_t* a_cmd, FOutputDevice& a_archive);

	public:
		FStaticSelfRegisteringExec(Func a_func) :
			m_func(a_func)
		{}

		virtual bool Exec(UE::UWorld* a_world, const wchar_t* a_cmd, UE::FOutputDevice& a_archive) override
		{
			return (*m_func)(a_world, a_cmd, a_archive);
		}

	private:
		Func m_func;
	};
	static_assert(sizeof(FSelfRegisteringExec) == 0x8);
}
