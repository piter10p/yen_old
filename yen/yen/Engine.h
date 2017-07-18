#pragma once
#include "SceneManager.h"
#include "GraphicsEngine.h"
#include "ResourceManager.h"
#include "EngineConfiguration.h"
#include "ObjectsManager.h"
#include "SettingsManager.h"
#include "InputManager.h"
#include "PhysicsEngine.h"

namespace yen
{
	class Engine
	{
	public:
		Engine();
		~Engine();

		void step();

		void initialize(EngineConfiguration configuration);

		Flag run();
		void stop();
		bool isRunning();
		const std::string getVersion();

		GraphicsEngine *graphicsEngine;
		SceneManager *sceneManager;
		ResourceManager *resourceManager;
		ObjectsManager *objectsManager;
		SettingsManager *settingsManager;
		InputManager *inputManager;
		PhysicsEngine *physicsEngine;


	private:
		bool running = false;
		bool initialized = false;
		EngineConfiguration configuration;
		const std::string version = "TEST_BUILD";

		void reInitialize();
	};
}
