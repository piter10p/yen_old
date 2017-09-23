#pragma once
#include "Scene.h"

namespace yen
{
	class SceneManipulator
	{
		friend class SceneManager;
	protected:
		Scene *scene;
		int id;
	};
}
