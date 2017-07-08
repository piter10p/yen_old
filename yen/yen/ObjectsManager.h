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

	private:
		std::vector <Object> objects;

		int idCounter;

		int getNewId();

		int getObjectListIndex(int id);
	};
}
