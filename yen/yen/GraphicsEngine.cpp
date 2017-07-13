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
	this->resolution = settings.resolution;
	this->fullScreen = settings.fullScreen;
	this->windowName = windowName;

	this->sceneManager = sceneManager;

	if(this->fullScreen)
		window.create(sf::VideoMode(resolution.getX(), resolution.getY()), this->windowName, sf::Style::Fullscreen);
	else
		window.create(sf::VideoMode(resolution.getX(), resolution.getY()), this->windowName, sf::Style::Titlebar);
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