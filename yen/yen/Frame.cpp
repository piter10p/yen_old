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
	if (texture.loadFromFile(path))
		return Flag::OK;
	return Flag::ERROR_CAN_NOT_LOAD_FILE;
}

sf::Texture* Frame::getTexture()
{
	return &texture;
}