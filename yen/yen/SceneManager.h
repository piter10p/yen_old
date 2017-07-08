#pragma once
#include <vector>
#include "Object.h"

namespace yen
{
	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

	protected:
		std::vector <Object> objects;
	};
}
