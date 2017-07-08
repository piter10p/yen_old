#pragma once
#include <vector>
#include "ObjectManipulator.h"

namespace yen
{
	class ObjectsManager
	{
	public:
		ObjectsManager();
		~ObjectsManager();

		ObjectManipulator createObject();
		bool removeObject(ObjectManipulator);
		ComponentManipulator attachComponent(ObjectManipulator, Component*);
		bool removeComponent(ObjectManipulator, ComponentManipulator);

	private:
		std::vector <Object> objects;

		int idCounter;

		int getNewId();

		int getObjectListIndex(int id);

		void clearAllObjects();
	};
}
