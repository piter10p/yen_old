#pragma once

#include "Manager.h"
#include "AnimationResource.h"
#include "AnimationResourceDef.h"
#include "AnimationManipulator.h"
#include "IdSetter.h"
#include "Language.h"
#include "StringManipulator.h"
#include "FontManipulator.h"

namespace yen
{
	class ResourceManager: public Manager, public IdSetter
	{
	public:
		ResourceManager();
		~ResourceManager();

		AnimationManipulator addAnimationResource(AnimationResourceDef);
		void removeAnimationResource(AnimationManipulator);

		StringManipulator addStringResource(std::string path);
		void removeStringResource(StringManipulator);
		std::string getString(StringManipulator, std::string stringName);

		FontManipulator addFontResource(std::string path);
		void removeFontResource(FontManipulator);

		void addLanguage(const std::string code);
		void changeActiveLanguage(unsigned int langIndex);

		void resetResourceUsage();

		void loadResources();

		bool test();

	protected:
		std::vector <AnimationResource*> animationResources;
		std::vector <StringResource*> stringResources;
		std::vector <FontResource*> fontResources;

	private:
		std::vector <Language*> languages;
		Language *actualLanguage;

		bool isIdSame(Id*, Resource*);
		bool isLanguageAlreadyAdded(const std::string code);
		void clearAllResources();
		void clearLanguages();

		void addDefaultLanguage();
	};
}
