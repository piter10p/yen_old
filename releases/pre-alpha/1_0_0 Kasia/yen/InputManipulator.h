#pragma once
#include "KeyboardInput.h"

namespace yen
{
	class InputManipulator
	{
		friend class InputManager;
	protected:
		Input *input;
		KeyboardInput *keyboardInput;
		int id;
	};
}
