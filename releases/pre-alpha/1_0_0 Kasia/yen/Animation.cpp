#include "stdafx.h"
#include "Animation.h"
#include "FileSystem.h"
#include "boost\convert.hpp"
#include "boost\numeric\conversion\converter.hpp"
#include "Error.h"
#include "Logger.h"

using namespace yen;

Animation::Animation()
{
}


Animation::~Animation()
{
}

void Animation::load(std::string path)
{
	std::vector <std::string> filesList;

	try
	{
		filesList = FileSystem::getAllFilesPathsinDirectory(path);


		if (filesList.empty())
		{
			FileManipulationError e;
			e.flag = Flag::ERROR_DIRECTORY_EMPTY;
			e.path = path;
			throw e;
		}

		for each (std::string filePath in filesList)
		{
			Frame frame;

			if (frame.load(filePath) != Flag::OK)
			{
				FileManipulationError e;
				e.flag = Flag::ERROR_CAN_NOT_OPEN_FILE;
				e.path = filePath;
				throw e;
			}

			frames.push_back(frame);
		}
	}
	catch(FileManipulationError e)
	{
		if (e.flag == Flag::ERROR_BAD_PATH)
			e.message = "Can not create file list in directory: \"" + e.path + "\". Is path right?";
		else if (e.flag == Flag::ERROR_DIRECTORY_EMPTY)
			e.message = "Direcotry defined in path: \"" + e.path + "\" is empty.";			
		else if (e.flag == Flag::ERROR_CAN_NOT_OPEN_FILE)
			e.message = "Can not open frame file. File path: \"" + e.path + "\".";
		else
			e.message = "Unknown error.";
			
		Logger::errorLog(0, e.message);
		throw e;
	}
	catch (...)
	{
		Error e;
		e.flag = Flag::ERROR_UNDEFINED;
		e.message = "Undefined error in Animation::load()";
		Logger::errorLog(0, e.message);
		
		throw e;
	}
}

void Animation::unLoad()
{
	frames.clear();
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
	if (timer.isTimeElapsed() && frameRate != 0)
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
