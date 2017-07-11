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

void Object::setPosition(Vector vector)
{
	position.copy(vector);
}

Vector Object::getPosition()
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

void Object::codeStepUpdate()
{
	for (int  i = 0; i < components.size(); i++)
	{
		components[i]->everyCodeStepUpdate();
	}
}

void Object::frameRenderUpdate()
{
	for (int i = 0; i < components.size(); i++)
	{
		components[i]->everyFrameRenderUpdate();
	}
}

bool Object::test()
{
	class TestComponent : public Component
	{
	public: void step() {};
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
	for (int i = 0; i < components.size(); i++)
	{
		delete components[i];
	}
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
}