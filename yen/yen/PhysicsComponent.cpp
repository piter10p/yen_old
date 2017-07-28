#include "stdafx.h"
#include "PhysicsComponent.h"
#include "PhysicsEngine.h"

using namespace yen;

PhysicsComponent::PhysicsComponent(PhysicsEngine *physicsEngine, BodyDef bodyDef, fVector centerOffset)
{
	this->physicsEngine = physicsEngine;
	this->bodyDef = bodyDef;
	this->centerOffset = centerOffset;
}


PhysicsComponent::~PhysicsComponent()
{
	type = "PhysicsComponent";
	physicsEngine->removeBody(worldManipulator, bodyManipulator);
}

void PhysicsComponent::codeStepUpdate(ObjectAccessInterface accessInterface)
{
	fVector position = physicsEngine->getBodyPosition(worldManipulator, bodyManipulator);
	position -= centerOffset;
	accessInterface.setPosition(position);
}

void PhysicsComponent::initialization(ObjectAccessInterface accessInterface)
{
   	if (!initialized)
	{
		bodyManipulator = physicsEngine->createBody(accessInterface.getWorldManipulator(), bodyDef);
		worldManipulator = accessInterface.getWorldManipulator();
		initialized = true;
	}
	physicsEngine->avtivateBody(worldManipulator, bodyManipulator);
}

Flag PhysicsComponent::load()
{
	return Flag::OK;
}

void PhysicsComponent::unLoad()
{
	physicsEngine->unActivateBody(worldManipulator, bodyManipulator);
}