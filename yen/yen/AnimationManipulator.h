#pragma once
#include "AnimationResource.h"
#include "Manipulator.h"

namespace yen
{
	class AnimationManipulator :public Manipulator
	{
		friend class ResourceEngine;
	protected:
		AnimationResource *animationResource;
	};
}
