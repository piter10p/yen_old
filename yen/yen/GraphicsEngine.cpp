#include "stdafx.h"
#include "GraphicsEngine.h"
#include "SceneManager.h"
#include "Logger.h"

using namespace yen;

GraphicsEngine::GraphicsEngine(SceneManager *sceneManager, InputManager *inputsManager)
{
	this->sceneManager = sceneManager;
	this->inputsManager = inputsManager;
}


GraphicsEngine::~GraphicsEngine()
{
}

void GraphicsEngine::initialize(GraphicsSettings settings, std::string windowName)
{
	Logger::infoLog(1, "Graphics Engine initialization");

	Logger::infoLog(2, "Creating window");
	if(settings.fullScreen)
		window.create(sf::VideoMode(settings.resolution.getX(), settings.resolution.getY()), windowName, sf::Style::Fullscreen);
	else
		window.create(sf::VideoMode(settings.resolution.getX(), settings.resolution.getY()), windowName, sf::Style::Titlebar);
}

void GraphicsEngine::reInitialize(GraphicsSettings settings, std::string windowName)
{
	if(window.isOpen())
		window.close();

	initialize(settings, windowName);
}

void GraphicsEngine::draw(RenderObject rObject)
{
	window.draw(*rObject.sprite);
}

Flag GraphicsEngine::renderFrame()
{
	inputsManager->updateInputs(&window);
	window.clear(sf::Color::White);
	sceneManager->codeStepUpdate();
	window.display();
	return Flag::OK;
}