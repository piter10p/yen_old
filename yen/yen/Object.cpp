#include "stdafx.h"
#include "Object.h"
#include "Error.h"
#include "Logger.h"

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

void Object::addComponent(ComponentManipulator *manipulator, Component *component)
{
	try
	{
		if (isAnyComponentOfThisType(component->getType()))
		{
			ManipulatorError e;
			e.flag = Flag::ERROR_COMPONENT_WITH_THIS_TYPE_HAS_BEEN_ADDED_ALREADY;
			e.type = "ComponentManipulator";
			e.id = manipulator->id;
			throw e;
		}

		component->setId(getNewId());
		components.push_back(component);

		manipulator->id = component->getId();
	}
	catch (ManipulatorError e)
	{
		Logger::errorLog(0, "Can not add component with id: " + std::to_string(e.id) + " to object with id: " + std::to_string(this->getId()) + ". Component of this type has been added already.");
		throw e;
	}
	catch (...)
	{
		Logger::errorLog(0, "Undefined error in Object::addComponent(). Object id: " + std::to_string(this->getId()) + ".");
		Error e;
		e.flag = Flag::ERROR_UNDEFINED;
		throw e;
	}
}

void Object::removeComponent(ComponentManipulator manipulator)
{
	try
	{
		unsigned int index = getComponentListIndex(manipulator.id);
		delete components[index];
		components.erase(components.begin() + index);
		return;
	}
	catch (Error e)
	{
		Logger::errorLog(0, "Can not remove component with id: " + std::to_string(manipulator.id) + " from object with id: " + std::to_string(this->getId()) + ". Component with this id is not exists.");
		throw e;
	}
	catch (const std::out_of_range& oor)
	{
		Logger::errorLog(0, "Can not remove component with id : " + std::to_string(manipulator.id) + " from object with id : " + std::to_string(this->getId()) + ". Component index is out of range.");
		Error e;
		e.flag = Flag::ERROR_INDEX_OUT_OF_LIST_RANGE;
		throw e;
	}
	catch (...)
	{
		Logger::errorLog(0, "Undefined error in Object::removeComponent() in object with id: " + std::to_string(this->getId()) + ".");
		Error e;
		e.flag = Flag::ERROR_UNDEFINED;
		throw e;
	}
}

void Object::codeStepUpdate(fVector cameraPos)
{
	if (!freezed)
	{
		objectAccessInterface.cameraPosition = cameraPos;

		for (int i = 0; i < components.size(); i++)
		{
			components[i]->codeStepUpdate(objectAccessInterface);
		}
	}
}

void Object::initialization(WorldManipulator worldManipulator)
{
	if (!initialized)
	{
		fillObjectAccessInterface(worldManipulator);

		for (int i = 0; i < components.size(); i++)
		{
			components[i]->initialization(objectAccessInterface);
			components[i]->setObjectData(&components);
		}

		initialized = true;
	}
}

void Object::setResourcesUsed()
{
	try
	{
		for (int i = 0; i < components.size(); i++)
		{
			components[i]->setResourcesUsed();
		}
	}
	catch(Error e)
	{
		throw e;
	}
	catch (ManipulatorError e)
	{
		throw e;
	}
	catch (...)
	{
		Logger::errorLog(0, "Undefined error in Object::load() in object with id: " + std::to_string(this->getId()) + ".");
		Error e;
		e.flag = Flag::ERROR_UNDEFINED;
		throw e;
	}
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

unsigned int Object::getComponentListIndex(int id)
{
	for (int i = 0; i < components.size(); i++)
	{
		if (components[i]->getId() == id)
			return i;
	}
	Logger::errorLog(0, "Number: " + std::to_string(id) + " is out of range of components list of object with id: " + std::to_string(this->getId()) + ".");
	Error e;
	e.flag = Flag::ERROR_NOTHING_FOUND_ID;
	throw e;
}

void Object::removeAllComponents()
{
	components.clear();
}

void Object::setLoadDistance(float distance)
{
	this->loadDistance = distance;
}

float Object::getLoadDistance()
{
	return loadDistance;
}

bool Object::isFreezed()
{
	return freezed;
}

void Object::freeze()
{
	freezed = true;

	for (unsigned int i = 0; i < components.size(); i++)
	{
		components[i]->freezed();
	}
}

void Object::unFreeze()
{
	freezed = false;

	for (unsigned int i = 0; i < components.size(); i++)
	{
		components[i]->unFreezed();
	}
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