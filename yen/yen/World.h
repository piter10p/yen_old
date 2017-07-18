#pragma once
#include <Box2D.h>
#include "Flag.h"
#include <vector>
#include "BodyDef.h"
#include "BodyManipulator.h"
#include "Id.h"

namespace yen
{
	class World : public Id
	{
	public:
		World();
		~World();

		void setGravity(b2Vec2);

		void step();

		BodyManipulator createBody(b2BodyDef, b2FixtureDef);
		Flag removeBody(BodyManipulator);

		void freeze();
		void unFreeze();
		bool isFreezed();

		void testPrintBodiesPosition();

	private:
		b2World *world;
		b2Vec2 gravityVector = b2Vec2(0.0f, 0.0f);

		const float32 deltaTime = 0.01f;
		const int velocityIt = 8, positionIt = 3;

		bool freezed = true;

		std::vector <b2Body*> bodies;
	};
}
