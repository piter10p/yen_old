#pragma once
#include <vector>
#include "Object.h"
#include "SceneManipulator.h"
#include "IdSetter.h"
#include "PhysicsEngine.h"
#include "ResourceManager.h"

namespace yen
{
	class SceneManager: public IdSetter
	{
	public:
		SceneManager(PhysicsEngine*, ResourceManager*);
		~SceneManager();

		SceneManipulator createScene();
		void removeScene(SceneManipulator);

		void addObjectToScene(SceneManipulator, ObjectManipulator);
		void removeObjectFromScene(SceneManipulator, ObjectManipulator);

		void initializeScene(SceneManipulator);

		void setSceneGravity(SceneManipulator, fVector);

		void setActiveCameraofScene(SceneManipulator, ObjectManipulator);

		void freezeScene(SceneManipulator);
		void unFreezeScene(SceneManipulator);
		bool isSceneFreezed(SceneManipulator);

		void codeStepUpdate();

		bool test();

	protected:
		std::vector <Scene> scenes;
		PhysicsEngine *physicsEngine;
		ResourceManager *resourceManager;

		int getSceneListIndex(int id);
	};
}
