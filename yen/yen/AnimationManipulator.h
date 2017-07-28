#pragma once
#include "AnimationResource.h"
#include "Id.h"

namespace yen
{
	class AnimationManipulator :public Id
	{
		friend class ResourceManager;
		friend class AnimationManager;
	protected:
		AnimationResource *animationResource;
		//int id;
	};
}
