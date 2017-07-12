#pragma once

namespace yen
{
	class fVector
	{
	public:
		float getX()
		{
			return x;
		}

		float getY()
		{
			return y;
		}

		void set(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

		void copy(fVector vector)
		{
			this->x = vector.x;
			this->y = vector.y;
		}

		void operator+=(fVector &vectorIn)
		{
			this->x += vectorIn.getX();
			this->y += vectorIn.getY();
		}

		fVector operator+(fVector &vectorIn)
		{
			fVector vectorOut;

			vectorOut.x = this->x + vectorIn.getX();
			vectorOut.y = this->y + vectorIn.getY();

			return vectorOut;
		}

		void operator-=(fVector &vectorIn)
		{
			this->x -= vectorIn.getX();
			this->y -= vectorIn.getY();
		}

		fVector operator-(fVector &vectorIn)
		{
			fVector vectorOut;

			vectorOut.x = this->x - vectorIn.getX();
			vectorOut.y = this->y - vectorIn.getY();

			return vectorOut;
		}

	private:
		float x;
		float y;
	};

	class uVector
	{
	public:
		unsigned int getX()
		{
			return x;
		}

		unsigned int getY()
		{
			return y;
		}

		void set(unsigned int x, unsigned int y)
		{
			this->x = x;
			this->y = y;
		}

		void copy(uVector vector)
		{
			this->x = vector.x;
			this->y = vector.y;
		}

	private:
		unsigned int x;
		unsigned int y;
	};
}
