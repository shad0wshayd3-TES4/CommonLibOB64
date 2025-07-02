#pragma once

#include "UE/T/TArray.h"

namespace UE
{
	class FKBoxElem;
	class FKConvexElem;
	class FKConvexGeomRenderInfo;
	class FKTaperedCapsuleElem;
	class FKLevelSetElem;
	class FKSkinnedLevelSetElem;
	class FKSphereElem;
	class FKSphylElem;

	class FKAggregateGeom
	{
	public:
		// members
		TArray<FKSphereElem>          sphereElems;           // 000
		TArray<FKBoxElem>             boxElems;              // 010
		TArray<FKSphylElem>           sphylElems;            // 020
		TArray<FKConvexElem>          convexElems;           // 030
		TArray<FKTaperedCapsuleElem>  taperedCapsuleElems;   // 040
		TArray<FKLevelSetElem>        levelSetElems;         // 050
		TArray<FKSkinnedLevelSetElem> skinnedLevelSetElems;  // 060
		FKConvexGeomRenderInfo*       renderInfo;            // 070
	};
	static_assert(sizeof(FKAggregateGeom) == 0x78);
}
