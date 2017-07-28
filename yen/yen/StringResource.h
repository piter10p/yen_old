#pragma once
#include "Resource.h"
#include <string>
#include <vector>
#include "LangString.h"
#include "Language.h"

namespace yen
{
	class StringResource : public Resource
	{
	public:
		StringResource(std::string path, int id, Language *actualLanguage);
		~StringResource();

		Flag load();
		void unLoad();

	private:
		std::string path;
		std::vector <LangString> strings;
		Language *actualLanguage;


	};
}
