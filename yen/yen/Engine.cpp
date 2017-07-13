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
	delete resourceManager;
	delete objectsManager;
}

void Engine::step()
{
	if (running)
	{
		graphicsEngine->renderFrame();
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
		resourceManager = new ResourceManager();
		objectsManager = new ObjectsManager();

		graphicsEngine->initialize(settings.graphicsSettings, configuration.windowName, sceneManager);

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
	graphicsEngine->reInitialize(settings.graphicsSettings, configuration.windowName, sceneManager);
}

void Engine::setDefaultSettings()
{
	settings.graphicsSettings.resolution.set(800, 600);
	settings.graphicsSettings.fullScreen = false;
	settings.graphicsSettings.fpsLock = 0;
	settings.graphicsSettings.vSync = false;
}