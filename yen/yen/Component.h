#pragma once
#include <string>
#include "Id.h"

namespace yen
{
	class Component: public Id
	{
	public:
		virtual void step() = 0;

		const std::string getType()
		{
			return type;
		}

	protected:
		const std::string type;
	};
}
