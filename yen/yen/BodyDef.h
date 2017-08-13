#pragma once
#include <Box2D.h>
#include "Vector.h"

namespace yen
{
	enum BodyType
	{
		STATIC,
		DYNAMIC
	};

	struct BodyDef
	{
		BodyType type = BodyType::STATIC;
		float32 density = 1.0f;
		float32 friction = 1.0f;
		float32 restitution = 0.0f;
		bool isSensor = false;
		fVector shapeSize = fVector(0.0f, 0.0f);
		fVector position = fVector(0.0f, 0.0f);
		fVector offset = fVector(0.0f, 0.0f);
	};
}
