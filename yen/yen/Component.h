#pragma once
#include <string>
#include "Id.h"
#include "ObjectAccessInterface.h"
#include "Flag.h"
#include <vector>

namespace yen
{
	class Component : public Id
	{
	public:
		virtual ~Component() {};

		virtual void codeStepUpdate(ObjectAccessInterface) = 0;
		virtual void initialization(ObjectAccessInterface) = 0;
		virtual Flag load() = 0;
		virtual void unLoad() = 0;

		void setObjectData(std::vector<Component*>*components)
		{
			this->components = components->data();
			componentsSize = components->size();
		}

		const std::string getType()
		{
			return type;
		}

	protected:
		std::string type;
		Component **components;
		int componentsSize;

		Flag getComponent(Component *out, std::string type)
		{
			for (unsigned int i = 0; i < componentsSize; i++)
			{
				if (components[i]->getType() == type)
				{
					out = components[i];
					return Flag::OK;
				}
			}
			return Flag::ERROR_OBJECT_DONT_HAVE_COMPONENT_OF_THIS_TYPE;
		}
	};
}
