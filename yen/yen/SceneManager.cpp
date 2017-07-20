#include "stdafx.h"
#include "SceneManager.h"

using namespace yen;

SceneManager::SceneManager(PhysicsEngine *physicsEngine)
{
	this->physicsEngine = physicsEngine;
}


SceneManager::~SceneManager()
{
}

SceneManipulator SceneManager::createScene()
{
	Scene scene(physicsEngine);
	scene.setId(getNewId()) ;
	scenes.push_back(scene);

	SceneManipulator manipulator;
	manipulator.id = scene.getId();
	manipulator.scene = &scenes[getSceneListIndex(scene.getId())];

	return manipulator;
}

Flag SceneManager::removeScene(SceneManipulator manipulator)
{
	int index = getSceneListIndex(manipulator.id);
	if (index != -1)
	{
		scenes.erase(scenes.begin() + index);
		return Flag::OK;
	}
	return Flag::ERROR_NOTHING_FOUND_ID;
}

Flag SceneManager::addObjectToScene(SceneManipulator sceneManipulator, ObjectManipulator objectManipulator)
{
	return sceneManipulator.scene->addObject(objectManipulator.object);
}

Flag SceneManager::removeObjectFromScene(SceneManipulator sceneManipulator, ObjectManipulator objectManipulator)
{
	return sceneManipulator.scene->removeObject(objectManipulator.object);
}

Flag SceneManager::initializeScene(SceneManipulator manipulator)
{
	return manipulator.scene->initialization();
}

void SceneManager::setSceneGravity(SceneManipulator manipulator, fVector vector)
{
	manipulator.scene->setGravity(vector);
}

Flag SceneManager::setActiveCameraofScene(SceneManipulator sManipulator, ObjectManipulator oManipulator)
{
	return sManipulator.scene->setActiveCamera(oManipulator.object);
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

Flag SceneManager::codeStepUpdate()
{
	for (unsigned int i = 0; i < scenes.size(); i++)
	{
		Flag flag = scenes[i].codeStepUpdate();

		if (flag != Flag::OK)
			return flag;
	}

	return Flag::OK;
}

bool SceneManager::test()
{
	SceneManipulator manipulator = createScene();
	Flag flag = removeScene(manipulator);
	if (flag != Flag::OK)
		return false;

	return true;
}

int SceneManager::getSceneListIndex(int id)
{
	for (int i = 0; i < scenes.size(); i++)
	{
		if (scenes[i].getId() == id)
			return i;
	}
	return -1;
}