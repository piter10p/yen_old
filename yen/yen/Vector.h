#pragma once

namespace yen
{
	class Vector
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

		void copy(Vector vector)
		{
			this->x = vector.x;
			this->y = vector.y;
		}

	private:
		float x;
		float y;
	};
}
