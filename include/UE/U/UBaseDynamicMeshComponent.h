#pragma once

#include "UE/E/EDynamicMeshComponentColorOverrideMode.h"
#include "UE/E/EDynamicMeshVertexColorTransformMode.h"
#include "UE/F/FColor.h"
#include "UE/F/FLinearColor.h"
#include "UE/I/IMeshCommandChangeTarget.h"
#include "UE/I/IMeshReplacementCommandChangeTarget.h"
#include "UE/I/IMeshVertexCommandChangeTarget.h"
#include "UE/I/IToolFrameworkComponent.h"
#include "UE/U/UMeshComponent.h"

namespace UE::Geometry
{
	class FDynamicMesh3;
}

namespace UE
{
	class FBaseDynamicMeshSceneProxy;
	class UDynamicMesh;

	class UBaseDynamicMeshComponent :
		public UMeshComponent,
		public IToolFrameworkComponent,
		public IMeshVertexCommandChangeTarget,
		public IMeshCommandChangeTarget,
		public IMeshReplacementCommandChangeTarget
	{
	public:
		UE_DEFINE_UOBJECT(UBaseDynamicMeshComponent, UMeshComponent, "Engine", "BaseDynamicMeshComponent");

		// override
		virtual ~UBaseDynamicMeshComponent();  // 000

		// add
		virtual void                                   SetMesh(Geometry::FDynamicMesh3&& a_mesh);                                         //
		virtual const Geometry::FDynamicMesh3*         GetMesh() const;                                                                   //
		virtual Geometry::FDynamicMesh3*               GetMesh();                                                                         //
		virtual void                                   ProcessMesh(TFunctionRef<void(const Geometry::FDynamicMesh3&)> a_function) const;  //
		virtual UDynamicMesh*                          GetDynamicMesh();                                                                  //
		virtual void                                   NotifyMeshUpdated();                                                               //
		virtual void                                   ApplyTransform(const FTransform3d& a_transform, bool a_invert);                    //
		virtual FBaseDynamicMeshSceneProxy*            GetBaseSceneProxy();                                                               //
		virtual void                                   NotifyMaterialSetUpdated();                                                        //
		virtual void                                   SetEnableWireframeRenderPass(bool a_value);                                        //
		virtual bool                                   GetEnableWireframeRenderPass() const;                                              //
		virtual void                                   SetColorOverrideMode(EDynamicMeshComponentColorOverrideMode a_mode);               //
		virtual EDynamicMeshComponentColorOverrideMode GetColorOverrideMode() const;                                                      //
		virtual void                                   SetConstantOverrideColor(FColor a_color);                                          //
		virtual FColor                                 GetConstantOverrideColor() const;                                                  //
		virtual void                                   SetVertexColorSpaceTransformMode(EDynamicMeshVertexColorTransformMode a_mode);     //
		virtual EDynamicMeshVertexColorTransformMode   GetVertexColorSpaceTransformMode() const;                                          //
		virtual void                                   SetEnableFlatShading(bool a_value);                                                //
		virtual bool                                   GetFlatShadingEnabled() const;                                                     //
		virtual void                                   SetShadowsEnabled(bool a_value);                                                   //
		virtual bool                                   GetShadowsEnabled() const;                                                         //
		virtual void                                   SetViewModeOverridesEnabled(bool a_value);                                         //
		virtual bool                                   GetViewModeOverridesEnabled() const;                                               //
		virtual void                                   SetOverrideRenderMaterial(UMaterialInterface* a_material);                         //
		virtual void                                   ClearOverrideRenderMaterial();                                                     //
		virtual bool                                   HasOverrideRenderMaterial(std::int32_t a_index) const;                             //
		virtual UMaterialInterface*                    GetOverrideRenderMaterial(std::int32_t a_index) const;                             //
		virtual void                                   SetSecondaryRenderMaterial(UMaterialInterface* a_material);                        //
		virtual void                                   ClearSecondaryRenderMaterial();                                                    //
		virtual bool                                   HasSecondaryRenderMaterial() const;                                                //
		virtual UMaterialInterface*                    GetSecondaryRenderMaterial() const;                                                //
		virtual void                                   SetSecondaryBuffersVisibility(bool a_value);                                       //
		virtual bool                                   GetSecondaryBuffersVisibility() const;                                             //
		virtual void                                   SetEnableRaytracing(bool a_value);                                                 //
		virtual bool                                   GetEnableRaytracing() const;                                                       //
		virtual void                                   OnRenderingStateChanged(bool a_rebuild);                                           //
		virtual void                                   SetNumMaterials(std::int32_t a_value);                                             //

		// members
		bool                                   explicitShowWireframe;    // 5D0
		FLinearColor                           wireframeColor;           // 5D4
		EDynamicMeshComponentColorOverrideMode colorMode;                // 5E4
		FColor                                 constantColor;            // 5E8
		EDynamicMeshVertexColorTransformMode   colorSpaceMode;           // 5EC
		bool                                   enableFlatShading;        // 5ED
		bool                                   enableViewModeOverrides;  // 5EE
		TObjectPtr<UMaterialInterface>         overrideRenderMaterial;   // 5F0
		TObjectPtr<UMaterialInterface>         secondaryRenderMaterial;  // 5F8
		bool                                   drawSecondaryBuffers;     // 600
		bool                                   enableRaytracing;         // 601
		TArray<TObjectPtr<UMaterialInterface>> baseMaterials;            // 608
	};
	static_assert(sizeof(UBaseDynamicMeshComponent) == 0x620);
}
