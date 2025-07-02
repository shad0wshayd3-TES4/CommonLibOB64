#pragma once

#include "TESObject.h"

namespace RE
{
	class TESObject;
	class TESObjectCELL;

	class TESObjectList
	{
	public:
		// members
		std::uint32_t  count;  // 00
		TESObject*     head;   // 08
		TESObject*     tail;   // 10
		TESObjectCELL* owner;  // 18

		template<class T, bool FORWARD>
		class iterator_base
		{
		public:
			T& operator*() { return *object_; }
			T* operator->() { return object_; }

			bool operator==(const iterator_base other) const { return other.object_ == object_; }
			bool operator!=(const iterator_base other) const { return !(other == *this); }

			iterator_base operator++()
			{
				if constexpr (FORWARD)
					object_ = object_->next;
				else
					object_ = object_->prev;

				return *this;
			}
			iterator_base operator--()
			{
				if constexpr (FORWARD)
					object_ = object_->prev;
				else
					object_ = object_->next;

				return *this;
			}

		private:
			friend class TESObjectList;

			iterator_base(T* object) :
				object_(object) {}

			T* object_;
		};

		using iterator = iterator_base<TESObject, true>;
		using const_iterator = iterator_base<const TESObject, true>;
		using reverse_iterator = iterator_base<TESObject, false>;
		using const_reverse_iterator = iterator_base<const TESObject, false>;

		iterator                begin() { return iterator{ head }; }
		iterator                end() { return iterator{ nullptr }; }
		const_iterator          begin() const { return const_iterator{ head }; }
		const_iterator          end() const { return const_iterator{ nullptr }; }
		const_iterator          cbegin() const { return begin(); }
		const_iterator          cend() const { return end(); }
		reverse_iterator        rbegin() { return reverse_iterator{ tail }; }
		reverse_iterator        rend() { return reverse_iterator{ nullptr }; }
		const_reverse_iterator  crbegin() const { return const_reverse_iterator{ tail }; }
		const_reverse_iterator  crend() const { return const_reverse_iterator{ nullptr }; }
	};
	static_assert(sizeof(TESObjectList) == 0x20);
}
