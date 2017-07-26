#include "stdafx.h"
#include "ResourceManager.h"

using namespace yen;

ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
	clearAllResources();
}

AnimationManipulator ResourceManager::addAnimationResource(AnimationResourceDef def)
{
	AnimationResource *resource = new AnimationResource(def, getNewId());
	animationResources.push_back(resource);

	AnimationManipulator manipulator;
	manipulator.animationResource = resource;
	manipulator.id = resource->getId();
	manipulator.animationResource->setFrameRate(def.frameRate);
	return manipulator;
}

Flag ResourceManager::removeAnimationResource(AnimationManipulator manipulator)
{
	for (unsigned int i = 0; i < animationResources.size(); i++)
	{
		if (isIdSame(&manipulator, animationResources[i]))
		{
			animationResources.erase(animationResources.begin() + i);
			return Flag::OK;
		}
	}
	return Flag::ERROR_NOTHING_FOUND_ID;
}

bool ResourceManager::test()
{
	AnimationResourceDef def;
	def.path = "ASD";

	AnimationManipulator manipulator = addAnimationResource(def);
	Flag flag = removeAnimationResource(manipulator);

	if (flag == Flag::OK)
		return true;
	return false;
}

bool ResourceManager::isIdSame(ResourceManipulator* manipulator, Resource* resource)
{
	if (manipulator->id == resource->getId())
		return true;
	return false;
}

void ResourceManager::clearAllResources()
{
	for (unsigned int i = 0; i < animationResources.size(); i++)
	{
		delete animationResources[i];
	}

	animationResources.clear();
}