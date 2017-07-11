#include "stdafx.h"
#include "Engine.h"

using namespace yen;

Engine::Engine()
{
}


Engine::~Engine()
{
	delete graphicsEngine;
	delete sceneManager;
}

void Engine::step()
{
	if (isRunning)
	{
		sceneManager->codeStepUpdate();
	}
}

void Engine::initialize(EngineConfiguration configuration)
{
	setDefaultSettings();
	this->configuration = configuration;

	if (initialized)
		reInitialize();
	else
	{
		sceneManager = new SceneManager();
		graphicsEngine = new GraphicsEngine();

		graphicsEngine->initialize(settings.resolution, settings.fullScreen, configuration.windowName);

		initialized = true;
	}
}

Flag Engine::run()
{
	if (initialized)
	{
		running = true;
		return Flag::OK;
	}
	return Flag::ERROR_ENGINE_NOT_INITIALIZED;
}

void Engine::stop()
{
	running = false;
}

bool Engine::isRunning()
{
	return running;
}

const std::string Engine::getVersion()
{
	return version;
}

void Engine::reInitialize()
{
	graphicsEngine->reInitialize(settings.resolution, settings.fullScreen, configuration.windowName);
}

void Engine::setDefaultSettings()
{
	settings.resolution.set(600, 600);
	settings.fullScreen = false;
}