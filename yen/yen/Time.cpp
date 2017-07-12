#include "stdafx.h"
#include "Time.h"

using namespace yen::time;

Timer::Timer()
{
	restart();
	elapsedTime = sf::Time::Zero;
	elapseTime = sf::Time::Zero;
	pauseTime = sf::Time::Zero;
	paused = true;
}

void Timer::setElapseTime(float seconds)
{
	this->elapseTime = sf::seconds(seconds);
}

void Timer::start()
{
	if (paused)
	{
		clock.restart();
		elapsedTime += pauseTime;
		paused = false;
	}
}

void Timer::pause()
{
	if (!paused)
	{
		pauseTime = clock.getElapsedTime();
		paused = true;
	}
}

void Timer::restart()
{
	clock.restart();
	elapsedTime = sf::Time::Zero;
	pauseTime = sf::Time::Zero;
	paused = false;
}

bool Timer::isPaused()
{
	return paused;
}

bool LoopTimer::isTimeElapsed()
{
	if (!paused)
	{
		elapsedTime += clock.getElapsedTime();
		clock.restart();

		if (elapsedTime > elapseTime)
		{
			elapsedTime = sf::Time::Zero;
			return true;
		}
	}
	
	return false;
}

bool FixedTimeLoopTimer::isTimeElapsed()
{
	if (!paused)
	{
		elapsedTime += clock.getElapsedTime();
		clock.restart();

		if (elapsedTime > elapseTime)
		{
			elapsedTime -= elapseTime;
			return true;
		}
	}
	
	return false;
}
