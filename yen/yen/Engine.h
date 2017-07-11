#pragma once
#include "SceneManager.h"
#include "GraphicsEngine.h"
#include "Settings.h"
#include "EngineConfiguration.h"

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
