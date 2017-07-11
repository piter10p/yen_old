#include "stdafx.h"
#include "GraphicsEngine.h"

using namespace yen;

GraphicsEngine::GraphicsEngine()
{
}


GraphicsEngine::~GraphicsEngine()
{
}

void GraphicsEngine::initialize(GraphicsSettings settings, std::string windowName)
{
	this->resolution = resolution;
	this->fullScreen = fullScreen;
	this->windowName = windowName;

	if(fullScreen)
		window.create(sf::VideoMode(settings.resolution.getX(), settings.resolution.getY()), windowName, sf::Style::Titlebar);
	else
		window.create(sf::VideoMode(settings.resolution.getX(), settings.resolution.getY()), windowName, sf::Style::Fullscreen);
}

void GraphicsEngine::reInitialize(GraphicsSettings settings, std::string windowName)
{
	if(window.isOpen())
		window.close();

	initialize(settings, windowName);
}

void GraphicsEngine::draw()
{

}

Flag GraphicsEngine::renderFrame()
{
	return Flag::OK;
}