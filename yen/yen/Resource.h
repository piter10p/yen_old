#pragma once
#include "Flag.h"

namespace yen
{
	class Resource
	{
		friend class ResourceEngine;

	protected:
		virtual Flag load() = 0;

		int id;
	};
}
