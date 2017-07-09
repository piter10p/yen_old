#pragma once
#include "Flag.h"

namespace yen
{
	class Resource
	{
		friend class ResourceManager;

	protected:
		virtual Flag load() = 0;

		int id;
	};
}
