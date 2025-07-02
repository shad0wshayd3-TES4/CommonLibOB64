#pragma once

#include "UE/T/TArray.h"

namespace UE::Chaos
{
	class FGeometryParticle;
	class FPhysicsObject;

	using FPhysicsObjectId = std::int32_t;
}

namespace UE
{
	class IPhysicsComponent
	{
	public:
		virtual ~IPhysicsComponent();                                                                                // 000
		virtual UObject*                       _GetUObject();                                                        // 001
		virtual Chaos::FPhysicsObject*         GetPhysicsObjectById(Chaos::FPhysicsObjectId a_id) const = 0;         // 002
		virtual Chaos::FPhysicsObject*         GetPhysicsObjectByName(const FName& a_name) const = 0;                // 003
		virtual TArray<Chaos::FPhysicsObject*> GetAllPhysicsObjects() const = 0;                                     // 004
		virtual Chaos::FPhysicsObjectId        GetIdFromGTParticle(Chaos::FGeometryParticle* a_particle) const = 0;  // 005
	};
}
