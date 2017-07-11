#pragma once
#include "Vector.h"

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
	};
}
