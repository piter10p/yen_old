#include "stdafx.h"
#include "MoveComponent.h"

using namespace yen;

MoveComponent::MoveComponent(fVector position)
{
	this->position = position;
	this->type = "MoveComponent";
}


MoveComponent::~MoveComponent()
{
}

void MoveComponent::codeStepUpdate(ObjectAccessInterface accessInterface)
{
	if (timer.isTimeElapsed())
	{
		accessInterface.setPosition(position);
		position = accessInterface.getPosition();
	}
}

void MoveComponent::initialization(ObjectAccessInterface accessInterface)
{
	timer.setElapseTime(elapseTime);
	timer.start();
}

void MoveComponent::setResourcesUsed()
{
}

void MoveComponent::freezed()
{
}

void MoveComponent::unFreezed()
{
}

void MoveComponent::move(fVector vector)
{
	position += vector;
}

void MoveComponent::setPosition(fVector vector)
{
	position = vector;
}
