#pragma once
#include <SFML\Graphics.hpp>
#include "Flag.h"
#include <string>

namespace yen
{
	class Frame
	{
	public:
		Frame();
		~Frame();

		Flag load(std::string path);

	private:
		sf::Texture texture;
	};
}
