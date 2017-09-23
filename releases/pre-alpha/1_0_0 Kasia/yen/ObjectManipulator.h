#pragma once
#include "Object.h"

namespace yen
{
	class ObjectManipulator
	{
		friend class ObjectsManager;
		friend class SceneManager;
	protected:
		Object *object;
		int id;
	};
}
