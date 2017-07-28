#include "stdafx.h"
#include "ResourceManager.h"

using namespace yen;

ResourceManager::ResourceManager()
{
	addDefaultLanguage();
}


ResourceManager::~ResourceManager()
{
	clearAllResources();
	clearLanguages();
}

AnimationManipulator ResourceManager::addAnimationResource(AnimationResourceDef def)
{
	AnimationResource *resource = new AnimationResource(def, getNewId());
	animationResources.push_back(resource);

	AnimationManipulator manipulator;
	manipulator.animationResource = resource;
	//manipulator.id = resource->getId();
	manipulator.setId(resource->getId());
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
			delete manipulator.animationResource;
			return Flag::OK;
		}
	}
	return Flag::ERROR_NOTHING_FOUND_ID;
}

StringManipulator ResourceManager::addStringResource(std::string path)
{
	StringResource *resource = new StringResource(path, getNewId(), actualLanguage);
	StringManipulator manipulator;
	manipulator.resource = resource;
	manipulator.id = resource->getId();
	stringResources.push_back(resource);

	return manipulator;
}

Flag ResourceManager::removeAnimationResource(StringManipulator manipulator)
{
	for (unsigned int i = 0; i < stringResources.size(); i++)
	{
		if (isIdSame(&manipulator, stringResources[i]))
		{
			stringResources.erase(stringResources.begin() + i);
			delete manipulator.resource;
			return Flag::OK;
		}
	}
	return Flag::ERROR_NOTHING_FOUND_ID;
}

Flag ResourceManager::addLanguage(const std::string code)
{
	if (isLanguageAlreadyAdded(code))
		return Flag::ERROR_LANGUAGE_WITH_THIS_CODE_ALREADY_EXISTS;

	Language *lang = new Language(code);
	languages.push_back(lang);

	return Flag::OK;
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

bool ResourceManager::isIdSame(Id* manipulator, Resource* resource)
{
	if (manipulator->getId() == resource->getId())
		return true;
	return false;
}

bool ResourceManager::isLanguageAlreadyAdded(const std::string code)
{
	for (unsigned int i = 0; i < languages.size(); i++)
	{
		if (languages[i]->getCode() == code)
			return true;
	}
	return false;
}

void ResourceManager::clearAllResources()
{
	for (unsigned int i = 0; i < animationResources.size(); i++)
	{
		delete animationResources[i];
	}
	animationResources.clear();

	for (unsigned int i = 0; i < stringResources.size(); i++)
	{
		delete stringResources[i];
	}
	stringResources.clear();
}

void ResourceManager::clearLanguages()
{
	for (unsigned int i = 0; i < languages.size(); i++)
	{
		delete languages[i];
	}
	languages.clear();
}

void ResourceManager::addDefaultLanguage()
{
	Language *lang = new Language("default");
	actualLanguage = lang;
	languages.push_back(lang);
}