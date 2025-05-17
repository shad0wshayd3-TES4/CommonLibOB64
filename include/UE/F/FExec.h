#pragma once

namespace UE
{
	class FOutputDevice;
	class UWorld;

	class FExec
	{
	public:
		// add
		virtual ~FExec() = default;  // 00

		// add
		virtual bool Exec(UWorld* a_world, const wchar_t* a_cmd, FOutputDevice& a_archive)  // 01
		{
			return Exec_Runtime(a_world, a_cmd, a_archive);
		}

	protected:
		virtual bool Exec_Runtime(UWorld*, const wchar_t*, FOutputDevice&)  // 02
		{
			return false;
		}

		virtual bool Exec_Dev(UWorld*, const wchar_t*, FOutputDevice&)  // 03
		{
			return false;
		}

		virtual bool Exec_Editor(UWorld*, const wchar_t*, FOutputDevice&)  // 04
		{
			return false;
		}
	};
	static_assert(sizeof(FExec) == 0x8);
}
