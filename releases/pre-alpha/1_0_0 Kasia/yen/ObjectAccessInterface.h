#pragma once
#include "Vector.h"
#include "WorldManipulator.h"

namespace yen
{
	class ObjectAccessInterface
	{
	public:
		ObjectAccessInterface();
		~ObjectAccessInterface();

		void setPosition(fVector);
		void move(fVector);

		fVector getPosition();
		WorldManipulator getWorldManipulator();

		friend class Object;
	protected:
		fVector *position;
		WorldManipulator worldManipulator;
	};
}
