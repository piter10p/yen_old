#pragma once
#include "Flag.h"
#include "Id.h"

namespace yen
{
	class Resource :public Id
	{
	public:
		virtual void load() = 0;
	};
}
