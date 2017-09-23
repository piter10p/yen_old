#include "stdafx.h"
#include "ObjectsManager.h"
#include "Error.h"
#include "Logger.h"

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

void ObjectsManager::removeObject(ObjectManipulator manipulator)
{
	try
	{
		int index = getObjectListIndex(manipulator.id);
		objects.erase(objects.begin() + index);
	}
	catch (Error e)
	{
		throw e;
	}
	catch (const std::out_of_range& oor)
	{
		Error e;
		e.message = "Can not remove object with id : " + std::to_string(manipulator.id) + ". Obehct index is out of range.";
		Logger::errorLog(0, e.message);
		e.flag = Flag::ERROR_INDEX_OUT_OF_LIST_RANGE;
		throw e;
	}
}

void ObjectsManager::attachComponent(ComponentManipulator *comManipulator, ObjectManipulator objManipulator, Component *component)
{
	objManipulator.object->addComponent(comManipulator, component);
}

void ObjectsManager::removeComponent(ObjectManipulator objManipulator, ComponentManipulator comManipulator)
{
	objManipulator.object->removeComponent(comManipulator);
}

void ObjectsManager::setLoadDistance(ObjectManipulator manipulator, float distance)
{
	manipulator.object->setLoadDistance(distance);
}

bool ObjectsManager::test()
{
	ObjectManipulator manipulator = createObject(fVector(0.0f, 0.0f));
	removeObject(manipulator);
	return true;
}

unsigned int ObjectsManager::getObjectListIndex(int id)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->getId() == id)
			return i;
	}
	Error e;
	e.message = std::to_string(id) + " is out of range Objects Manager objects list.";
	Logger::errorLog(0, e.message);
	e.flag = Flag::ERROR_INDEX_OUT_OF_LIST_RANGE;
	throw e;
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