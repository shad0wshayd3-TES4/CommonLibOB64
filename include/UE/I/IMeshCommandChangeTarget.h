#pragma once

namespace UE
{
	class FMeshChange;
	class UObject;

	class IMeshCommandChangeTarget
	{
	public:
		virtual ~IMeshCommandChangeTarget();                                           // 000
		virtual UObject* _GetUObject();                                                // 001
		virtual void     ApplyChange(const FMeshChange* a_change, bool a_revert) = 0;  // 002
	};
}
