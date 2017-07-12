#pragma once
#include "Frame.h"
#include <vector>
#include "Time.h"

namespace yen
{
	class Animation
	{
	public:
		Animation();
		~Animation();

		Flag load(std::string path);
		void setFrameRate(unsigned int);
		unsigned int getFrameRate();

		Frame* getActualFrame();

		void start();
		void pause();
		void restart();
		bool isPlaying();


	private:
		std::vector <Frame> frames;
		unsigned int frameRate = 0;
		time::LoopTimer timer;

		unsigned int actualFrameId = 0;

		bool playing = false;

		float frameRateToSeconds(unsigned int frameRate);

		void increaseActualFrameIdNumer();
	};
}
