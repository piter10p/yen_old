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
		uVector getGraphicsPosition();

		friend class Object;
	protected:
		fVector *position;
	};
}
