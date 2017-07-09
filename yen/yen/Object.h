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

		void setPosition(Vector);
		Vector getPosition();

		Flag addComponent(ComponentManipulator *, Component *);
		Flag removeComponent(ComponentManipulator);

		void everyCodeStepUpdate();
		void everyFrameRenderUpdate();

		void removeAllComponents();

		bool test();

	private:
		Vector position;

		std::vector <Component*> components;

		int getComponentListIndex(int id);

		bool isAnyComponentOfThisType(const std::string type);
	};
}
