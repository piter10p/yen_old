#pragma once
#include "Resource.h"
#include <string>
#include <vector>
#include "LangString.h"
#include "Language.h"
#include <pugixml.hpp>

namespace yen
{
	class StringResource : public Resource
	{
	public:
		StringResource(std::string path, int id, Language *actualLanguage);
		~StringResource();

		void load();
		void unLoad();

		std::string getString(std::string stringName);

	private:
		std::string path;
		std::vector <LangString> strings;
		Language *actualLanguage;

		std::string generatePath();
		void openDocument(pugi::xml_document *doc, std::string filePath);
		void loadStrings(pugi::xml_document *doc);

	};
}
