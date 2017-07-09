#pragma once
#include "AnimationResource.h"
#include "ResourceManipulator.h"

namespace yen
{
	class AnimationManipulator :public ResourceManipulator
	{
		friend class ResourceManager;
	protected:
		AnimationResource *animationResource;
		int id;
	};
}
