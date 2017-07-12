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

uVector ObjectAccessInterface::getGraphicsPosition()
{
	boost::numeric::converter <unsigned int, float> converter;
	uVector gPosition;
	unsigned int gPosX = converter(this->getPosition().getX());
	unsigned int gPosY = converter(this->getPosition().getY());
	gPosition.set(gPosX, gPosY);
	return gPosition;
}
