#include "stdafx.h"
#include "ResourceEngine.h"

using namespace yen;

ResourceEngine::ResourceEngine()
{
	idCounter = 0;
}


ResourceEngine::~ResourceEngine()
{
	clearAllResources();
}

AnimationManipulator ResourceEngine::addAnimationResource(AnimationResourceDef def)
{
	AnimationResource *resource = new AnimationResource(def, getId());
	animationResources.push_back(resource);
	AnimationManipulator manipulator;
	manipulator.animationResource = resource;
	manipulator.id = resource->id;
	return manipulator;
}

bool ResourceEngine::removeAnimationResource(AnimationManipulator manipulator)
{
	for (unsigned int i = 0; i < animationResources.size(); i++)
	{
		if (isIdSame(&manipulator, animationResources[i]))
		{
			delete animationResources[i];
			animationResources.erase(animationResources.begin() + i);
			return true;
		}
	}
	return false;
}

int ResourceEngine::getId()
{
	idCounter++;
	return idCounter - 1;
}

bool ResourceEngine::isIdSame(ResourceManipulator* manipulator, Resource* resource)
{
	if (manipulator->id == resource->id)
		return true;
	return false;
}

void ResourceEngine::clearAllResources()
{
	for (unsigned int i = 0; i < animationResources.size(); i++)
	{
		delete animationResources[i];
	}
	animationResources.clear();
}