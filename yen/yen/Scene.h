#pragma once
#include "ObjectManipulator.h"
#include <vector>
#include "Id.h"
#include "PhysicsEngine.h"
#include "ResourceManager.h"

namespace yen
{
	class Scene :public Id
	{
	public:
		Scene(PhysicsEngine*);
		~Scene();

		void addObject(Object*);
		void removeObject(Object*);

		void initialization();

		void setActiveCamera(Object*);

		void freeze();
		void unFreeze();
		bool isFreezed();

		void codeStepUpdate();
		void setGravity(fVector);

		bool test();

		void loadObjects();
		void initializeObjects();

	private:
		std::vector <Object*> objects;
		bool freezed = true;
		bool initialized = false;
		Object *activeCamera;

		WorldManipulator worldManipulator;
		PhysicsEngine *physicsEngine;

		int getIndexOfObjectsListObject(int id);
		bool haveActiveCamera();
		bool isObjectInLoadRange(Object*);
	};
}
