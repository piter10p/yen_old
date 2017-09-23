#pragma once
#include "World.h"

namespace yen
{
	class WorldManipulator
	{
		friend class PhysicsEngine;
	protected:
		int id;
		World *world;
	};
}
