#pragma once

#include "UE/E/ENavDataGatheringMode.h"
#include "UE/F/FBox.h"

namespace UE
{
	class FNavigableGeometryExport;
	class FNavigationRelevantData;
	class UObject;

	class INavRelevantInterface
	{
	public:
		// add
		virtual ~INavRelevantInterface();                                                                                  // 000
		virtual UObject*              _GetUObject();                                                                       // 001
		virtual void                  GetNavigationData(FNavigationRelevantData& a_data) const;                            // 002
		virtual FBox                  GetNavigationBounds() const;                                                         // 003
		virtual bool                  SupportsGatheringGeometrySlices() const;                                             // 004
		virtual void                  GatherGeometrySlice(FNavigableGeometryExport& a_export, const FBox& a_slice) const;  // 005
		virtual ENavDataGatheringMode GetGeometryGatheringMode() const;                                                    // 006
		virtual void                  PrepareGeometryExportSync();                                                         // 007
		virtual void                  UpdateNavigationBounds();                                                            // 008
		virtual bool                  IsNavigationRelevant() const;                                                        // 009
		virtual UObject*              GetNavigationParent() const;                                                         // 00A
	};
}
