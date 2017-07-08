#pragma once
#include "ObjectManipulator.h"
#include <vector>

namespace yen
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		friend class SceneManager;

	protected:
		int id;

		void addObject(Object*);
		Flag removeObject(ObjectManipulator);

	private:
		std::vector <Object*> objects;

		int getObjectListIndex(ObjectManipulator);
	};
}
