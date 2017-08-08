#pragma once
#include <Box2D.h>
#include "Flag.h"
#include "Vector.h"
#include <vector>
#include "IdSetter.h"
#include "WorldManipulator.h"
#include "World.h"
#include "BodyDef.h"
#include "Time.h"

namespace yen
{
	class PhysicsEngine : public IdSetter
	{
	public:
		PhysicsEngine();
		~PhysicsEngine();

		void initialize();

		WorldManipulator createWorld();
		Flag removeWorld(WorldManipulator);
		void setWorldGravity(WorldManipulator, fVector);

		void step();

		void freezeWorld(WorldManipulator);
		void unFreezeWorld(WorldManipulator);
		bool isWorldFreezed(WorldManipulator);

		fVector getBodyPosition(WorldManipulator, BodyManipulator);
		void unActivateBody(WorldManipulator, BodyManipulator);
		void activateBody(WorldManipulator, BodyManipulator);

		BodyManipulator createBody(WorldManipulator, BodyDef);
		Flag removeBody(WorldManipulator, BodyManipulator);

		void testPrintBodiesPosition();

	private:	
		std::vector <World*> worlds;

		const float stepTime = 0.001f;
		time::FixedTimeLoopTimer timer;

		void clearWorlds();

		b2FixtureDef createFixtureDef(BodyDef);
		b2BodyDef createBodyDef(BodyDef);
		b2PolygonShape* createShape(BodyDef);

		static float pixels2Meters(float);
		static float meters2pixels(float);
		
		static float degrees2radians(float);
		static float radians2degrees(float);

		static b2Vec2 yenfVectorTob2Vec2(fVector, bool pixels2Meters);
		static fVector b2Vec2ToYenfVector(b2Vec2, bool meters2Pixels);
	};
}
