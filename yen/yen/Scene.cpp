#include "stdafx.h"
#include "Scene.h"

using namespace yen;

Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::addObject(Object *object)
{
	objects.push_back(object);
}

bool Scene::removeObject(ObjectManipulator manipulator)
{
	int index = getObjectListIndex(manipulator);
	if (index != -1)
	{
		objects.erase(objects.begin() + index);
		return true;
	}
	return false;
}

int Scene::getObjectListIndex(ObjectManipulator manipulator)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->id == manipulator.id)
			return i;
	}
	return -1;
}