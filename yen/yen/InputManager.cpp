#include "stdafx.h"
#include "InputManager.h"
#include "KeyboardInput.h"
#include "Error.h"

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

void InputManager::createInput(InputManipulator* manipulator, InputDef def)
{
	if (def.name.empty())
		throw Flag::ERROR_DEF_OBJECT_IS_NOT_FILLED_PROPERLY;
	
	if (def.type == InputType::KEYBOARD_KEY)
		createKeyInput(manipulator, def);

	manipulator->id = getNewId();
}

void InputManager::removeInput(InputManipulator manipulator)
{
	if (manipulator.input->getType() == InputType::KEYBOARD_KEY)
	{
		removeKeyInput(manipulator);
	}
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

void InputManager::removeKeyInput(InputManipulator manipulator)
{
	for (unsigned int i = 0; i < keyboardInputs.size(); i++)
	{
		if (keyboardInputs[i]->getId() == manipulator.id)
		{
			delete keyboardInputs[i];
			keyboardInputs.erase(keyboardInputs.begin() + i);

			return;
		}
	}
	ManipulatorError e;
	e.flag = Flag::ERROR_NOTHING_FOUND_ID;
	e.type = "InputManipulator";
	e.id = manipulator.id;
	e.message = "InputManager did not found object of this manipulator";
	Logger::errorLog(0, e.message);
	throw e;
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
