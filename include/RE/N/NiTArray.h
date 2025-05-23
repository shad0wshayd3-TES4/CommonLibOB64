#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	template <class T>
	class NiTArray
	{
	public:
		using value_type = T;
		using size_type = std::uint16_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = T*;
		using const_iterator = const T*;

		NiTArray(std::uint32_t a_maxSize = 0, std::uint32_t a_growBy = 1) :
			_data(0),
			_capacity(static_cast<std::uint16_t>(a_maxSize)),
			_freeIdx(0),
			_size(0),
			_growthSize(static_cast<std::uint16_t>(a_growBy))
		{
			if (_capacity > 0) {
				_data = static_cast<T*>(malloc(sizeof(T) * _capacity));
			}
		}

		virtual ~NiTArray()  // 00
		{
			free(_data);
		}

		reference operator[](size_type a_pos)
		{
			assert(a_pos < capacity());
			return _data[a_pos];
		}

		const_reference operator[](size_type a_pos) const
		{
			assert(a_pos < capacity());
			return _data[a_pos];
		}

		reference front()
		{
			return operator[](0);
		}

		[[nodiscard]] const_reference front() const
		{
			return operator[](0);
		}

		reference back()
		{
			return operator[](capacity() - 1);
		}

		[[nodiscard]] const_reference back() const
		{
			return operator[](capacity() - 1);
		}

		iterator begin()
		{
			return _data;
		}

		[[nodiscard]] const_iterator begin() const
		{
			return _data;
		}

		[[nodiscard]] const_iterator cbegin() const
		{
			return _data;
		}

		iterator end()
		{
			return _data + _capacity;
		}

		[[nodiscard]] const_iterator end() const
		{
			return _data + _capacity;
		}

		[[nodiscard]] const_iterator cend() const
		{
			return _data + _capacity;
		}

		[[nodiscard]] bool empty() const
		{
			return _capacity == 0;
		}

		[[nodiscard]] size_type size() const
		{
			return _size;
		}

		[[nodiscard]] size_type capacity() const
		{
			return _capacity;
		}

	private:
		// members
		T*            _data;        // 08
		std::uint16_t _capacity;    // 10
		std::uint16_t _freeIdx;     // 12
		std::uint16_t _size;        // 14
		std::uint16_t _growthSize;  // 16
	};
	static_assert(sizeof(NiTArray<void*>) == 0x18);

	template <class T>
	class NiTLargeArray
	{
	public:
		using value_type = T;
		using size_type = std::uint32_t;
		using reference = value_type&;
		using const_reference = const value_type&;
		using iterator = T*;
		using const_iterator = const T*;

		NiTLargeArray(std::uint32_t a_maxSize = 0, std::uint32_t a_growBy = 1) :
			_data(0),
			_capacity(a_maxSize),
			_freeIdx(0),
			_size(0),
			_growthSize(a_growBy)
		{
			if (_capacity > 0) {
				_data = static_cast<T*>(malloc(sizeof(T) * _capacity));
			}
		}

		virtual ~NiTLargeArray()  // 00
		{
			free(_data);
		}

		reference operator[](size_type a_pos)
		{
			assert(a_pos < size());
			return _data[a_pos];
		}

		const_reference operator[](size_type a_pos) const
		{
			assert(a_pos < size());
			return _data[a_pos];
		}

		reference front()
		{
			return operator[](0);
		}

		[[nodiscard]] const_reference front() const
		{
			return operator[](0);
		}

		reference back()
		{
			return operator[](size() - 1);
		}

		[[nodiscard]] const_reference back() const
		{
			return operator[](size() - 1);
		}

		iterator begin()
		{
			return _data;
		}

		[[nodiscard]] const_iterator begin() const
		{
			return _data;
		}

		[[nodiscard]] const_iterator cbegin() const
		{
			return _data;
		}

		iterator end()
		{
			return _data + _size;
		}

		[[nodiscard]] const_iterator end() const
		{
			return _data + _size;
		}

		[[nodiscard]] const_iterator cend() const
		{
			return _data + _size;
		}

		[[nodiscard]] bool empty() const
		{
			return _capacity == 0;
		}

		[[nodiscard]] size_type size() const
		{
			return _size;
		}

		[[nodiscard]] size_type capacity() const
		{
			return _capacity;
		}

	private:
		// members
		T*            _data;        // 08
		std::uint32_t _capacity;    // 10
		std::uint32_t _freeIdx;     // 14
		std::uint32_t _size;        // 18
		std::uint32_t _growthSize;  // 1C
	};
	static_assert(sizeof(NiTLargeArray<void*>) == 0x20);
}
