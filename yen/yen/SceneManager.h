#pragma once
#include <vector>
#include "Object.h"
#include "SceneManipulator.h"
#include "IdSetter.h"
#include "PhysicsEngine.h"

namespace yen
{
	class SceneManager: public IdSetter
	{
	public:
		SceneManager(PhysicsEngine*);
		~SceneManager();

		SceneManipulator createScene();
		Flag removeScene(SceneManipulator);

		Flag addObjectToScene(SceneManipulator, ObjectManipulator);
		Flag removeObjectFromScene(SceneManipulator, ObjectManipulator);

		Flag initializeScene(SceneManipulator);

		void setSceneGravity(SceneManipulator, fVector);

		Flag setActiveCameraofScene(SceneManipulator, ObjectManipulator);

		void freezeScene(SceneManipulator);
		void unFreezeScene(SceneManipulator);
		bool isSceneFreezed(SceneManipulator);

		Flag codeStepUpdate();

		bool test();

	protected:
		std::vector <Scene> scenes;
		PhysicsEngine *physicsEngine;

		int getSceneListIndex(int id);
	};
}
