#include "stdafx.h"
#include "SettingsManager.h"
#include "Vector.h"

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
