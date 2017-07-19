#include "stdafx.h"
#include "ObjectAccessInterface.h"
#include <boost\numeric\conversion\converter.hpp>

using namespace yen;

ObjectAccessInterface::ObjectAccessInterface()
{
}


ObjectAccessInterface::~ObjectAccessInterface()
{
}

void ObjectAccessInterface::setPosition(fVector position)
{
	*this->position = position;
}

void ObjectAccessInterface::move(fVector shift)
{
	*this->position += shift;
}

fVector ObjectAccessInterface::getPosition()
{
	return *this->position;
}

fVector ObjectAccessInterface::getCameraPosition()
{
	return cameraPosition;
}

WorldManipulator ObjectAccessInterface::getWorldManipulator()
{
	return worldManipulator;
}
