#pragma once

namespace UE
{
	enum class ECollisionTraceFlag : std::int32_t
	{
		UseDefault,
		UseSimpleAndComplex,
		UseSimpleAsComplex,
		UseComplexAsSimple,
	};
}
