#pragma once

namespace yen
{
	class Component
	{
		friend class Object;
	protected:
		virtual void step() = 0;
		int id;
	};
}
