#pragma once
#include <string>
#include "Id.h"
#include "ObjectAccessInterface.h"
#include "Flag.h"

namespace yen
{
	class Component : public Id
	{
	public:
		virtual ~Component() {};

		virtual void codeStepUpdate(ObjectAccessInterface) = 0;
		virtual void initialization(ObjectAccessInterface) = 0;
		virtual Flag load() = 0;

		const std::string getType()
		{
			return type;
		}

	protected:
		std::string type;
	};
}
