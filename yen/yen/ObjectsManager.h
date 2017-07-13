#pragma once
#include <vector>
#include "ObjectManipulator.h"
#include "IdSetter.h"

namespace yen
{
	class ObjectsManager: public IdSetter
	{
	public:
		ObjectsManager();
		~ObjectsManager();

		ObjectManipulator createObject();
		Flag removeObject(ObjectManipulator);
		Flag attachComponent(ComponentManipulator *out, ObjectManipulator, Component*);
		Flag removeComponent(ObjectManipulator, ComponentManipulator);

		bool test();

	private:
		std::vector <Object*> objects;

		int getObjectListIndex(int id);

		void clearAllObjects();
	};
}
