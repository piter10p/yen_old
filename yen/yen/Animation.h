#pragma once
#include "Frame.h"
#include <vector>

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

	private:
		std::vector <Frame> frames;
		unsigned int frameRate;
	};
}
