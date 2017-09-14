#include "stdafx.h"
#include "GraphicsEngine.h"
#include "SceneManager.h"
#include "Logger.h"

using namespace yen;

GraphicsEngine::GraphicsEngine(InputManager *inputsManager)
{
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
	Logger::infoLog(1, "Graphics Engine reinitialization");

	if(window.isOpen())
		window.close();

	initialize(settings, windowName);
}

void GraphicsEngine::draw(RenderObject rObject)
{
	window.draw(*rObject.drawable);
}

void GraphicsEngine::setView(sf::View view)
{
	window.setView(view);
}

void GraphicsEngine::renderFrame()
{
	try
	{
		inputsManager->updateInputs(&window);
		window.display();
	}
	catch (...)
	{
		Logger::errorLog(0, "Undefined error in GraphicsEngine::renderFrame().");
		throw Error::generateUndefinedError();
	}
}

void GraphicsEngine::clearFrame()
{
	window.clear(sf::Color::White);
}