#pragma once

namespace UE
{
	enum class ECollisionEnabled : std::int32_t
	{
		NoCollision,
		QueryOnly,
		PhysicsOnly,
		QueryAndPhysics,
		ProbeOnly,
		QueryAndProbe
	};
}
