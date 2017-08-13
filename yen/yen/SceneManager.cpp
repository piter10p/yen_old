#include "stdafx.h"
#include "SceneManager.h"

using namespace yen;

SceneManager::SceneManager(PhysicsEngine *physicsEngine, ResourceManager* resourceManager)
{
	this->physicsEngine = physicsEngine;
	this->resourceManager = resourceManager;
}


SceneManager::~SceneManager()
{
	for (unsigned int i = 0; i < scenes.size(); i++)
	{
		delete scenes[i];
	}
}

SceneManipulator SceneManager::createScene()
{
	Scene *scene = new Scene(physicsEngine);
	scene->setId(getNewId()) ;
	scenes.push_back(scene);

	SceneManipulator manipulator;
	manipulator.id = scene->getId();
	manipulator.scene = scene;

	return manipulator;
}

void SceneManager::removeScene(SceneManipulator manipulator)
{
	try
	{
		int index = getSceneListIndex(manipulator.id);
		if (index != -1)
		{
			delete scenes[index];
			scenes.erase(scenes.begin() + index);
			return;
		}
	}
	catch (const std::out_of_range& oor)
	{
		Logger::errorLog(0, "Can not remove scene with id : " + std::to_string(manipulator.id) + " from Scene Manager. Obejct index is out of range.");
		Error e;
		e.flag = Flag::ERROR_INDEX_OUT_OF_LIST_RANGE;
		throw e;
	}
	Logger::errorLog(0, "Can not remove scene with id : " + std::to_string(manipulator.id) + " from Scene Manager. Obejct is missing.");
	Error e;
	e.flag = Flag::ERROR_NOTHING_FOUND_ID;
	throw e;
}

void SceneManager::addObjectToScene(SceneManipulator sceneManipulator, ObjectManipulator objectManipulator)
{
	try
	{
		sceneManipulator.scene->addObject(objectManipulator.object);
	}
	catch (Error e)
	{
		throw e;
	}
		
	
}

void SceneManager::removeObjectFromScene(SceneManipulator sceneManipulator, ObjectManipulator objectManipulator)
{
	try
	{
		sceneManipulator.scene->removeObject(objectManipulator.object);
	}
	catch (Error e)
	{
		throw e;
	}
	
}

void SceneManager::initializeScene(SceneManipulator manipulator)
{
	try
	{
		manipulator.scene->initialization();
	}
	catch (Error e)
	{
		throw e;
	}
}

void SceneManager::setSceneGravity(SceneManipulator manipulator, fVector vector)
{
	manipulator.scene->setGravity(vector);
}

void SceneManager::freezeScene(SceneManipulator manipulator)
{
	manipulator.scene->freeze();
}

void SceneManager::unFreezeScene(SceneManipulator manipulator)
{
	manipulator.scene->unFreeze();
}

bool SceneManager::isSceneFreezed(SceneManipulator manipulator)
{
	return manipulator.scene->isFreezed();
}

void SceneManager::codeStepUpdate()
{
	try
	{
		for (unsigned int i = 0; i < scenes.size(); i++)
		{
			loadScenes();
			scenes[i]->codeStepUpdate();
		}
	}
	catch (Error e)
	{
		throw e;
	}
	
}

void SceneManager::loadScenes()
{
	resourceManager->resetResourceUsage();

	for (unsigned int i = 0; i < scenes.size(); i++)
	{
		scenes[i]->loadObjects();
	}

	resourceManager->loadResources();

	for (unsigned int i = 0; i < scenes.size(); i++)
	{
		scenes[i]->initializeObjects();
	}
}

bool SceneManager::test()
{
	SceneManipulator manipulator = createScene();
	removeScene(manipulator);

	return true;
}

int SceneManager::getSceneListIndex(int id)
{
	for (int i = 0; i < scenes.size(); i++)
	{
		if (scenes[i]->getId() == id)
			return i;
	}
	return -1;
}