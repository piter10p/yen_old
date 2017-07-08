#include "stdafx.h"
#include "ObjectsManager.h"

using namespace yen;

ObjectsManager::ObjectsManager()
{
	this->idCounter = 0;
}


ObjectsManager::~ObjectsManager()
{
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

bool ObjectsManager::removeObject(ObjectManipulator manipulator)
{
	int index = getObjectListIndex(manipulator.id);

	if (index != -1)
	{
		objects.erase(objects.begin() + index);
		return true;
	}
	return false;
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
		if (objects[i].id = id)
		{
			i;
		}
	}
	return -1;
}