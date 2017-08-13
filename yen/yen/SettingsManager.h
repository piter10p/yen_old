#pragma once
#include "Settings.h"
#include "GraphicsEngine.h"
#include "Flag.h"
#include "pugixml.hpp"

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

		void setLanguage(std::string code);
		std::string getLanguage();
			
		void saveSettings();
		void loadSettings();

	private:
		Settings settings;

		bool graphicsChanged = false;

		bool openConfigFile(pugi::xml_document*);
		bool load(pugi::xml_document*);

		bool text2Bool(std::string);
		std::string bool2Text(bool);
	};
}
