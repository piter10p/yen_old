#include "stdafx.h"
#include "ObjectsManager.h"

using namespace yen;

ObjectsManager::ObjectsManager()
{
}


ObjectsManager::~ObjectsManager()
{
	clearAllObjects();
}

ObjectManipulator ObjectsManager::createObject(fVector position)
{
	Object *object = new Object();
	object->setId(getNewId());
	object->setPosition(position);

	objects.push_back(object);

	ObjectManipulator manipulator;
	manipulator.id = object->getId();
	manipulator.object = objects[getObjectListIndex(object->getId())];

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

Flag ObjectsManager::attachComponent(ComponentManipulator *comManipulator, ObjectManipulator objManipulator, Component *component)
{
	return objManipulator.object->addComponent(comManipulator, component);
}

Flag ObjectsManager::removeComponent(ObjectManipulator objManipulator, ComponentManipulator comManipulator)
{
	return objManipulator.object->removeComponent(comManipulator);
}

void ObjectsManager::setLoadDistance(ObjectManipulator manipulator, float distance)
{
	manipulator.object->setLoadDistance(distance);
}

bool ObjectsManager::test()
{
	ObjectManipulator manipulator = createObject(fVector(0.0f, 0.0f));
	Flag flag = removeObject(manipulator);
	if (flag != Flag::OK)
		return false;
	return true;
}

int ObjectsManager::getObjectListIndex(int id)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->getId() == id)
			return i;
	}
	return -1;
}

void ObjectsManager::clearAllObjects()
{
	for (int i = 0; i < objects.size(); i++)
	{
		objects[i]->removeAllComponents();
		delete objects[i];
	}
	objects.clear();
}