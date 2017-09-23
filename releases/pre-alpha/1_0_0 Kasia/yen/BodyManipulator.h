#pragma once
#include <Box2D.h>

namespace yen
{
	class BodyManipulator
	{
		friend class World;
		friend class PhysicsEngine;
	protected:
		b2Body *body;
	};
}
