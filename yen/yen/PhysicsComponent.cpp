#include "stdafx.h"
#include "PhysicsComponent.h"
#include "PhysicsEngine.h"

using namespace yen;

PhysicsComponent::PhysicsComponent(PhysicsEngine *physicsEngine, BodyDef bodyDef, fVector centerOffset)
{
	this->physicsEngine = physicsEngine;
	this->bodyDef = bodyDef;
	this->centerOffset = centerOffset;
	this->type = "PhysicsComponent";
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
	physicsEngine->activateBody(worldManipulator, bodyManipulator);
}

void PhysicsComponent::setResourcesUsed()
{
}

void PhysicsComponent::applyForce(fVector force)
{
	physicsEngine->applyForceToBody(bodyManipulator, force);
}

void PhysicsComponent::applyForce(fVector force, fVector forcePoint)
{
	physicsEngine->applyForceToBody(bodyManipulator, force, forcePoint);
}

void PhysicsComponent::setVelocity(fVector velocity)
{
	physicsEngine->setVelocityToBody(bodyManipulator, velocity);
}

void PhysicsComponent::freezed()
{
	if (initialized)
		physicsEngine->unActivateBody(worldManipulator, bodyManipulator);
}

void PhysicsComponent::unFreezed()
{
	if (initialized)
		physicsEngine->activateBody(worldManipulator, bodyManipulator);
}
