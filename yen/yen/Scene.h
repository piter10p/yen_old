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

		void freeze();
		void unFreeze();
		bool isFreezed();

		void codeStepUpdate();

		bool test();

	private:
		std::vector <Object*> objects;
		bool freezed = false;

		int getIndexOfObjectsListObject(int id);
	};
}
