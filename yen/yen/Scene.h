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

		Flag addObject(Object*);
		Flag removeObject(Object*);

	private:
		std::vector <Object*> objects;

		int getObjectListIndex(int id);
	};
}
