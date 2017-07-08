#pragma once
#include "Object.h"

namespace yen
{
	class ObjectManipulator
	{
		friend class ObjectsManager;
	protected:
		Object *object;
		int id;
	};
}
