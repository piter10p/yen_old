#pragma once
#include <cmath>

namespace yen
{
	class fVector
	{
	public:
		fVector()
		{
			zero();
		}

		fVector(float x, float y)
		{
			this->x = x;
			this->y = y;
		}

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

		void zero()
		{
			this->x = 0.0f;
			this->y = 0.0f;
		}

		static float getDistance(fVector vector1, fVector vector2)
		{
			return sqrt(pow((vector2.getX() - vector1.getX()), 2.0f) + pow((vector2.getY() - vector1.getY()), 2.0f)); // square root( (B.x - A.x)^2 + (B.y - A.y)^2 )
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
		uVector()
		{
			zero();
		}

		uVector(unsigned int x, unsigned int y)
		{
			this->x = x;
			this->y = y;
		}

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

		void zero()
		{
			this->x = 0;
			this->y = 0;
		}

	private:
		unsigned int x;
		unsigned int y;
	};

	class fRect
	{
	public:
		fRect()
		{
			zero();
		}

		fRect(fVector position, fVector size)
		{
			this->position = position;
			this->size = size;
		}

		float getX()
		{
			return position.getX();
		}

		float getY()
		{
			return position.getY();
		}

		float getWidth()
		{
			return size.getX();
		}

		float getHeight()
		{
			return size.getY();
		}

		float setPosition(fVector position)
		{
			this->position = position;
		}

		float setSize(fVector size)
		{
			this->size = size;
		}

		void zero()
		{
			position.zero();
			size.zero();
		}

	private:
		fVector position;
		fVector size;
	};
}
