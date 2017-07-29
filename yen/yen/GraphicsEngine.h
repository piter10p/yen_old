#pragma once
#include "Vector.h"
#include "SFML\Graphics.hpp"
#include <string>
#include "Flag.h"
#include "Settings.h"
#include "RenderObject.h"
#include "SceneManager.h"
#include "InputManager.h"

namespace yen
{
	class GraphicsEngine
	{
	public:
		GraphicsEngine(SceneManager*, InputManager*);
		~GraphicsEngine();

		void initialize(GraphicsSettings settings, std::string windowName);
		void reInitialize(GraphicsSettings settings, std::string windowName);

		void draw(RenderObject);

		void renderFrame();

	private:
		InputManager *inputsManager;
		SceneManager *sceneManager;

		sf::RenderWindow window;
	};
}
