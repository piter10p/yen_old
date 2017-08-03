#pragma once
#include "FontResource.h"
#include "Id.h"

namespace yen
{
	class FontManipulator: Id
	{
		friend class ResourceManager;
		friend class GraphicsComponent;
	protected:
		FontResource *resource;
	};
}