#pragma once
#include <vector>
#include "Object.h"
#include "SceneManipulator.h"
#include "IdSetter.h"

namespace yen
{
	class SceneManager: public IdSetter
	{
	public:
		SceneManager();
		~SceneManager();

		SceneManipulator createScene();
		Flag removeScene(SceneManipulator);

		Flag addObjectToScene(SceneManipulator, ObjectManipulator);
		Flag removeObjectFromScene(SceneManipulator, ObjectManipulator);

		Flag loadScene(SceneManipulator);

		void initializeScene(SceneManipulator);

		Flag setActiveCameraofScene(SceneManipulator, ObjectManipulator);

		void freezeScene(SceneManipulator);
		void unFreezeScene(SceneManipulator);
		bool isSceneFreezed(SceneManipulator);

		void codeStepUpdate();

		bool test();

	protected:
		std::vector <Scene> scenes;

		int getSceneListIndex(int id);
	};
}
