#pragma once
#include <string>
#include "Id.h"
#include "ObjectAccessInterface.h"
#include "Flag.h"
#include <vector>
#include "Error.h"
#include "Logger.h"

namespace yen
{
	class Component : public Id
	{
	public:
		virtual ~Component() {};

		virtual void codeStepUpdate(ObjectAccessInterface) = 0;
		virtual void initialization(ObjectAccessInterface) = 0;
		virtual void setResourcesUsed() = 0;

		virtual void freezed() = 0;
		virtual void unFreezed() = 0;

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

		Component* getComponent(std::string type)
		{
			for (unsigned int i = 0; i < componentsSize; i++)
			{
				if (components[i]->getType() == type)
				{
					return components[i];
				}
			}
			Logger::errorLog(0, "Object dont have component of type: " + type + ".");
			Error e;
			e.flag = Flag::ERROR_OBJECT_DONT_HAVE_COMPONENT_OF_THIS_TYPE;
			throw e;
		}

	private:
		Component **components;
		int componentsSize;
	};
}
