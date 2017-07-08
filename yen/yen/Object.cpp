#include "stdafx.h"
#include "Object.h"

using namespace yen;

Object::Object()
{
	this->position.x = 0;
	this->position.y = 0;

	this->componentsIdCounter = 0;
}


Object::~Object()
{
	removeAllComponents();
}

void Object::setPosition(Vector vector)
{
	this->position.x = vector.x;
	this->position.y = vector.y;
}

ComponentManipulator Object::addComponent(Component *component)
{
	component->id = getNewComponentsId();
	components.push_back(component);

	ComponentManipulator manipulator;
	manipulator.id = component->id;

	return manipulator;
}

Flag Object::removeComponent(ComponentManipulator manipulator)
{
	int index = getComponentListIndex(manipulator.id);
	if (index != -1)
	{
		delete components[index];
		components.erase(components.begin() + index);
		return Flag::OK;
	}
	return Flag::ERROR_NOTHING_FOUND_ID;
}

void Object::callComponentsStepFuncion()
{
	for (int  i = 0; i < components.size(); i++)
	{
		components[i]->step();
	}
}

int Object::getNewComponentsId()
{
	componentsIdCounter++;

	return componentsIdCounter - 1;
}

int Object::getComponentListIndex(int id)
{
	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]->id == id)
			return i;
	}
	return -1;
}

void Object::removeAllComponents()
{
	for (int i = 0; i < components.size(); i++)
	{
		delete components[i];
	}
	components.clear();
}