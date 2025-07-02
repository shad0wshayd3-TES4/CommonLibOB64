#pragma once

namespace UE
{
	class FMeshReplacementChange;
	class UObject;

	class IMeshReplacementCommandChangeTarget
	{
	public:
		virtual ~IMeshReplacementCommandChangeTarget();                                           // 000
		virtual UObject* _GetUObject();                                                           // 001
		virtual void     ApplyChange(const FMeshReplacementChange* a_change, bool a_revert) = 0;  // 002
	};
}
