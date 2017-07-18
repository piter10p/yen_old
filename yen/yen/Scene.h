#pragma once
#include "ObjectManipulator.h"
#include <vector>
#include "Id.h"
#include "PhysicsEngine.h"

namespace yen
{
	class Scene :public Id
	{
	public:
		Scene(PhysicsEngine*);
		~Scene();

		Flag addObject(Object*);
		Flag removeObject(Object*);

		Flag load();

		void initialization();

		Flag setActiveCamera(Object*);

		void freeze();
		void unFreeze();
		bool isFreezed();

		void codeStepUpdate();
		void setGravity(fVector);

		bool test();

	private:
		std::vector <Object*> objects;
		bool freezed = true;
		bool initialized = false;
		Object *activeCamera;

		WorldManipulator worldManipulator;
		PhysicsEngine *physicsEngine;

		int getIndexOfObjectsListObject(int id);
		bool haveActiveCamera();
	};
}
