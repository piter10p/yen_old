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

bool SceneManager::test()
{
	SceneManipulator manipulator = createScene();
	Flag flag = removeScene(manipulator);
	if (flag != Flag::OK)
		return false;

	return true;
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
		if (scenes[i].getId() == id)
			return i;
	}
	return -1;
}