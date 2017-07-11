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

		Flag addObjectToScene(SceneManipulator, ObjectManipulator);
		Flag removeObjectFromScene(SceneManipulator, ObjectManipulator);

		void freezeScene(SceneManipulator);
		void unFreezeScene(SceneManipulator);
		bool isSceneFreezed(SceneManipulator);

		void codeStepUpdate();

		bool test();

	protected:
		std::vector <Scene> scenes;

		int idCounter;
		int getNewId();

		int getSceneListIndex(int id);
	};
}
