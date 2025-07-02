#pragma once

namespace UE
{
	class FMeshVertexChange;
	class UObject;

	class IMeshVertexCommandChangeTarget
	{
	public:
		virtual ~IMeshVertexCommandChangeTarget();                                           // 000
		virtual UObject* _GetUObject();                                                      // 001
		virtual void     ApplyChange(const FMeshVertexChange* a_change, bool a_revert) = 0;  // 002
	};
}
