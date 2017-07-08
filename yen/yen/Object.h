#pragma once
#include "Vector.h"
#include "Component.h"
#include <vector>
#include "ComponentManipulator.h"

namespace yen
{
	class Object
	{
	public:
		Object();
		~Object();

		friend class ObjectsManager;
		friend class Scene;

	protected:
		int id;
		void setPosition(Vector);

		ComponentManipulator addComponent(Component*);
		bool removeComponent(ComponentManipulator);

		void callComponentsStepFuncion();

	private:
		Vector position;

		std::vector <Component*> components;

		int componentsIdCounter;
		int getNewComponentsId();

		int getComponentListIndex(int id);

		void removeAllComponents();
	};
}
