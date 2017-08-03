#pragma once
#include "Resource.h"
#include <SFML\Graphics.hpp>

namespace yen
{
	class FontResource: public Resource
	{
	public:
		FontResource(std::string path);
		~FontResource();

		void load();
		void unLoad();

		sf::Font& getFont();

	private:
		sf::Font font;
		std::string path;

		std::string generatePath();
	};
}
