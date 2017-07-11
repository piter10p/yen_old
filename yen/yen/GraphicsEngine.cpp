#include "stdafx.h"
#include "GraphicsEngine.h"

using namespace yen;

GraphicsEngine::GraphicsEngine()
{
}


GraphicsEngine::~GraphicsEngine()
{
}

void GraphicsEngine::initialize(uVector resolution, bool fullScreen, std::string windowName)
{
	this->resolution = resolution;
	this->fullScreen = fullScreen;
	this->windowName = windowName;

	if(fullScreen)
		window.create(sf::VideoMode(800, 600), windowName, sf::Style::Titlebar);
	else
		window.create(sf::VideoMode(800, 600), windowName, sf::Style::Fullscreen);
}

void GraphicsEngine::reInitialize(uVector resolution, bool fullScreen, std::string windowName)
{
	if(window.isOpen())
		window.close();

	initialize(resolution, fullScreen, windowName);
}

Flag GraphicsEngine::renderFrame()
{
	return Flag::OK;
}