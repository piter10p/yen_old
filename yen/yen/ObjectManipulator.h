#pragma once
#include "Object.h"

namespace yen
{
	class ObjectManipulator
	{
		friend class ObjectsManager;
		friend class Scene;
	protected:
		Object *object;
		int id;
	};
}
