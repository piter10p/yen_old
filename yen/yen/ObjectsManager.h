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

		ObjectManipulator createObject(fVector position);
		Flag removeObject(ObjectManipulator);
		Flag attachComponent(ComponentManipulator *out, ObjectManipulator, Component*);
		Flag removeComponent(ObjectManipulator, ComponentManipulator);
		void setLoadDistance(ObjectManipulator, float);

		bool test();

	private:
		std::vector <Object*> objects;

		int getObjectListIndex(int id);

		void clearAllObjects();
	};
}
