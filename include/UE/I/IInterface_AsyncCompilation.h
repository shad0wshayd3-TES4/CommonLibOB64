#pragma once

namespace UE
{
	class UObject;

	class IInterface_AsyncCompilation
	{
	public:
		// add
		virtual ~IInterface_AsyncCompilation();  // 000
		virtual UObject* _GetUObject();          // 001
	};
}
