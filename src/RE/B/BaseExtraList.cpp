#include "RE/B/BaseExtraList.h"
#include "RE/B/BSExtraData.h"

namespace RE
{
	BSExtraData* BaseExtraList::GetExtraData(ExtraDataType a_type) const
	{
		if (!HasExtraData(a_type))
			return nullptr;

		for (const BSExtraData& data : *this)
		{
			if (data.type == a_type)
				return const_cast<BSExtraData*>(&data);
		}

		return nullptr;
	}

	bool BaseExtraList::HasExtraData(ExtraDataType a_type) const
	{
		if (a_type >= ExtraDataType::Max)
			return false;

		return (flags[(std::uint8_t)a_type >> 3] >> ((std::uint8_t)a_type & 7)) & 1;
	}

	std::int32_t BaseExtraList::ItemsInList() const
	{
		static REL::Relocation<decltype(&BaseExtraList::ItemsInList)> func{ REL::ID(407290) };
		return func(this);
	}

	void BaseExtraList::AddExtra(BSExtraData* a_extra)
	{
		static REL::Relocation<decltype(&BaseExtraList::AddExtra)> func{ REL::ID(407178) };
		func(this, a_extra);
	}

	void BaseExtraList::RemoveExtra(ExtraDataType a_type)
	{
		static REL::Relocation<decltype(&BaseExtraList::RemoveExtra)> func{ REL::ID(407306) };
		func(this, a_type);
	}

	void BaseExtraList::RemoveAll()
	{
		static REL::Relocation<decltype(&BaseExtraList::RemoveAll)> func{ REL::ID(407170) };
		func(this);
	}
}
