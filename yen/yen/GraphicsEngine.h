#pragma once
#include "Vector.h"
#include "SFML\Graphics.hpp"
#include <string>
#include "Flag.h"

namespace yen
{
	class GraphicsEngine
	{
	public:
		GraphicsEngine();
		~GraphicsEngine();

		void initialize(uVector resolution, bool fullScreen, std::string windowName);
		void reInitialize(uVector resolution, bool fullScreen, std::string windowName);

		Flag renderFrame();

	private:
		uVector resolution;
		bool fullScreen;
		std::string windowName;

		sf::RenderWindow window;
	};
}
