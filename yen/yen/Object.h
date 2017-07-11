#pragma once
#include "Vector.h"
#include "Component.h"
#include <vector>
#include "ComponentManipulator.h"
#include "Flag.h"
#include "Id.h"
#include "IdSetter.h"

namespace yen
{
	class Object: public Id, public IdSetter
	{
	public:
		Object();
		~Object();

		void setPosition(fVector);
		fVector getPosition();

		Flag addComponent(ComponentManipulator *, Component *);
		Flag removeComponent(ComponentManipulator);

		void codeStepUpdate();
		void frameRenderUpdate();

		void removeAllComponents();

		bool test();

	private:
		fVector position;

		std::vector <Component*> components;

		int getComponentListIndex(int id);

		bool isAnyComponentOfThisType(const std::string type);
	};
}
