#include "stdafx.h"
#include "Frame.h"

using namespace yen;

Frame::Frame()
{
}


Frame::~Frame()
{
}

Flag Frame::load(std::string path)
{
	if (!texture.loadFromFile(path))
		return Flag::ERROR_CAN_NOT_OPEN_FILE;
	return Flag::OK;
}

sf::Texture* Frame::getTexture()
{
	return &texture;
}