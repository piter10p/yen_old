#pragma once
#include <Box2D.h>

namespace yen
{
	class BodyManipulator
	{
		friend class World;
	protected:
		b2Body *body;
	};
}
