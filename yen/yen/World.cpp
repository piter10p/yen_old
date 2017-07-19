#include "stdafx.h"
#include "World.h"
#include <iostream>

using namespace yen;

World::World()
{
	world = new b2World(gravityVector);
}


World::~World()
{
}

void World::setGravity(b2Vec2 vector)
{
	gravityVector = vector;
	world->SetGravity(gravityVector);
}

void World::step()
{
	if(!freezed)
		world->Step(World::deltaTime, World::velocityIt, World::positionIt);
}

BodyManipulator World::createBody(b2BodyDef bodyDef, b2FixtureDef fixtureDef)
{
	b2Body *body = world->CreateBody(&bodyDef);
	body->CreateFixture(&fixtureDef);

	BodyManipulator manipulator;
	manipulator.body = body;

	bodies.push_back(body);

	return manipulator;
}

Flag World::removeBody(BodyManipulator manipulator)
{
	for (unsigned int i = 0; i < bodies.size(); i++)
	{
		if (bodies[i] == manipulator.body)
		{
			bodies.erase(bodies.begin() + i);
			return Flag::OK;
		}	
	}
	return Flag::ERROR_NO_BODY_FOUNDED;
}

void World::freeze()
{
	freezed = true;
}

void World::unFreeze()
{
	freezed = false;
}

bool World::isFreezed()
{
	return freezed;
}

b2Vec2 World::getBodyPosition(BodyManipulator manipulator)
{
	return manipulator.body->GetPosition();
}

void World::testPrintBodiesPosition()
{
	for (unsigned int i = 0; i < bodies.size(); i++)
	{
		std::cout << bodies[i]->GetPosition().x << "/" << bodies[i]->GetPosition().y << std::endl;
	}
}

