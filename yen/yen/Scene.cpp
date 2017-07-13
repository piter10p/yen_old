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
	if (getIndexOfObjectsListObject(object->getId()) != -1)
		return Flag::ERROR_THING_WITH_THIS_ID_IS_ALREADY_EXISTS;
	objects.push_back(object);
	return Flag::OK;
}

Flag Scene::removeObject(Object* object)
{
	int index = getIndexOfObjectsListObject(object->getId());
	if (index != -1)
	{
		objects.erase(objects.begin() + index);
		return Flag::OK;
	}
	return Flag::ERROR_NOTHING_FOUND_ID;
}

Flag Scene::load()
{
	if (!haveActiveCamera())
		return Flag::ERROR_SCENE_DONT_HAVE_CAMERA;

	for (unsigned int i = 0; i < objects.size(); i++)
	{
		Flag flag = objects[i]->load();
		if (flag != Flag::OK)
			return flag;
	}
	initialized = false;
	return Flag::OK;
}

void Scene::initialization()
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		objects[i]->initialization();
	}

	initialized = true;
	freezed = false;
}

Flag Scene::setActiveCamera(Object* object)
{
	if (object->haveComponentofType("CameraComponent"))
	{
		activeCamera = object;
		return Flag::OK;
	}
	return Flag::ERROR_OBJECT_DONT_HAVE_COMPONENT_OF_THIS_TYPE;
}

void Scene::freeze()
{
	freezed = true;
}

void Scene::unFreeze()
{
	freezed = false;
}

bool Scene::isFreezed()
{
	return freezed;
}

void Scene::codeStepUpdate()
{
	if (!freezed)
	{
		for (unsigned int i = 0; i < objects.size(); i++)
		{
			objects[i]->codeStepUpdate(activeCamera->getPosition());
		}
	}
}

bool Scene::test()
{
	Object object;
	
	Flag flag = addObject(&object);
	if (flag != Flag::OK)
		return false;

	flag = removeObject(&object);
	if (flag != Flag::OK)
		return false;

	return true;
}

int Scene::getIndexOfObjectsListObject(int id)
{
	for (int i = 0; i < objects.size(); i++)
	{
		if (objects[i]->getId() == id)
			return i;
	}
	return -1;
}

bool Scene::haveActiveCamera()
{
	if (activeCamera->haveComponentofType("CameraComponent"))
		return true;
	return false;
}