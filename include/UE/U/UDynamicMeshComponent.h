#pragma once

#include "UE/E/ECollisionTraceFlag.h"
#include "UE/E/EDynamicMeshComponentRenderUpdateMode.h"
#include "UE/E/EDynamicMeshComponentTangentsMode.h"
#include "UE/F/FAxisAlignedBox3.h"
#include "UE/F/FKAggregateGeom.h"
#include "UE/F/FMeshTangents.h"
#include "UE/F/FVector4.h"
#include "UE/I/IInterface_CollisionDataProvider.h"
#include "UE/T/TUniqueFunction.h"
#include "UE/U/UBaseDynamicMeshComponent.h"

namespace UE
{
	class FMeshRenderDecomposition;
	class IRenderMeshPostProcessor;
	class UDynamicMeshComponent;

	using FComponentChildrenChangedDelegate = TMulticastDelegate<void(USceneComponent*, bool)>;
	using FMeshVerticesModified = TMulticastDelegate<void(UDynamicMeshComponent*, const FMeshVertexChange*, bool)>;

	class UDynamicMeshComponent :
		public UBaseDynamicMeshComponent,
		public IInterface_CollisionDataProvider
	{
	public:
		UE_DEFINE_UOBJECT(UDynamicMeshComponent, UBaseDynamicMeshComponent, "Engine", "DynamicMeshComponent");

		// override
		virtual ~UDynamicMeshComponent();  // 000

		// add
		virtual void                           EditMesh(TFunctionRef<void(Geometry::FDynamicMesh3&)> a_function, EDynamicMeshComponentRenderUpdateMode a_updateMode = EDynamicMeshComponentRenderUpdateMode::FullUpdate);                                           //
		virtual void                           NotifyMeshModified();                                                                                                                                                                                                //
		virtual void                           NotifyMeshVertexAttributesModified(bool a_position = true, bool a_normal = true, bool a_uv = true, bool a_color = true);                                                                                             //
		virtual void                           SetTriangleColorFunction(TUniqueFunction<FColor(const Geometry::FDynamicMesh3*, std::int32_t)> a_function, EDynamicMeshComponentRenderUpdateMode a_updateMode = EDynamicMeshComponentRenderUpdateMode::FastUpdate);  //
		virtual void                           ClearTriangleColorFunction(EDynamicMeshComponentRenderUpdateMode UpdateMode = EDynamicMeshComponentRenderUpdateMode::FastUpdate);                                                                                    //
		virtual bool                           HasTriangleColorFunction();                                                                                                                                                                                          //
		virtual void                           SetVertexColorRemappingFunction(TUniqueFunction<void(FVector4f&)> a_function, EDynamicMeshComponentRenderUpdateMode a_updateMode = EDynamicMeshComponentRenderUpdateMode::FastUpdate);                               //
		virtual void                           ClearVertexColorRemappingFunction(EDynamicMeshComponentRenderUpdateMode a_updateMode = EDynamicMeshComponentRenderUpdateMode::FastUpdate);                                                                           //
		virtual bool                           HasVertexColorRemappingFunction();                                                                                                                                                                                   //
		virtual void                           EnableSecondaryTriangleBuffers(TUniqueFunction<bool(const Geometry::FDynamicMesh3*, std::int32_t)> a_filterFunction);                                                                                                //
		virtual void                           DisableSecondaryTriangleBuffers();                                                                                                                                                                                   //
		virtual void                           SetExternalDecomposition(TUniquePtr<FMeshRenderDecomposition> a_decomposition);                                                                                                                                      //
		virtual void                           SetRenderMeshPostProcessor(TUniquePtr<IRenderMeshPostProcessor> a_processor);                                                                                                                                        //
		virtual const Geometry::FDynamicMesh3* GetRenderMesh() const;                                                                                                                                                                                               //
		virtual Geometry::FDynamicMesh3*       GetRenderMesh();                                                                                                                                                                                                     //
		virtual void                           InvalidateAutoCalculatedTangents();                                                                                                                                                                                  //
		virtual const UBodySetup*              GetBodySetup() const;                                                                                                                                                                                                //
		virtual void                           UpdateCollision(bool a_onlyPending = true);                                                                                                                                                                          //
		virtual void                           SetSimpleCollisionShapes(const FKAggregateGeom& a_geom, bool a_update);                                                                                                                                              //
		virtual void                           ClearSimpleCollisionShapes(bool a_update);                                                                                                                                                                           //
		virtual void                           InvalidatePhysicsData();                                                                                                                                                                                             //
		virtual void                           RebuildPhysicsData();                                                                                                                                                                                                //
		virtual void                           FinishPhysicsAsyncCook(bool a_success, UBodySetup* a_setup);                                                                                                                                                         //
		virtual UBodySetup*                    CreateBodySetupHelper();                                                                                                                                                                                             //
		virtual void                           SetBodySetup(UBodySetup* a_setup);                                                                                                                                                                                   //

		// members
		TObjectPtr<UDynamicMesh>                                              meshObject;                      // 620
		FSimpleMulticastDelegate                                              onMeshChanged;                   // 628
		FMeshVerticesModified                                                 onMeshVerticesChanged;           // 640
		bool                                                                  invalidateProxyOnChange;         // 658
		FDelegateHandle                                                       meshObjectChangedHandle;         // 660
		TUniqueFunction<FColor(const Geometry::FDynamicMesh3*, std::int32_t)> triangleColorFunc;               // 670
		TUniqueFunction<void(FVector4f&)>                                     vertexColorMappingFunc;          // 6B0
		TUniqueFunction<bool(const Geometry::FDynamicMesh3*, std::int32_t)>   secondaryTriFilterFunc;          // 6F0
		TUniquePtr<FMeshRenderDecomposition>                                  decomposition;                   // 730
		TUniquePtr<IRenderMeshPostProcessor>                                  renderMeshPostProcessor;         // 738
		TUniquePtr<Geometry::FDynamicMesh3>                                   renderMesh;                      // 740
		FComponentChildrenChangedDelegate                                     onChildAttachmentModified;       // 748
		EDynamicMeshComponentTangentsMode                                     tangentsType;                    // 760
		bool                                                                  autoCalculatedTangentsValid;     // 761
		Geometry::FMeshTangentsf                                              autoCalculatedTangents;          // 768
		TEnumAsByte<ECollisionTraceFlag>                                      collisionType;                   // 7A0
		bool                                                                  useAsyncCooking;                 // 7A1
		bool                                                                  enableComplexCollision;          // 7A2
		bool                                                                  deferCollisionUpdates;           // 7A3
		TObjectPtr<UBodySetup>                                                meshBodySetup;                   // 7A8
		bool                                                                  transientDeferCollisionUpdates;  // 7B0
		bool                                                                  collisionUpdatePending;          // 7B1
		Geometry::FAxisAlignedBox3d                                           localBounds;                     // 7B8
		FKAggregateGeom                                                       aggGeom;                         // 7E8
		TArray<TObjectPtr<UBodySetup>>                                        asyncBodySetupQueue;             // 860
		bool                                                                  proxyValid;                      // 870
		bool                                                                  proxyVerifyUsedMaterials;        // 871
	};
	static_assert(sizeof(UDynamicMeshComponent) == 0x880);
}
