#include "stdafx.h"
#include "Animation.h"
#include <boost\filesystem.hpp>

using namespace yen;

Animation::Animation()
{
}


Animation::~Animation()
{
}

Flag Animation::load(std::string path)
{
	return Flag::OK;
}

void Animation::setFrameRate(unsigned int frameRate)
{
	this->frameRate = frameRate;
}

unsigned int Animation::getFrameRate()
{
	return this->frameRate;
}
