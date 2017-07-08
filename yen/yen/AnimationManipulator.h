#pragma once
#include "AnimationResource.h"
#include "ResourceManipulator.h"

namespace yen
{
	class AnimationManipulator :public ResourceManipulator
	{
		friend class ResourceEngine;
	protected:
		AnimationResource *animationResource;
		int id;
	};
}
