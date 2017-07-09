#pragma once
#include <vector>
#include "Id.h"

namespace yen
{
	class Manager
	{
	protected:
		int getIndexInListOfIdInherited(std::vector <Id*> list, int id);// return -1 if not found any of that id
	};
}
