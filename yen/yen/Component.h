#pragma once
#include <string>
#include "Id.h"

namespace yen
{
	class Component: public Id
	{
	public:
		virtual void everyCodeStepUpdate() = 0;
		virtual void everyFrameRenderUpdate() = 0;

		const std::string getType()
		{
			return type;
		}

	protected:
		const std::string type;
	};
}
