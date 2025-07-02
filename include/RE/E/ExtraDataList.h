#pragma once

#include "RE/B/BaseExtraList.h"

namespace RE
{
	class ExtraDataList :
		public BaseExtraList
	{
	public:
		inline static constexpr auto RTTI = RTTI::ExtraDataList;
		inline static constexpr auto VTABLE = VTABLE::ExtraDataList;

		// override
		virtual ~ExtraDataList() override;  // 00

		void RemoveAllCopyableExtra();
		void RemoveNonPersistentCellData();
		#if 0 // Not sure exactly what each one of these do or what differentiates them yet.
		void CopyListForContainer(ExtraDataList* a_other);
		void DuplicateExtraListForContainer(ExtraDataList* a_other);
		void CopyListForReference(ExtraDataList* a_other);
		bool CompareList(ExtraDataList* a_other) const;
		bool CompareListForContainer(ExtraDataList* a_other) const;
		void Save();
		#endif
	};
	static_assert(sizeof(ExtraDataList) == 0x20);
}
