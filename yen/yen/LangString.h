#pragma once
#include <string>

namespace yen
{
	class LangString
	{
	public:
		LangString(std::string name, std::string text);
		~LangString();

		std::string getName();
		std::string getText();

	private:
		std::string name;
		std::string text;
	};
}
