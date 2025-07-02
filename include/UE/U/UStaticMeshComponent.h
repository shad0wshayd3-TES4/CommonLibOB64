#pragma once

#include "UE/U/UMeshComponent.h"

namespace UE::Nanite
{
	class FMaterialAudit;
	class FResources;
}

namespace UE
{
	class FStaticMeshComponentLODInfo;
	class FStaticMeshStaticLightingMesh;
	class FStreamingTextureBuildInfo;
	class ULightComponent;
	class UStaticMesh;

	using FOnGetNaniteResources = TDelegate<const Nanite::FResources*(void)>;

	class UStaticMeshComponent :
		public UMeshComponent
	{
	public:
		UE_DEFINE_UOBJECT(UStaticMeshComponent, UMeshComponent, "Engine", "StaticMeshComponent");

		// override
		virtual ~UStaticMeshComponent();  // 000

		// add
		virtual bool                           SetStaticMesh(UStaticMesh* a_mesh);                                                                                                                                                                                                                                     //
		virtual const Nanite::FResources*      GetNaniteResources() const;                                                                                                                                                                                                                                             //
		virtual bool                           HasValidNaniteData() const;                                                                                                                                                                                                                                             //
		virtual float                          GetTextureStreamingTransformScale() const;                                                                                                                                                                                                                              //
		virtual bool                           UsesTextureLightmaps(std::int32_t a_width, std::int32_t a_height) const;                                                                                                                                                                                                //
		virtual bool                           HasLightmapTextureCoordinates() const;                                                                                                                                                                                                                                  //
		virtual void                           GetTextureLightAndShadowMapMemoryUsage(std::int32_t a_width, std::int32_t a_height, std::int32_t& a_lightMap, std::int32_t& a_shadowMap) const;                                                                                                                         //
		virtual void                           GetEstimatedLightMapResolution(std::int32_t& a_width, std::int32_t& a_height) const;                                                                                                                                                                                    //
		virtual bool                           GetEstimatedLightAndShadowMapMemoryUsage(std::int32_t& a_textureLightMap, std::int32_t& a_textureShadowMap, std::int32_t& a_vertexLightMap, std::int32_t& a_vertexShadowMap, std::int32_t& a_staticResolution, bool& a_textureMapping, bool& a_lightmapTexture) const;  //
		virtual bool                           SupportsDefaultCollision();                                                                                                                                                                                                                                             //
		virtual bool                           SupportsDitheredLODTransitions(ERHIFeatureLevel a_featureLevel);                                                                                                                                                                                                        //
		virtual FPrimitiveSceneProxy*          CreateStaticMeshSceneProxy(Nanite::FMaterialAudit& a_materials, bool a_create);                                                                                                                                                                                         //
		virtual FStaticMeshStaticLightingMesh* AllocateStaticLightingMesh(std::int32_t a_lodIndex, const TArray<ULightComponent*>& a_lights);                                                                                                                                                                          //
		virtual bool                           SetStaticLightingMapping(bool a_textureMapping, std::int32_t a_resolution);                                                                                                                                                                                             //
		virtual const FOnGetNaniteResources&   OnGetNaniteResources() const;                                                                                                                                                                                                                                           //
		virtual FOnGetNaniteResources&         OnGetNaniteResources();                                                                                                                                                                                                                                                 //

		// members
		std::int32_t                        forcedLodModel;                              // 5B0
		std::int32_t                        previousLODLevel_DEPRECATED;                 // 5B4
		std::int32_t                        minLOD;                                      // 5B8
		std::int32_t                        subDivisionStepSize;                         // 5BC
		TObjectPtr<UStaticMesh>             staticMesh;                                  // 5C0
		FColor                              wireframeColorOverride;                      // 5C8
		std::uint8_t                        forceNaniteForMasked: 1;                     // 5CC:0
		std::uint8_t                        disallowNanite: 1;                           // 5CC:1
		std::uint8_t                        forceDisableNanite: 1;                       // 5CC:2
		std::uint8_t                        evaluateWorldPositionOffset: 1;              // 5CC:3
		std::uint8_t                        worldPositionOffsetWritesVelocity: 1;        // 5CC:4
		std::uint8_t                        evaluateWorldPositionOffsetInRayTracing: 1;  // 5CC:5
		std::int32_t                        worldPositionOffsetDisableDistance;          // 5D0
		std::uint8_t                        initialEvaluateWorldPositionOffset: 1;       // 5D4:0
		std::uint8_t                        overrideWireframeColor: 1;                   // 5D4:1
		std::uint8_t                        overrideMinLOD: 1;                           // 5D4:2
		std::uint8_t                        overrideNavigationExport: 1;                 // 5D4:3
		std::uint8_t                        forceNavigationObstacle: 1;                  // 5D4:4
		std::uint8_t                        disallowMeshPaintPerInstance: 1;             // 5D4:5
		std::uint8_t                        ignoreInstanceForTextureStreaming: 1;        // 5D4:6
		std::uint8_t                        overrideLightMapRes: 1;                      // 5D4:7
		std::uint8_t                        castDistanceFieldIndirectShadow: 1;          // 5D5:0
		std::uint8_t                        overrideDistanceFieldSelfShadowBias: 1;      // 5D5:1
		std::uint8_t                        useSubDivisions: 1;                          // 5D5:2
		std::uint8_t                        useDefaultCollision: 1;                      // 5D5:3
		std::uint8_t                        sortTriangles: 1;                            // 5D5:4
		std::uint8_t                        reverseCulling: 1;                           // 5D5:5
		std::int32_t                        overriddenLightMapRes;                       // 5D8
		float                               distanceFieldIndirectShadowMinVisibility;    // 5DC
		float                               distanceFieldSelfShadowBias;                 // 5E0
		float                               streamingDistanceMultiplier;                 // 5E4
		TArray<FStaticMeshComponentLODInfo> lodData;                                     // 5E8
		TArray<FStreamingTextureBuildInfo>  streamingTextureData;                        // 5F8
		std::byte                           lightmassSettings[0x18];                     // 608 - FLightmassPrimitiveSettings
		FOnGetNaniteResources               onGetNaniteResourcesEvent;                   // 620
	};
	static_assert(sizeof(UStaticMeshComponent) == 0x630);
}
