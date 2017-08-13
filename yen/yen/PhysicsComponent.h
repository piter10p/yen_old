#pragma once
#include "Component.h"

namespace yen
{
	class PhysicsComponent : public Component
	{
	public:
		PhysicsComponent(PhysicsEngine*, BodyDef);
		~PhysicsComponent();

		void codeStepUpdate(ObjectAccessInterface);
		void initialization(ObjectAccessInterface);
		void setResourcesUsed();

		void applyForce(fVector force);
		void applyForce(fVector force, fVector forcePoint);
		void setVelocity(fVector velocity);

		void freezed();
		void unFreezed();

	private:
		PhysicsEngine *physicsEngine;
		BodyDef bodyDef;
		BodyManipulator bodyManipulator;
		WorldManipulator worldManipulator;
		fVector centerOffset;
		bool initialized = false;
	};
}
