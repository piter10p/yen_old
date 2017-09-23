#pragma once
#include "Vector.h"
#include "Component.h"
#include <vector>
#include "ComponentManipulator.h"
#include "Flag.h"
#include "Id.h"
#include "IdSetter.h"
#include "GraphicsComponent.h"
#include "CameraComponent.h"

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

		void codeStepUpdate();
		void initialization(WorldManipulator);
		void setResourcesUsed();

		void removeAllComponents();

		void setLoadDistance(float distance);
		float getLoadDistance();

		bool isFreezed();
		void freeze();
		void unFreeze();

		bool haveComponentofType(const std::string);

		GraphicsComponent* getGraphicsComponent(); //return nullptr if no component
		CameraComponent* getCameraComponent(); //return nullptr if no component

	private:
		fVector position;
		std::vector <Component*> components;
		ObjectAccessInterface objectAccessInterface;

		unsigned int getComponentListIndex(int id);
		bool isAnyComponentOfThisType(const std::string type);
		void fillObjectAccessInterface(WorldManipulator);
		float loadDistance = 0.0f;
		bool freezed = true;

		bool initialized = false;
	};
}
