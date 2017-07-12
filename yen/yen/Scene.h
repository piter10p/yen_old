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

		Flag load();

		void initialization();

		void freeze();
		void unFreeze();
		bool isFreezed();

		void codeStepUpdate();

		bool test();

	private:
		std::vector <Object*> objects;
		bool freezed = true;
		bool initialized = false;

		int getIndexOfObjectsListObject(int id);
	};
}
