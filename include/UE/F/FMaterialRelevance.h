#pragma once

namespace UE
{
	class FMaterialRelevance
	{
	public:
		// members
		std::uint16_t shadingModelMask;                 // 000
		std::uint8_t  strataUintPerPixel;               // 002
		std::uint8_t  strataBSDFCountMask;              // 003
		std::uint8_t  usesComplexSpecialRenderPath: 1;  // 004:0
		std::uint8_t  opaque: 1;                        // 004:1
		std::uint8_t  masked: 1;                        // 004:2
		std::uint8_t  distortion: 1;                    // 004:3
		std::uint8_t  hairStrands: 1;                   // 004:4
		std::uint8_t  twoSided: 1;                      // 004:5
		std::uint8_t  separateTranslucency: 1;          // 004:6
		std::uint8_t  translucencyModulate: 1;          // 004:7
		std::uint8_t  postMotionBlurTranslucency: 1;    // 005:0
		std::uint8_t  normalTranslucency: 1;            // 005:1
		std::uint8_t  usesSceneColorCopy: 1;            // 005:2
		std::uint8_t  outputsTranslucentVelocity: 1;    // 005:3
		std::uint8_t  usesGlobalDistanceField: 1;       // 005:4
		std::uint8_t  usesWorldPositionOffset: 1;       // 005:5
		std::uint8_t  usesDisplacement: 1;              // 005:6
		std::uint8_t  usesPixelDepthOffset: 1;          // 005:7
		std::uint8_t  decal: 1;                         // 006:0
		std::uint8_t  translucentSurfaceLighting: 1;    // 006:1
		std::uint8_t  usesSceneDepth: 1;                // 006:2
		std::uint8_t  usesSkyMaterial: 1;               // 006:3
		std::uint8_t  usesSingleLayerWaterMaterial: 1;  // 006:4
		std::uint8_t  hasVolumeMaterialDomain: 1;       // 006:5
		std::uint8_t  customDepthStencilUsageMask: 2;   // 006:6
		std::uint8_t  usesDistanceCullFade: 1;          // 007:0
		std::uint8_t  disableDepthTest: 1;              // 007:1
		std::uint8_t  usesAnisotropy: 1;                // 007:2
	};
	static_assert(sizeof(FMaterialRelevance) == 0x8);
}
