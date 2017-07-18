#include "stdafx.h"
#include "PhysicsEngine.h"
#include <boost\convert.hpp>

using namespace yen;

PhysicsEngine::PhysicsEngine()
{
	timer.setElapseTime(PhysicsEngine::stepTime);
}


PhysicsEngine::~PhysicsEngine()
{
	clearWorlds();
}

void PhysicsEngine::initialize()
{
	for (unsigned int i = 0; i < worlds.size(); i++)
	{
		worlds[i]->unFreeze();
	}

	timer.start();
}

WorldManipulator PhysicsEngine::createWorld()
{
	World *world = new World();
	WorldManipulator manipulator;

	manipulator.id = getNewId();
	manipulator.world = world;

	worlds.push_back(world);

	return manipulator;
}

Flag PhysicsEngine::removeWorld(WorldManipulator manipulator)
{
	for (unsigned int i = 0; i < worlds.size(); i++)
	{
		if (worlds[i]->getId() == manipulator.id)
		{
			delete worlds[i];
			return Flag::OK;
		}
	}
	return Flag::ERROR_NOTHING_FOUND_ID;
}

void PhysicsEngine::setWorldGravity(WorldManipulator manipulator, fVector vector)
{
	manipulator.world->setGravity(yenfVectorTob2Vec2(vector));
}

void PhysicsEngine::step()
{
	while (timer.isTimeElapsed())
	{
		for (unsigned int i = 0; i < worlds.size(); i++)
		{
			worlds[i]->step();
		}
	}
}

void PhysicsEngine::freezeWorld(WorldManipulator worldManipulator)
{
	worldManipulator.world->freeze();
}

void PhysicsEngine::unFreezeWorld(WorldManipulator worldManipulator)
{
	worldManipulator.world->freeze();
}

bool PhysicsEngine::isWorldFreezed(WorldManipulator worldManipulator)
{
	return worldManipulator.world->isFreezed();
}


BodyManipulator PhysicsEngine::createBody(WorldManipulator worldManipulator, BodyDef def)
{
	b2FixtureDef fixtureDef = createFixtureDef(def);
	b2BodyDef bodyDef = createBodyDef(def);

	return worldManipulator.world->createBody(bodyDef, fixtureDef);
}

Flag PhysicsEngine::removeBody(WorldManipulator worldManipulator, BodyManipulator bodyManipulator)
{
	return worldManipulator.world->removeBody(bodyManipulator);
}

void PhysicsEngine::testPrintBodiesPosition()
{
	for (unsigned int i = 0; i < worlds.size(); i++)
	{
		worlds[i]->testPrintBodiesPosition();
	}
}

void PhysicsEngine::clearWorlds()
{
	for (unsigned int i = 0; i < worlds.size(); i++)
	{
		delete worlds[i];
	}
	worlds.clear();
}

b2FixtureDef PhysicsEngine::createFixtureDef(BodyDef bodyDef)
{
	b2FixtureDef fixtureDef;
	fixtureDef.density = bodyDef.density;
	fixtureDef.friction = bodyDef.friction;
	fixtureDef.isSensor = bodyDef.isSensor;
	fixtureDef.restitution = bodyDef.restitution;
	fixtureDef.shape = createShape(bodyDef);
	return fixtureDef;
}

b2BodyDef PhysicsEngine::createBodyDef(BodyDef bodyDef)
{
	b2BodyDef def;
	def.position = yenfVectorTob2Vec2(bodyDef.position);
	if (bodyDef.type == BodyType::STATIC)
		def.type = b2BodyType::b2_staticBody;
	if (bodyDef.type == BodyType::DYNAMIC)
		def.type = b2BodyType::b2_dynamicBody;
	return def;
}

b2PolygonShape* PhysicsEngine::createShape(BodyDef bodyDef)
{
	b2Vec2 shapeSize = yenfVectorTob2Vec2(bodyDef.shapeSize);
	shapeSize.x = shapeSize.x / 2.0f;
	shapeSize.y = shapeSize.y / 2.0f;

	b2PolygonShape *shape = new b2PolygonShape();
	shape->SetAsBox(shapeSize.x, shapeSize.y);
	return shape;
}

float PhysicsEngine::pixels2Meters(float pixels)
{
	return pixels * 0.02f;
}

float PhysicsEngine::meters2pixels(float meters)
{
	return meters * 50.0f;
}

float PhysicsEngine::degrees2radians(float degrees)
{
	return b2_pi * degrees / 180.0f;
}

float PhysicsEngine::radians2degrees(float radians)
{
	return 180.0f * radians / b2_pi;
}

b2Vec2 PhysicsEngine::yenfVectorTob2Vec2(fVector vectorIn)
{
	b2Vec2 vectorOut;
	vectorOut.x = pixels2Meters(vectorIn.getX());
	vectorOut.y = pixels2Meters(vectorIn.getY());

	return vectorOut;
}

fVector PhysicsEngine::b2Vec2ToYenfVector(b2Vec2 vectorIn)
{
	return fVector(meters2pixels(vectorIn.x), meters2pixels(vectorIn.y));
}
