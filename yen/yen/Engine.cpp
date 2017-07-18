#include "stdafx.h"
#include "Engine.h"
#include "Logger.h"

using namespace yen;

Engine::Engine()
{
	Logger::prepareFile();
}


Engine::~Engine()
{
	if (initialized)
	{
		delete graphicsEngine;
		delete sceneManager;
		delete resourceManager;
		delete objectsManager;
		delete settingsManager;
		delete inputManager;
		delete physicsEngine;
	}
}

void Engine::step()
{
	if (running)
	{
		graphicsEngine->renderFrame();
		physicsEngine->step();
	}
}

void Engine::initialize(EngineConfiguration configuration)
{
	Logger::infoLog(0, "Engine initialization");

	this->configuration = configuration;

	if (initialized)
		reInitialize();
	else
	{
		physicsEngine = new PhysicsEngine();
		inputManager = new InputManager();
		sceneManager = new SceneManager(physicsEngine);
		graphicsEngine = new GraphicsEngine(sceneManager, inputManager);
		resourceManager = new ResourceManager();
		objectsManager = new ObjectsManager();
		settingsManager = new SettingsManager();

		settingsManager->setDefaults();

		graphicsEngine->initialize(settingsManager->getGraphicsSettings(), configuration.windowName);
		physicsEngine->initialize();

		initialized = true;
	}

	Logger::infoLog(0, "Engine initialized");
	Logger::insertReturn();

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
	graphicsEngine->reInitialize(settingsManager->getGraphicsSettings(), configuration.windowName);
}