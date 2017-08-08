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

		sf::Font& getFont();

	protected:
		void load();
		void unLoad();

	private:
		sf::Font font;
		std::string path;

		std::string generatePath();
	};
}
