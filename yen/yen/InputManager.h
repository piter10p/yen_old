#pragma once
#include "IdSetter.h"
#include "KeyboardInput.h"
#include <vector>
#include "Flag.h"
#include "InputDef.h"
#include "InputManipulator.h"
#include "SFML/Graphics.hpp"

namespace yen
{
	class InputManager: public IdSetter
	{
	public:
		InputManager();
		~InputManager();

		Flag createInput(InputManipulator*, InputDef);
		Flag removeInput(InputManipulator);

		void updateInputs(sf::RenderWindow *window);

		bool isKeyPressed(InputManipulator);

	private:
		std::vector<KeyboardInput*> keyboardInputs;

		void createKeyInput(InputManipulator*, InputDef);

		Flag removeKeyInput(InputManipulator);

		void setKeyboardInputsPressed(sf::Keyboard::Key);
		void setKeyboardInputsReleased(sf::Keyboard::Key);
	};
}
