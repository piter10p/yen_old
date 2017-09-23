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

void Scene::addObject(Object *object)
{
	if (getIndexOfObjectsListObject(object->getId()) != -1)
	{
		Error e;
		e.message = "Object with id: " + std::to_string(object->getId()) + " has been added already to scene with id: " + std::to_string(this->getId()) + ".";
		Logger::errorLog(0, e.message);
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
		Error e;
		e.message = "Can not remove object with id : " + std::to_string(object->getId()) + " from scene with id: " + std::to_string(this->getId()) + ". Obejct index is out of range.";
		Logger::errorLog(0, e.message);
		e.flag = Flag::ERROR_INDEX_OUT_OF_LIST_RANGE;
		throw e;
	}
	catch (...)
	{
		Error e;
		e.message = "Undefined error in Scene::removeObject() in scene with id: " + std::to_string(this->getId()) + ".";
		Logger::errorLog(0, e.message);
		e.flag = Flag::ERROR_UNDEFINED;
		throw e;
	}
	
	Error e;
	e.message = "Can not remove object with id : " + std::to_string(object->getId()) + " from scene with id: " + std::to_string(this->getId()) + ". Object is missing.";
	Logger::errorLog(0, e.message);
	e.flag = Flag::ERROR_NOTHING_FOUND_ID;
	throw e;
}

void Scene::initialization()
{
	try
	{
		if (!haveCamera())
		{
			Error e;
			e.message = "Scene with id: " + std::to_string(this->getId()) + " don't have active camera.";
			Logger::errorLog(0, e.message);
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
		Error e;
		e.message = "Undefined error in Scene::initialization() in sceen with id: " + std::to_string(this->getId()) + ".";
		Logger::errorLog(0, e.message);
		e.flag = Flag::ERROR_UNDEFINED;
		throw e;
	}
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
		std::vector<GraphicsComponent*> graphicsComponents;
		std::vector<CameraComponent*> cameraComponents;

		for (unsigned int i = 0; i < objects.size(); i++)
		{
			if (!objects[i]->isFreezed())
			{
				GraphicsComponent* gc = objects[i]->getGraphicsComponent();
				if (gc != nullptr)
					graphicsComponents.push_back(gc);

				CameraComponent* cc = objects[i]->getCameraComponent();
				if (cc != nullptr)
					cameraComponents.push_back(cc);
			}
		}

		if (!freezed)
		{
			for (unsigned int i = 0; i < objects.size(); i++)
			{
				objects[i]->codeStepUpdate();
			}
		}

		for (unsigned int i = 0; i < cameraComponents.size(); i++)
		{
			cameraComponents[i]->draw(&graphicsComponents);
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

void Scene::loadObjects()
{
	try
	{
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

void Scene::initializeObjects()
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		if (isObjectInLoadRange(objects[i]))
			objects[i]->initialization(worldManipulator);
	}
}

bool Scene::isObjectInLoadRange(Object* object)
{
	float loadDistance = object->getLoadDistance();

	if (loadDistance == 0.0f)
		return true;

	std::vector <Object*> cameras = getCameraObejcts();

	for (unsigned int i = 0; i < cameras.size(); i++)
	{
		if (fVector::getDistance(cameras[i]->getPosition(), object->getPosition()) <= loadDistance)
			return true;
	}
	return false;
}

std::vector <Object*> Scene::getCameraObejcts()
{
	std::vector<Object*> cameraObjects;

	for (unsigned int i = 0; i < objects.size(); i++)
	{
		CameraComponent* cc = objects[i]->getCameraComponent();
		if (cc != nullptr)
			cameraObjects.push_back(objects[i]);
	}

	return cameraObjects;
}

bool Scene::haveCamera()
{
	for (unsigned int i = 0; i < objects.size(); i++)
	{
		CameraComponent* cc = objects[i]->getCameraComponent();
		if (cc != nullptr)
			return true;
	}
	return false;
}