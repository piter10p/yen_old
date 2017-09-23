#include "stdafx.h"
#include "Manager.h"

using namespace yen;

int Manager::getIndexInListOfIdInherited(std::vector <Id*> list, int id)
{
	for (int i = 0; i < list.size(); i++)
	{
		if (list[i]->getId() == id)
			return i;
	}
	return -1;
}
