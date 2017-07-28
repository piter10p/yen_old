#pragma once
#include <string>

namespace yen
{
	class Language
	{
	public:
		Language(const std::string code);
		~Language();

		std::string getCode();

	private:
		std::string code;
	};
}
