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
		void removeObject(ObjectManipulator);
		void attachComponent(ComponentManipulator *out, ObjectManipulator, Component*);
		void removeComponent(ObjectManipulator, ComponentManipulator);
		void setLoadDistance(ObjectManipulator, float);

		bool test();

	private:
		std::vector <Object*> objects;

		unsigned int getObjectListIndex(int id);

		void clearAllObjects();
	};
}
