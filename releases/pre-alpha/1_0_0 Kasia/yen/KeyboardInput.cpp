#include "stdafx.h"
#include "KeyboardInput.h"

using namespace yen;

KeyboardInput::KeyboardInput(InputDef def)
{
	name = def.name;
	type = def.type;
	key = def.key;

	keyPressed = false;
}


KeyboardInput::~KeyboardInput()
{
}

void KeyboardInput::setKey(inputs::Key key)
{
	this->key = key;
}

inputs::Key KeyboardInput::getKey()
{
	return key;
}

void KeyboardInput::pressed()
{
	keyPressed = true;
}

void KeyboardInput::released()
{
	keyPressed = false;
}

bool KeyboardInput::isKeyPressed()
{
	return keyPressed;
}
