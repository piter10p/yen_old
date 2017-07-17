#include "stdafx.h"
#include "InputManager.h"
#include "KeyboardInput.h"

using namespace yen;


InputManager::InputManager()
{
}


InputManager::~InputManager()
{
	for (unsigned int i = 0; i < keyboardInputs.size(); i++)
	{
		delete keyboardInputs[i];
	}
}

Flag InputManager::createInput(InputManipulator* manipulator, InputDef def)
{
	if (def.name.empty())
		return Flag::ERROR_DEF_OBJECT_IS_NOT_FILLED_PROPERLY;
	
	if (def.type == InputType::KEYBOARD_KEY)
		createKeyInput(manipulator, def);

	manipulator->id = getNewId();
	
	return Flag::OK;
}

Flag InputManager::removeInput(InputManipulator manipulator)
{
	if (manipulator.input->getType() == InputType::KEYBOARD_KEY)
		return removeKeyInput(manipulator);
}

void InputManager::updateInputs(sf::RenderWindow *window)
{
	sf::Event sfEvent;

	while (window->pollEvent(sfEvent))
	{
		if (sfEvent.type == sf::Event::KeyPressed)
		{
			setKeyboardInputsPressed(sfEvent.key.code);
		}	
		else if (sfEvent.type = sf::Event::KeyReleased)
		{
			setKeyboardInputsReleased(sfEvent.key.code);
		}
	}
}

void InputManager::createKeyInput(InputManipulator* manipulator, InputDef def)
{
	KeyboardInput *input = new KeyboardInput(def);
	manipulator->keyboardInput = input;
	manipulator->input = input;

	keyboardInputs.push_back(input);
}

Flag InputManager::removeKeyInput(InputManipulator manipulator)
{
	for (unsigned int i = 0; i < keyboardInputs.size(); i++)
	{
		if (keyboardInputs[i]->getId() == manipulator.id)
		{
			delete keyboardInputs[i];
			keyboardInputs.erase(keyboardInputs.begin() + i);

			return Flag::OK;
		}
	}

	return Flag::ERROR_NOTHING_FOUND_ID;
}

void InputManager::setKeyboardInputsPressed(sf::Keyboard::Key sfKey)
{
	inputs::Key key = inputs::InputsConverter::sfKeyToKey(sfKey);

	for (unsigned int i = 0; i < keyboardInputs.size(); i++)
	{
		if (keyboardInputs[i]->getKey() == key)
			keyboardInputs[i]->pressed();
	}
}

void InputManager::setKeyboardInputsReleased(sf::Keyboard::Key sfKey)
{
	inputs::Key key = inputs::InputsConverter::sfKeyToKey(sfKey);

	for (unsigned int i = 0; i < keyboardInputs.size(); i++)
	{
		if (keyboardInputs[i]->getKey() == key)
			keyboardInputs[i]->released();
	}
}

bool InputManager::isKeyPressed(InputManipulator manipulator)
{
	return manipulator.keyboardInput->isKeyPressed();
}
