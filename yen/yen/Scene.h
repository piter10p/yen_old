#pragma once
#include "ObjectManipulator.h"
#include <vector>
#include "Id.h"

namespace yen
{
	class Scene :public Id
	{
	public:
		Scene();
		~Scene();

		Flag addObject(Object*);
		Flag removeObject(Object*);

		bool test();

	private:
		std::vector <Object*> objects;

		int getIndexOfObjectsListObject(int id);
	};
}
