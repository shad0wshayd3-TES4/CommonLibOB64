#pragma once

namespace UE::Math
{
	using VectorRegister4Float = __m128;
	using VectorRegister4Int = __m128i;
	using VectorRegister2Int64 = __m128i;
	using VectorRegister2Double = __m128d;

	class alignas(16) VectorRegister4Double
	{
	public:
		// members
		VectorRegister2Double xy;
		VectorRegister2Double zw;
	};
	static_assert(sizeof(VectorRegister4Double) == 0x20);

	using PersistentVectorRegister4Float = VectorRegister4Float;
	using PersistentVectorRegister4Double = VectorRegister4Double;

	template <typename T>
	using TPersistentVectorRegisterType = std::conditional_t<std::is_same_v<T, float>, PersistentVectorRegister4Float, std::conditional_t<std::is_same_v<T, double>, PersistentVectorRegister4Double, void>>;

	template <class T>
	struct TAlignOfTransform;

	template <>
	struct TAlignOfTransform<float>
	{
		static constexpr auto Value{ std::max(16ull, alignof(TPersistentVectorRegisterType<float>)) };
	};
	template <>
	struct TAlignOfTransform<double>
	{
		static constexpr auto Value{ std::max(16ull, alignof(TPersistentVectorRegisterType<double>)) };
	};

	template <class T>
	class alignas(TAlignOfTransform<T>::Value) TTransform
	{
	public:
		// members
		TPersistentVectorRegisterType<T> rotation;
		TPersistentVectorRegisterType<T> translation;
		TPersistentVectorRegisterType<T> scale3D;
	};
}
