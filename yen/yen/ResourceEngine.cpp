#include "stdafx.h"
#include "ResourceEngine.h"

using namespace yen;

ResourceEngine::ResourceEngine()
{
	idCounter = 0;
}


ResourceEngine::~ResourceEngine()
{
	for each (AnimationResource* resource in animationResources)
	{
		delete resource;
	}
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
	int i = 0;

	for each (AnimationResource* animationResource in animationResources)
	{
		if (isIdSame(&manipulator, animationResource))
		{
			delete animationResource;
			animationResources.erase(animationResources.begin() + i);
			return true;
		}

		i++;
	}
	return false;
}

int ResourceEngine::getId()
{
	idCounter++;
	return idCounter - 1;
}

bool ResourceEngine::isIdSame(Manipulator* manipulator, Resource* resource)
{
	if (manipulator->id == resource->id)
		return true;
	return false;
}