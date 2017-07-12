#pragma once
#include "Vector.h"
#include "SFML\Graphics.hpp"
#include <string>
#include "Flag.h"
#include "Settings.h"
#include "RenderObject.h"
#include "SceneManager.h"

namespace yen
{
	class GraphicsEngine
	{
	public:
		GraphicsEngine();
		~GraphicsEngine();

		void initialize(GraphicsSettings settings, std::string windowName, SceneManager*);
		void reInitialize(GraphicsSettings settings, std::string windowName, SceneManager*);

		void draw(RenderObject);

		Flag renderFrame();

	private:
		uVector resolution;
		bool fullScreen;
		std::string windowName;
		SceneManager *sceneManager;

		sf::RenderWindow window;
	};
}
