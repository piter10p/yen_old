#pragma once
#include "Input.h"

namespace yen
{
	class KeyboardInput : public Input
	{
	public:
		KeyboardInput(InputDef);
		~KeyboardInput();

		void setKey(inputs::Key);
		inputs::Key getKey();

		void pressed();
		void released();

		bool isKeyPressed();

	private:
		inputs::Key key;

		bool keyPressed;
	};
}
