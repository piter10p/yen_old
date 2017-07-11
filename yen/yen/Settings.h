#pragma once
#include "Vector.h"

namespace yen
{
	struct Settings
	{
		uVector resolution;
		bool fullScreen;

		bool fpsLock;
		unsigned int fpsLockValueinHz;
	};
}
