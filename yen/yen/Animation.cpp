#include "stdafx.h"
#include "Animation.h"
#include "FileSystem.h"
#include "boost\convert.hpp"
#include "boost\numeric\conversion\converter.hpp"

using namespace yen;

Animation::Animation()
{
}


Animation::~Animation()
{
}

Flag Animation::load(std::string path)
{
	std::vector <std::string> filesList = FileSystem::getAllFilesPathsinDirectory(path);

	if (filesList.empty())
		return Flag::ERROR_DIRECTORY_EMPTY;

	for each (std::string filePath in filesList)
	{
		Frame frame;

		if (frame.load(filePath) != Flag::OK)
			return Flag::ERROR_CAN_NOT_LOAD_FILE;

		frames.push_back(frame);
	}

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

Frame* Animation::getActualFrame()
{
	if (timer.isTimeElapsed())
	{
		increaseActualFrameIdNumer();
	}

	return &frames[actualFrameId];
}

void Animation::start()
{
	timer.setElapseTime(frameRateToSeconds(frameRate));
	timer.start();
}

void Animation::pause()
{
	timer.pause();
}

void Animation::restart()
{
	timer.restart();
	actualFrameId = 0;
}

bool Animation::isPlaying()
{
	return !timer.isPaused();
}

float Animation::frameRateToSeconds(unsigned int frameRate)
{
	boost::numeric::converter <float, unsigned int> ftouintConverter;
	
	float convertedTime = ftouintConverter(frameRate);

	return 1.0f / convertedTime;
}

void Animation::increaseActualFrameIdNumer()
{
	if (actualFrameId < frames.size() - 1)
		actualFrameId++;
	else
		actualFrameId = 0;
}
