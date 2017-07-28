#include "stdafx.h"
#include "AnimationManager.h"

using namespace yen;

AnimationManager::AnimationManager()
{
}


AnimationManager::~AnimationManager()
{
}

Flag AnimationManager::setActualAnimation(AnimationManipulator manipulator)
{
	if (firstAnimationSetted == true)
		actualAnimation->pause();

	if (isAnimationAdded(manipulator))
	{
		actualAnimation = &manipulator.animationResource->animation;
		actualAnimation->restart();
		actualAnimation->pause();
		firstAnimationSetted = true;
		return Flag::OK;
	}
	return Flag::ERROR_NOTHING_FOUND_ID;
}

Flag AnimationManager::addAnimation(AnimationManipulator manipulator)
{
	if (isAnimationAdded(manipulator))
		return Flag::ERROR_THING_WITH_THIS_ID_IS_ALREADY_EXISTS;	

	animations.push_back(manipulator.animationResource);
	return Flag::OK;
}

Flag AnimationManager::removeAnimation(AnimationManipulator manipulator)
{
	for (unsigned int i = 0; i < animations.size(); i++)
	{
		if (animations[i]->getId() == manipulator.getId())
		{
			animations.erase(animations.begin() + i);
			return Flag::OK;
		}
	}
	return Flag::ERROR_NOTHING_FOUND_ID;
}

Frame* AnimationManager::getActualFrame()
{
	return actualAnimation->getActualFrame();
}

Flag AnimationManager::load()
{
	Flag flag;

	for (unsigned int i = 0; i < animations.size(); i++)
	{
		flag = animations[i]->load();
		if (flag != Flag::OK)
			return flag;
	}
	return Flag::OK;
}

void AnimationManager::unLoad()
{
	for (unsigned int i = 0; i < animations.size(); i++)
	{
		animations[i]->unLoad();
	}
}

void AnimationManager::start()
{
	actualAnimation->start();
}

void AnimationManager::pause()
{
	actualAnimation->pause();
}

bool AnimationManager::isAnimationAdded(AnimationManipulator manipulator)
{
	for (unsigned int i = 0; i < animations.size(); i++)
	{
		if (animations[i]->getId() == manipulator.getId())
			return true;
	}
	return false;
}
