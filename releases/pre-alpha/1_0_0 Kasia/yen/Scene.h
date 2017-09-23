#pragma once
#include "ObjectManipulator.h"
#include <vector>
#include "Id.h"
#include "PhysicsEngine.h"
#include "ResourceManager.h"
#include "CameraComponent.h"

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

		bool haveCamera();

		WorldManipulator worldManipulator;
		PhysicsEngine *physicsEngine;

		int getIndexOfObjectsListObject(int id);
		bool isObjectInLoadRange(Object*);

		std::vector <Object*> getCameraObejcts();
	};
}
