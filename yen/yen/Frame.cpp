#include "stdafx.h"
#include "Frame.h"

using namespace yen;

Frame::Frame()
{
}


Frame::~Frame()
{
}

void Frame::load(std::string path)
{
	if (!texture.loadFromFile(path))
		throw Flag::ERROR_CAN_NOT_OPEN_FILE;
}

sf::Texture* Frame::getTexture()
{
	return &texture;
}