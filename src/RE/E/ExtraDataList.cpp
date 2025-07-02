#include "RE/E/ExtraDataList.h"

namespace RE
{
	void ExtraDataList::RemoveAllCopyableExtra()
	{
		static REL::Relocation<decltype(&ExtraDataList::RemoveAllCopyableExtra)> func{ REL::ID(407191) };
		func(this);
	}

	void ExtraDataList::RemoveNonPersistentCellData()
	{
		static REL::Relocation<decltype(&ExtraDataList::RemoveNonPersistentCellData)> func{ REL::ID(407317) };
		func(this);
	}

	#if 0 // Not sure exactly what each one of these do or what differentiates them yet.

	void ExtraDataList::CopyListForContainer(ExtraDataList* a_other)
	{
		static REL::Relocation<decltype(&ExtraDataList::CopyListForContainer)> func{ REL::ID(407192) };
		func(this, a_other);
	}

	void ExtraDataList::DuplicateExtraListForContainer(ExtraDataList* a_other)
	{
		static REL::Relocation<decltype(&ExtraDataList::DuplicateExtraListForContainer)> func{ REL::ID(407194) };
		func(this, a_other);
	}

	void ExtraDataList::CopyListForReference(ExtraDataList* a_other)
	{
		static REL::Relocation<decltype(&ExtraDataList::CopyListForReference)> func{ REL::ID(407193) };
		func(this, a_other);
	}

	bool ExtraDataList::CompareList(ExtraDataList* a_other) const
	{
		static REL::Relocation<decltype(&ExtraDataList::CompareList)> func{ REL::ID(407189) };
		return func(this, a_other);
	}

	bool ExtraDataList::CompareListForContainer(ExtraDataList* a_other) const
	{
		static REL::Relocation<decltype(&ExtraDataList::CompareListForContainer)> func{ REL::ID(407190) };
		return func(this, a_other);
	}

	void ExtraDataList::Save()
	{
		static REL::Relocation<decltype(&ExtraDataList::Save)> func{ REL::ID(407337) };
		func(this);
	}

	#endif
}
