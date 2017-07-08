#include "stdafx.h"
#include "Scene.h"

using namespace yen;

Scene::Scene()
{
}


Scene::~Scene()
{
}

Flag Scene::addObject(Object *object)
{
	if (getObjectListIndex(object->id) != -1)
		return Flag::ERROR_THING_WITH_THIS_ID_HAS_ALREADY_BEEN_ADDED;
	objects.push_back(object);
	return Flag::OK;
}

Flag Scene::removeObject(Object* object)
{
	int index = getObjectListIndex(object->id);
	if (index != -1)
	{
		objects.erase(objects.begin() + index);
		return Flag::OK;
	}
	return Flag::ERROR_NOTHING_FOUND_ID;
}

int Scene::getObjectListIndex(int id)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->id == id)
			return i;
	}
	return -1;
}
