#include "stdafx.h"
#include "IdSetter.h"

using namespace yen;

int IdSetter::getNewId()
{
	idCounter++;
	return idCounter - 1;
}