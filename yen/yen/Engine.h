#pragma once
#include "SceneManager.h"
#include "GraphicsEngine.h"
#include "Settings.h"
#include "ResourceManager.h"
#include "EngineConfiguration.h"
#include "ObjectsManager.h"

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

	private:
		bool running = false;
		bool initialized = false;
		Settings settings;
		EngineConfiguration configuration;
		const std::string version = "TEST_BUILD";

		void reInitialize();

		void setDefaultSettings();
	};
}
