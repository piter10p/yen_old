#include "stdafx.h"
#include "MoveComponent.h"

using namespace yen;

MoveComponent::MoveComponent(fVector position)
{
	this->position = position;
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

Flag MoveComponent::load()
{
	return Flag::OK;
}

void MoveComponent::unLoad()
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
