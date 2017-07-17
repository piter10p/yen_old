#pragma once
#include "Settings.h"
#include "GraphicsEngine.h"
#include "Flag.h"

namespace yen
{
	class SettingsManager
	{
	public:
		SettingsManager();
		~SettingsManager();

		void setDefaults();
		GraphicsSettings getGraphicsSettings();

		void setResolution(uVector);
		void setFpsLock(unsigned int);
		void setFullScreen(bool);
		void setVSync(bool);

	private:
		Settings settings;

		bool graphicsChanged = false;
	};
}
