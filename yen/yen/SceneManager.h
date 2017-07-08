#pragma once
#include <vector>
#include "Object.h"
#include "SceneManipulator.h"

namespace yen
{
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		SceneManipulator createScene();
		Flag removeScene(SceneManipulator);

	protected:
		std::vector <Scene> scenes;

		int idCounter;
		int getNewId();

		int getSceneListIndex(int id);
	};
}
