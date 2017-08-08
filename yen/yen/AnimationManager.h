#pragma once
#include "AnimationResource.h"
#include "AnimationManipulator.h"
#include <vector>
#include "Frame.h"

namespace yen
{
	class AnimationManager
	{
	public:
		AnimationManager();
		~AnimationManager();

		void setActualAnimation(AnimationManipulator);

		void addAnimation(AnimationManipulator);
		void removeAnimation(AnimationManipulator);

		Frame* getActualFrame();

		void setResourcesUsed();

		void start();
		void pause();
	private:
		std::vector<AnimationResource*> animations;

		Animation *actualAnimation;

		bool isAnimationAdded(AnimationManipulator);

		bool firstAnimationSetted = false;
	};
}
