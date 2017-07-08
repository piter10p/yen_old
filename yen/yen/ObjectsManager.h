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
		Flag removeObject(ObjectManipulator);
		ComponentManipulator attachComponent(ObjectManipulator, Component*);
		Flag removeComponent(ObjectManipulator, ComponentManipulator);

	private:
		std::vector <Object> objects;

		int idCounter;

		int getNewId();

		int getObjectListIndex(int id);

		void clearAllObjects();
	};
}
