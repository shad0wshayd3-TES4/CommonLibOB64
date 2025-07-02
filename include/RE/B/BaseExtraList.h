#pragma once

#include "BSExtraData.h"

namespace RE
{
	class BaseExtraList
	{
	public:
		inline static constexpr auto RTTI = RTTI::BaseExtraList;
		inline static constexpr auto VTABLE = VTABLE::BaseExtraList;

		// add
		virtual ~BaseExtraList();  // 00

		[[nodiscard]] BSExtraData* GetExtraData(ExtraDataType a_type) const;
		[[nodiscard]] bool         HasExtraData(ExtraDataType a_type) const;
		void                       RemoveAll();
		[[nodiscard]] std::int32_t ItemsInList() const;
		void                       AddExtra(BSExtraData* a_extra);
		void                       RemoveExtra(ExtraDataType a_type);

		template<class T>
		[[nodiscard]] inline T* GetExtraData()
		{
			return static_cast<T*>(GetExtraData(T::EXTRADATATYPE));
		}

		// members
		BSExtraData* head;       // 08
		std::uint8_t flags[16];  // 10

		// iterators
		template <class T>
		class iterator_base
		{
		public:
			T& operator*() { return *data_; }
			T* operator->() { return data_; }

			bool operator==(const iterator_base other) const { return other.data_ == data_; }
			bool operator!=(const iterator_base other) const { return !(other == *this); }

			iterator_base operator++()
			{
				data_ = data_->next;
				return *this;
			}

		private:
			friend class BaseExtraList;

			iterator_base(T* data) :
				data_(data) {}

			T* data_;
		};

		using iterator = iterator_base<BSExtraData>;
		using const_iterator = iterator_base<const BSExtraData>;

		iterator               begin() { return iterator{ head }; }
		iterator               end() { return iterator{ nullptr }; }
		const_iterator         begin() const { return const_iterator{ head }; }
		const_iterator         end() const { return const_iterator{ nullptr }; }
		const_iterator         cbegin() const { return const_iterator{ head }; }
		const_iterator         cend() const { return const_iterator{ nullptr }; }
	};
	static_assert(sizeof(BaseExtraList) == 0x20);
}
