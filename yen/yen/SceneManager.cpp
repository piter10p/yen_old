#include "stdafx.h"
#include "SceneManager.h"

using namespace yen;

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

SceneManipulator SceneManager::createScene()
{
	Scene scene;
	scene.id = getNewId();
	scenes.push_back(scene);

	SceneManipulator manipulator;
	manipulator.id = scene.id;
	manipulator.scene = &scenes[getSceneListIndex(scene.id)];

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

int SceneManager::getNewId()
{
	idCounter++;
	return idCounter - 1;
}

int SceneManager::getSceneListIndex(int id)
{
	for (int i = 0; i < scenes.size(); i++)
	{
		if (scenes[i].id == id)
			return i;
	}
	return -1;
}