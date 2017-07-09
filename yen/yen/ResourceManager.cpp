#include "stdafx.h"
#include "ResourceManager.h"

using namespace yen;

ResourceManager::ResourceManager()
{
	idCounter = 0;
}


ResourceManager::~ResourceManager()
{
	clearAllResources();
}

AnimationManipulator ResourceManager::addAnimationResource(AnimationResourceDef def)
{
	AnimationResource *resource = new AnimationResource(def, getId());
	animationResources.push_back(resource);
	AnimationManipulator manipulator;
	manipulator.animationResource = resource;
	manipulator.id = resource->id;
	return manipulator;
}

Flag ResourceManager::removeAnimationResource(AnimationManipulator manipulator)
{
	for (unsigned int i = 0; i < animationResources.size(); i++)
	{
		if (isIdSame(&manipulator, animationResources[i]))
		{
			delete animationResources[i];
			animationResources.erase(animationResources.begin() + i);
			return Flag::OK;
		}
	}
	return Flag::ERROR_NOTHING_FOUND_ID;
}

int ResourceManager::getId()
{
	idCounter++;
	return idCounter - 1;
}

bool ResourceManager::isIdSame(ResourceManipulator* manipulator, Resource* resource)
{
	if (manipulator->id == resource->id)
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