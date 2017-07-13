#pragma once
#include "Vector.h"

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
		fVector getCameraPosition();

		friend class Object;
	protected:
		fVector *position;
		fVector cameraPosition;
	};
}
