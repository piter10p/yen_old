#pragma once

#include <vector>
#include "Resource.h"

namespace yen
{
	class ResourceEngine
	{
	public:
		ResourceEngine();
		~ResourceEngine();

	private:
		std::vector <Resource*> resources;
	};
}
