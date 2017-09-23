#include "stdafx.h"
#include "SettingsManager.h"
#include "Vector.h"
#include "Paths.h"
#include "Logger.h"
#include "Error.h"

using namespace yen;

SettingsManager::SettingsManager()
{
}


SettingsManager::~SettingsManager()
{
}

void SettingsManager::setDefaults()
{
	settings.graphicsSettings.fpsLock = 0;
	settings.graphicsSettings.fullScreen = false;
	settings.graphicsSettings.vSync = false;
	settings.graphicsSettings.resolution = uVector(800, 600);
}

GraphicsSettings SettingsManager::getGraphicsSettings()
{
	return settings.graphicsSettings;
}

void SettingsManager::setResolution(uVector resolution)
{
	settings.graphicsSettings.resolution = resolution;
	graphicsChanged = true;
}

void SettingsManager::setFpsLock(unsigned int fpsLock)
{
	settings.graphicsSettings.fpsLock = fpsLock;
	graphicsChanged = true;
}

void SettingsManager::setFullScreen(bool fullScreen)
{
	settings.graphicsSettings.fullScreen = fullScreen;
	graphicsChanged = true;
}

void SettingsManager::setVSync(bool vSync)
{
	settings.graphicsSettings.vSync = vSync;
	graphicsChanged = true;
}

void SettingsManager::saveSettings()
{
	try
	{
		pugi::xml_document doc;
		pugi::xml_node root = doc.append_child("Settings");

		pugi::xml_node setting;
		pugi::xml_node setting2;


		setting = root.append_child("Resolution");

		setting2 = setting.append_child("Width");
		setting2.append_child(pugi::node_pcdata).set_value(std::to_string(settings.graphicsSettings.resolution.getX()).c_str());

		setting2 = setting.append_child("Height");
		setting2.append_child(pugi::node_pcdata).set_value(std::to_string(settings.graphicsSettings.resolution.getY()).c_str());


		setting = root.append_child("FullScreen");
		setting.append_child(pugi::node_pcdata).set_value(bool2Text(settings.graphicsSettings.fullScreen).c_str());

		setting = root.append_child("FpsLock");
		setting.append_child(pugi::node_pcdata).set_value(std::to_string(settings.graphicsSettings.fpsLock).c_str());

		setting = root.append_child("vSync");
		setting.append_child(pugi::node_pcdata).set_value(bool2Text(settings.graphicsSettings.vSync).c_str());

		setting = root.append_child("Language");
		setting.append_child(pugi::node_pcdata).set_value(settings.language.c_str());

		doc.save_file(Paths::CONFIG_FILE);
	}
	catch (...)
	{
		Error e;
		e.message = "Can not save configuration file with path: \"" + (std::string)Paths::CONFIG_FILE + "\".";
		e.flag = Flag::ERROR_CAN_NOT_SAVE_FILE;
		Logger::errorLog(0, e.message);
		throw e;
	}
}

void SettingsManager::loadSettings()
{
	pugi::xml_document doc;
	
	if (!openConfigFile(&doc) || !load(&doc))
	{
		setDefaults();
		saveSettings();
	}
}

bool SettingsManager::openConfigFile(pugi::xml_document* doc)
{
	pugi::xml_parse_result result = doc->load_file(Paths::CONFIG_FILE);

	if (result.status == pugi::status_ok)
		return true;
	Logger::errorLog(0, "Can not open config file with path: \"" + (std::string)Paths::CONFIG_FILE + "\". Creating new.");
	return false;
}

bool SettingsManager::load(pugi::xml_document* doc)
{
	try
	{
		pugi::xml_node root = doc->first_child();
		pugi::xml_node setting;
		pugi::xml_node setting2;


		setting = root.child("Resolution");

		setting2 = setting.child("Width");
		settings.graphicsSettings.resolution.set(std::stof(setting2.child_value()), 0.0f);

		setting2 = setting.child("Height");
		settings.graphicsSettings.resolution.set(settings.graphicsSettings.resolution.getX(), std::stof(setting2.child_value()));


		setting = root.child("FullScreen");
		settings.graphicsSettings.fullScreen = text2Bool(setting.child_value());

		setting = root.child("FpsLock");
		settings.graphicsSettings.fpsLock = (unsigned int)std::stoul(setting.child_value());

		setting = root.child("vSync");
		settings.graphicsSettings.vSync = text2Bool(setting.child_value());

		setting = root.child("Language");
		settings.language = setting.child_value();
	}
	catch (...)
	{
		Error e;
		e.message = "Can not load data from config file with path: \"" + (std::string)Paths::CONFIG_FILE + "\". Creating new.";
		e.flag = ERROR_CAN_NOT_READ_FILE;
		Logger::errorLog(0, e.message);
		throw e;
		return false;
	}
	return true;
}

void SettingsManager::setLanguage(std::string code)
{
	settings.language = code;
}

bool SettingsManager::text2Bool(std::string text)
{
	if (text == "true")
		return true;
	return false;
}

std::string  SettingsManager::bool2Text(bool b)
{
	if (b)
		return "true";
	return "false";
}

std::string SettingsManager::getLanguage()
{
	return settings.language;
}