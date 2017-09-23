#pragma once


namespace yen
{
	class Color
	{
	public:
		Color()
		{
			r = 0;
			g = 0;
			b = 0;
			a = 0;
		}

		Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
		{
			set(r, g, b, a);
		}

		void set(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
		{
			{
				this->r = r;
				this->g = g;
				this->b = b;
				this->a = a;
			}
		}

		unsigned char getR()
		{
			return r;
		}

		unsigned char getG()
		{
			return g;
		}

		unsigned char getB()
		{
			return b;
		}

		unsigned char getA()
		{
			return a;
		}

	private:
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;
	};
}