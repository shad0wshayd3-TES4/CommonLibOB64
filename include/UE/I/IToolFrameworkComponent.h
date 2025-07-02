#pragma once

namespace UE
{
	class UObject;

	class IToolFrameworkComponent
	{
	public:
		virtual ~IToolFrameworkComponent();  // 000
		virtual UObject* _GetUObject();      // 001
	};
}
