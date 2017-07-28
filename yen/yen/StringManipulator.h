#pragma once
#include "StringResource.h"
#include "Id.h"

namespace yen
{
	class StringManipulator: public Id
	{
		friend class ResourceManager;
	protected:
		StringResource *resource;
		int id;
	};
}
