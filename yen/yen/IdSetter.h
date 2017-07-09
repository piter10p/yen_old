#pragma once

namespace yen
{
	class IdSetter
	{
	public:
		int getNewId();

	private:
		int idCounter = 0;
	};
}
