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

bool SceneManager::removeScene(SceneManipulator manipulator)
{
	int index = getSceneListIndex(manipulator.id);
	if (index != -1)
	{
		scenes.erase(scenes.begin() + index);
		return true;
	}
	return false;
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