#pragma once
#include "Vector.h"
#include "SFML\Graphics.hpp"
#include <string>
#include "Flag.h"
#include "Settings.h"
#include "RenderObject.h"
#include "InputManager.h"

namespace yen
{
	class GraphicsEngine
	{
	public:
		GraphicsEngine(InputManager*);
		~GraphicsEngine();

		void initialize(GraphicsSettings settings, std::string windowName);
		void reInitialize(GraphicsSettings settings, std::string windowName);

		void draw(RenderObject);
		void setView(sf::View);

		void renderFrame();
		void clearFrame();

	private:
		InputManager *inputsManager;

		sf::RenderWindow window;
	};
}
