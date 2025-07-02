#pragma once

#include "UE/F/FString.h"

namespace UE
{
	class FTriMeshCollisionData;
	class FTriMeshCollisionDataEstimates;
	class UObject;

	class IInterface_CollisionDataProvider
	{
	public:
		// add
		virtual ~IInterface_CollisionDataProvider();                                                              // 000
		virtual UObject* _GetUObject();                                                                           // 001
		virtual bool     GetPhysicsTriMeshData(FTriMeshCollisionData* a_data, bool a_all);                        // 002
		virtual bool     GetTriMeshSizeEstimates(FTriMeshCollisionDataEstimates& a_estimates, bool a_all) const;  // 003
		virtual bool     ContainsPhysicsTriMeshData(bool a_all) const;                                            // 004
		virtual bool     PollAsyncPhysicsTriMeshData(bool a_all) const;                                           // 005
		virtual bool     WantsNegXTriMesh();                                                                      // 006
		virtual void     GetMeshId(FString& a_id);                                                                // 007
	};
}
