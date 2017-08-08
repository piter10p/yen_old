#include "stdafx.h"
#include "Scene.h"

using namespace yen;

Scene::Scene(PhysicsEngine *physicsEngine, ResourceManager *resourceManager)
{
	this->physicsEngine = physicsEngine;
	this->resourceManager = resourceManager;

	worldManipulator = physicsEngine->createWorld();
}


Scene::~Scene()
{
}

void Scene::addObject(Object *object)
{
	if (getIndexOfObjectsListObject(object->getId()) != -1)
	{
		Logger::errorLog(0, "Object with id: " + std::to_string(object->getId()) + " has been added already to scene with id: " + std::to_string(this->getId()) + ".");
		Error e;
		e.flag = Flag::ERROR_THING_WITH_THIS_ID_IS_ALREADY_EXISTS;
		throw e;
	}
	objects.push_back(object);
}

void Scene::removeObject(Object* object)
{
	try
	{
		int index = getIndexOfObjectsListObject(object->getId());
		if (index != -1)
		{
			objects.erase(objects.begin() + index);
			return;
		}
	}
	catch (const std::out_of_range& oor)
	{
		Logger::errorLog(0, "Can not remove object with id : " + std::to_string(object->getId()) + " from scene with id: " + std::to_string(this->getId()) + ". Obejct index is out of range.");
		Error e;
		e.flag = Flag::ERROR_INDEX_OUT_OF_LIST_RANGE;
		throw e;
	}
	catch (...)
	{
		Logger::errorLog(0, "Undefined error in Scene::removeObject() in scene with id: " + std::to_string(this->getId()) + ".");
		Error e;
		e.flag = Flag::ERROR_UNDEFINED;
		throw e;
	}
	
	Logger::errorLog(0, "Can not remove object with id : " + std::to_string(object->getId()) + " from scene with id: " + std::to_string(this->getId()) + ". Object is missing.");
	Error e;
	e.flag = Flag::ERROR_NOTHING_FOUND_ID;
	throw e;
}

void Scene::initialization()
{
	try
	{
		if (!haveActiveCamera())
		{
			Logger::errorLog(0, "Scene with id: " + std::to_string(this->getId()) + " don't have active camera.");
			Error e;
			e.flag = Flag::ERROR_SCENE_DONT_HAVE_CAMERA;
			throw e;
		}

		loadObjects();
		initialized = true;
		unFreeze();
	}
	catch (Error e)
	{
		throw e;
	}
	catch (...)
	{
		Logger::errorLog(0, "Undefined error in Scene::initialization() in sceen with id: " + std::to_string(this->getId()) + ".");
		Error e;
		e.flag = Flag::ERROR_UNDEFINED;
		throw e;
	}
}

void Scene::setActiveCamera(Object* object)
{
	if (object->haveComponentofType("CameraComponent"))
	{
		activeCamera = object;
		return;
	}
	Logger::errorLog(0, "Can not set active camera in scene with id: " + std::to_string(this->getId()) + ". Object with id: " + std::to_string(object->getId()) + " is not a camera.");
	Error e;
	e.flag = Flag::ERROR_OBJECT_DONT_HAVE_COMPONENT_OF_THIS_TYPE;
	throw e;
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

void Scene::codeStepUpdate()
{
	try
	{
		if (!freezed)
		{
			loadObjects();

			for (unsigned int i = 0; i < objects.size(); i++)
			{
				objects[i]->codeStepUpdate(activeCamera->getPosition());
			}
		}
	}
	catch(Error e)
	{
		throw e;
	}
}

void Scene::setGravity(fVector vector)
{
	physicsEngine->setWorldGravity(worldManipulator, vector);
}

bool Scene::test()
{
	Object object;
	
	addObject(&object);
	removeObject(&object);

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

void Scene::loadObjects()
{
	try
	{
		resourceManager->resetResourceUsage();

		for (unsigned int i = 0; i < objects.size(); i++)
		{
			if (isObjectInLoadRange(objects[i]))
			{
				objects[i]->setResourcesUsed();
				objects[i]->unFreeze();
				
			}
			else if (!isObjectInLoadRange(objects[i]))
			{
				objects[i]->freeze();
			}
		}

		resourceManager->loadResources();

		for (unsigned int i = 0; i < objects.size(); i++)
		{
			if (isObjectInLoadRange(objects[i]))
				objects[i]->initialization(worldManipulator);
		}
	}
	catch(Error e)
	{
		throw e;
	}
	catch (FileManipulationError e)
	{
		throw e;
	}
	
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