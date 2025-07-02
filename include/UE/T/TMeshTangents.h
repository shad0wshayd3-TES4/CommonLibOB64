#pragma once

#include "UE/T/TArray.h"
#include "UE/T/TVector.h"

namespace UE::Geometry
{
	class FDynamicMesh3;

	template <class T>
	class TMeshTangents
	{
	public:
		// members
		const FDynamicMesh3*     mesh;            // 000
		TArray<Math::TVector<T>> tangents;        // 008
		TArray<Math::TVector<T>> bitangents;      // ???
		TArray<std::int32_t>     degenerateTris;  // ???
	};
}
