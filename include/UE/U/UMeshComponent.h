#pragma once

#include "UE/E/ELODStreamingCallbackResult.h"
#include "UE/F/FMaterialRelevance.h"
#include "UE/T/TSortedMap.h"
#include "UE/U/UPrimitiveComponent.h"

namespace UE
{
	class FNameFastLess;
	class FPrimitiveMaterialInfo;
	class UMaterialInterface;
	class UStreamableRenderAsset;

	using FLODStreamingCallback = TFunction<void(UPrimitiveComponent*, UStreamableRenderAsset*, ELODStreamingCallbackResult)>;

	class UMeshComponent :
		public UPrimitiveComponent
	{
	public:
		UE_DEFINE_UOBJECT(UMeshComponent, UPrimitiveComponent, "Engine", "MeshComponent");

		class FMaterialParameterCache
		{
		public:
			// members
			TArray<std::int32_t> scalarParameterMaterialIndices;
			TArray<std::int32_t> vectorParameterMaterialIndices;
			float                scalarParameterDefaultValue{ 0.0F };
		};
		static_assert(sizeof(FMaterialParameterCache) == 0x28);

		// override
		virtual ~UMeshComponent();  // 000

		// add
		virtual TArray<UMaterialInterface*> GetMaterials() const;                                                                                                                    //
		virtual std::int32_t                GetMaterialIndex(FName a_slotName) const;                                                                                                //
		virtual TArray<FName>               GetMaterialSlotNames() const;                                                                                                            //
		virtual bool                        IsMaterialSlotNameValid(FName a_slotName) const;                                                                                         //
		virtual bool                        UseNaniteOverrideMaterials() const;                                                                                                      //
		virtual std::int32_t                GetNumOverrideMaterials() const;                                                                                                         //
		virtual FMaterialRelevance          GetMaterialRelevance(ERHIFeatureLevel a_featureLevel) const;                                                                             //
		virtual void                        SetTextureForceResidentFlag(bool a_value);                                                                                               //
		virtual void                        PrestreamTextures(float a_seconds, bool a_prioritizeCharacter, std::int32_t a_cinematicTextureGroups = 0);                               //
		virtual void                        RegisterLODStreamingCallback(FLODStreamingCallback&& a_start, FLODStreamingCallback&& a_end, float a_timeoutStart, float a_timeoutEnd);  //
		virtual void                        RegisterLODStreamingCallback(FLODStreamingCallback&& a_start, std::int32_t a_index, float a_timeout, bool a_onStream);                   //
		virtual bool                        GetMaterialStreamingData(std::int32_t a_index, FPrimitiveMaterialInfo& a_data);                                                          //
		virtual UMaterialInterface*         GetDefaultOverlayMaterial() const;                                                                                                       //
		virtual float                       GetDefaultOverlayMaterialMaxDrawDistance() const;                                                                                        //

		// members
		std::byte                                                                    overrideMaterials[8];                       // 580 - ???
		TObjectPtr<UMaterialInterface>                                               overlayMaterial;                            // 588
		float                                                                        overlayMaterialMaxDrawDistance;             // 590
		TSortedMap<FName, FMaterialParameterCache, FDefaultAllocator, FNameFastLess> materialParameterCache;                     // 598
		std::uint8_t                                                                 enableMaterialParameterCaching: 1;          // 5A8:0
		std::uint8_t                                                                 cachedMaterialParameterIndicesAreDirty: 1;  // 5A8:1
	};
	static_assert(sizeof(UMeshComponent) == 0x5B0);
}
