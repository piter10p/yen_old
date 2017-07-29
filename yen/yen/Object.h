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

		void addComponent(ComponentManipulator *, Component *);
		void removeComponent(ComponentManipulator);

		void codeStepUpdate(fVector cameraPos);
		void initialization(WorldManipulator);
		void load();
		void unLoad();

		void removeAllComponents();

		void setLoadDistance(float distance);
		float getLoadDistance();

		bool isLoaded();

		bool haveComponentofType(const std::string);

		bool test();

	private:
		fVector position;
		std::vector <Component*> components;
		ObjectAccessInterface objectAccessInterface;

		unsigned int getComponentListIndex(int id);
		bool isAnyComponentOfThisType(const std::string type);
		void fillObjectAccessInterface(WorldManipulator);
		float loadDistance = 0.0f;
		bool loaded = false;
		
	};
}
