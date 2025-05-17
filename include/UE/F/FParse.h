#pragma once

namespace UE
{
	class FParse
	{
	public:
		static bool Command(const wchar_t** a_stream, const wchar_t* a_match, bool a_parseMightTriggerExecution = true)
		{
			using func_t = decltype(&FParse::Command);
			static REL::Relocation<func_t> func{ ID::FParse::Command };
			return func(a_stream, a_match, a_parseMightTriggerExecution);
		}
	};
}
