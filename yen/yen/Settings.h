#pragma once
#include "Vector.h"
#include <string>

namespace yen
{
	struct GraphicsSettings
	{
		uVector resolution;
		bool fullScreen;
		unsigned int fpsLock;
		bool vSync;
	};

	struct Settings
	{
		GraphicsSettings graphicsSettings;

		std::string language;
	};
}
