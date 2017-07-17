#include "stdafx.h"
#include "Keys.h"
#include "boost\convert.hpp"

using namespace yen::inputs;

sf::Keyboard::Key InputsConverter::keyToSfKey(Key key)
{
	sf::Keyboard::Key keyOut = (sf::Keyboard::Key)key;
	return keyOut;
}

Key InputsConverter::sfKeyToKey(sf::Keyboard::Key key)
{
	Key keyOut = (Key)key;
	return keyOut;
}

std::string InputsConverter::getKeyString(Key)
{
	std::string out;
	out = "[";



	out += "]";
	return out;
}
