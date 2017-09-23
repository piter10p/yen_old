#pragma once
#include "Id.h"
#include <string>
#include <SFML\Window\Keyboard.hpp>
#include "Keys.h"

namespace yen
{
	enum InputType
	{
		KEYBOARD_KEY,
		JOYSTICK_BUTTON,
		JOYSTICK_AXIS
	};

	struct InputDef
	{
		InputType type;
		std::string name;

		inputs::Key key;
	};

	class Input: public Id 
	{
	public:
		Input();
		~Input();

		InputType getType();

	protected:
		std::string name;
		InputType type;
	};
}
