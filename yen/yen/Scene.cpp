#include "stdafx.h"
#include "Scene.h"

using namespace yen;

Scene::Scene(PhysicsEngine *physicsEngine)
{
	this->physicsEngine = physicsEngine;

	worldManipulator = physicsEngine->createWorld();
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

Flag Scene::initialization()
{
	if (!haveActiveCamera())
		return Flag::ERROR_SCENE_DONT_HAVE_CAMERA;

	Flag flag = loadObjects();
	if (flag != Flag::OK)
		return flag;


	initialized = true;
	unFreeze();
	return Flag::OK;
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
	physicsEngine->freezeWorld(worldManipulator);
}

void Scene::unFreeze()
{
	freezed = false;
	physicsEngine->unFreezeWorld(worldManipulator);
}

bool Scene::isFreezed()
{
	return freezed;
}

Flag Scene::codeStepUpdate()
{
	if (!freezed)
	{
		Flag flag = loadObjects();
		if (flag != Flag::OK)
			return flag;

		for (unsigned int i = 0; i < objects.size(); i++)
		{
			objects[i]->codeStepUpdate(activeCamera->getPosition());
		}
	}

	return Flag::OK;
}

void Scene::setGravity(fVector vector)
{
	physicsEngine->setWorldGravity(worldManipulator, vector);
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

Flag Scene::loadObjects()
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if (isObjectHasToBeLoaded(objects[i]))
		{
			Flag flag = objects[i]->load();
			if (flag != Flag::OK)
				return flag;
			objects[i]->initialization(worldManipulator);
		}
		else if(isObjectHasToBeUnLoaded(objects[i]))
		{
			objects[i]->unLoad();
		}
	}

	return Flag::OK;
}

bool Scene::isObjectInLoadRange(Object* object)
{
	float loadDistance = object->getLoadDistance();

	if (loadDistance == 0.0f)
		return true;

	if (fVector::getDistance(activeCamera->getPosition(), object->getPosition()) <= loadDistance)
		return true;
	return false;
}

bool Scene::isObjectHasToBeLoaded(Object* object)
{
	if (!object->isLoaded() && isObjectInLoadRange(object))
		return true;
	return false;
}

bool Scene::isObjectHasToBeUnLoaded(Object* object)
{
	if (object->isLoaded() && !isObjectInLoadRange(object))
		return true;
	return false;
}