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

		Flag setActualAnimation(AnimationManipulator);

		Flag addAnimation(AnimationManipulator);
		Flag removeAnimation(AnimationManipulator);

		Frame* getActualFrame();

		Flag load();
		void unLoad();

		void start();
		void pause();
	private:
		std::vector<AnimationResource*> animations;

		Animation *actualAnimation;

		bool isAnimationAdded(AnimationManipulator);

		bool firstAnimationSetted = false;
	};
}
