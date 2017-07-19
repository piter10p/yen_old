#pragma once
#include "Component.h"

namespace yen
{
	class PhysicsComponent : public Component
	{
	public:
		PhysicsComponent(PhysicsEngine*, BodyDef, fVector);
		~PhysicsComponent();

		void codeStepUpdate(ObjectAccessInterface);
		void initialization(ObjectAccessInterface);
		Flag load();

	private:
		PhysicsEngine *physicsEngine;
		BodyDef bodyDef;
		BodyManipulator bodyManipulator;
		WorldManipulator worldManipulator;
		fVector centerOffset;
	};
}
