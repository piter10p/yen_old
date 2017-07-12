#pragma once
#include "AnimationResource.h"
#include "ResourceManipulator.h"

namespace yen
{
	class AnimationManipulator :public ResourceManipulator
	{
		friend class ResourceManager;
		friend class GraphicsComponent;
	protected:
		AnimationResource *animationResource;
		int id;
	};
}
