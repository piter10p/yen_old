#include "stdafx.h"
#include "GraphicsEngine.h"
#include "SceneManager.h"

using namespace yen;

GraphicsEngine::GraphicsEngine()
{
}


GraphicsEngine::~GraphicsEngine()
{
}

void GraphicsEngine::initialize(GraphicsSettings settings, std::string windowName, SceneManager *sceneManager)
{
	this->resolution = resolution;
	this->fullScreen = fullScreen;
	this->windowName = windowName;

	this->sceneManager = sceneManager;

	if(fullScreen)
		window.create(sf::VideoMode(settings.resolution.getX(), settings.resolution.getY()), windowName, sf::Style::Titlebar);
	else
		window.create(sf::VideoMode(settings.resolution.getX(), settings.resolution.getY()), windowName, sf::Style::Fullscreen);
}

void GraphicsEngine::reInitialize(GraphicsSettings settings, std::string windowName, SceneManager *sceneManager)
{
	if(window.isOpen())
		window.close();

	initialize(settings, windowName, sceneManager);
}

void GraphicsEngine::draw(RenderObject rObject)
{
	window.draw(*rObject.sprite);
}

Flag GraphicsEngine::renderFrame()
{
	window.clear(sf::Color::White);
	sceneManager->codeStepUpdate();
	window.display();
	return Flag::OK;
}