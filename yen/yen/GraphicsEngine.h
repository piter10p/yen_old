#pragma once
#include "Vector.h"
#include "SFML\Graphics.hpp"
#include <string>
#include "Flag.h"
#include "Settings.h"
//#include "GraphicsComponent.h"

namespace yen
{
	class GraphicsEngine
	{
	public:
		GraphicsEngine();
		~GraphicsEngine();

		void initialize(GraphicsSettings settings, std::string windowName);
		void reInitialize(GraphicsSettings settings, std::string windowName);

		void draw();

		Flag renderFrame();

	private:
		uVector resolution;
		bool fullScreen;
		std::string windowName;

		sf::RenderWindow window;
	};
}
