#pragma once

#include "UE/F/FRotator.h"
#include "UE/F/FVector.h"

namespace UE
{
	enum class EVectorQuantization : std::uint8_t
	{
		RoundWholeNumber,
		RoundOneDecimal,
		RoundTwoDecimals
	};

	enum class ERotatorQuantization : std::uint8_t
	{
		ByteComponents,
		ShortComponents
	};

	class FRepMovement
	{
	public:
		// members
		FVector              linearVelocity;
		FVector              angularVelocity;
		FVector              location;
		FRotator             rotation;
		std::uint8_t         simulatedPhysicSleep: 1;
		std::uint8_t         repPhysics: 1;
		std::int32_t         serverFrame;
		std::int32_t         serverPhysicsHandle;
		EVectorQuantization  locationQuantizationLevel;
		EVectorQuantization  velocityQuantizationLevel;
		ERotatorQuantization rotationQuantizationLevel;
	};
	static_assert(sizeof(FRepMovement) == 0x70);
}
