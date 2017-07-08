#include "stdafx.h"
#include "ObjectsManager.h"

using namespace yen;

ObjectsManager::ObjectsManager()
{
	this->idCounter = 0;
}


ObjectsManager::~ObjectsManager()
{
	clearAllObjects();
}

ObjectManipulator ObjectsManager::createObject()
{
	Object object;
	object.id = getNewId();

	objects.push_back(object);

	ObjectManipulator manipulator;
	manipulator.id = object.id;
	manipulator.object = &objects[getObjectListIndex(object.id)];

	return manipulator;
}

Flag ObjectsManager::removeObject(ObjectManipulator manipulator)
{
	int index = getObjectListIndex(manipulator.id);

	if (index != -1)
	{
		objects.erase(objects.begin() + index);
		return Flag::OK;
	}
	return Flag::ERROR_NOTHING_FOUND_ID;
}

ComponentManipulator ObjectsManager::attachComponent(ObjectManipulator manipulator, Component *component)
{
	return manipulator.object->addComponent(component);
}

Flag ObjectsManager::removeComponent(ObjectManipulator objManipulator, ComponentManipulator comManipulator)
{
	return objManipulator.object->removeComponent(comManipulator);
}

int ObjectsManager::getNewId()
{
	this->idCounter++;

	return this->idCounter - 1;
}

int ObjectsManager::getObjectListIndex(int id)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i].id == id)
			return i;
	}
	return -1;
}

void ObjectsManager::clearAllObjects()
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i].removeAllComponents();
	}
	objects.clear();
}