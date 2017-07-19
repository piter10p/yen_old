#include "stdafx.h"
#include "Object.h"

using namespace yen;

Object::Object()
{
	position.set(0.0f, 0.0f);
}


Object::~Object()
{
	removeAllComponents();
}

void Object::setPosition(fVector vector)
{
	position.copy(vector);
}

fVector Object::getPosition()
{
	return position;
}

Flag Object::addComponent(ComponentManipulator *manipulator, Component *component)
{
	if (isAnyComponentOfThisType(component->getType()))
		return Flag::ERROR_COMPONENT_WITH_THIS_TYPE_HAS_BEEN_ADDED_ALREADY;

	component->setId(getNewId());
	components.push_back(component);

	manipulator->id = component->getId();

	return Flag::OK;
}

Flag Object::removeComponent(ComponentManipulator manipulator)
{
	int index = getComponentListIndex(manipulator.id);
	if (index != -1)
	{
		delete components[index];
		components.erase(components.begin() + index);
		return Flag::OK;
	}
	return Flag::ERROR_NOTHING_FOUND_ID;
}

void Object::codeStepUpdate(fVector cameraPos)
{
	objectAccessInterface.cameraPosition = cameraPos;

	for (int  i = 0; i < components.size(); i++)
	{
		components[i]->codeStepUpdate(objectAccessInterface);
	}
}

void Object::initialization(WorldManipulator worldManipulator)
{
	fillObjectAccessInterface(worldManipulator);

	for (int i = 0; i < components.size(); i++)
	{
		components[i]->initialization(objectAccessInterface);
	}
}

Flag Object::load()
{
	for (int i = 0; i < components.size(); i++)
	{
		Flag flag = components[i]->load();
		if (flag != Flag::OK)
			return flag;
	}
	return Flag::OK;
}

bool Object::haveComponentofType(const std::string type)
{
	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]->getType() == type)
			return true;
	}
	return false;
}

bool Object::test()
{
	class TestComponent : public Component
	{
	public:
		void codeStepUpdate(ObjectAccessInterface) {};
		void initialization(ObjectAccessInterface) {};
		Flag load() { return Flag::OK; };
	protected: std::string type = "TestComponent";
	};

	TestComponent *component = new TestComponent();

	ComponentManipulator manipulator;
	Flag flag = addComponent(&manipulator, component);
	if (flag != Flag::OK)
		return false;

	flag = removeComponent(manipulator);
	if (flag != Flag::OK)
		return false;
	
	return true;
}

int Object::getComponentListIndex(int id)
{
	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]->getId() == id)
			return i;
	}
	return -1;
}

void Object::removeAllComponents()
{
	components.clear();
}

bool Object::isAnyComponentOfThisType(const std::string type)
{
	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]->getType() == type)
			return true;
		return false;
	}
	return false;
}

void Object::fillObjectAccessInterface(WorldManipulator worldManipulator)
{
	objectAccessInterface.position = &this->position;
	objectAccessInterface.worldManipulator = worldManipulator;
}