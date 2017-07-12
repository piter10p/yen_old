#pragma once
#include <SFML\System\Clock.hpp>

namespace yen
{
	namespace time
	{
		class Timer
		{
		public:
			Timer();

			virtual bool isTimeElapsed() = 0;
			void setElapseTime(float seconds);

			void start();
			void pause();
			void restart();
			bool isPaused();

		protected:
			sf::Clock clock;
			sf::Time elapseTime;
			sf::Time elapsedTime;
			sf::Time pauseTime;

			bool paused = true;
		};

		class LoopTimer: public Timer
		{
		public:
			bool isTimeElapsed();
		};

		class FixedTimeLoopTimer: public Timer
		{
		public:
			bool isTimeElapsed();

		};
	}
}
