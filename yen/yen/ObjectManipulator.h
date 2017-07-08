#pragma once
#include "Manipulator.h"
#include "Object.h"

namespace yen
{
	class ObjectManipulator :public Manipulator
	{
		friend class ObjectsManager;
	protected:
		Object *object;
	};
}
