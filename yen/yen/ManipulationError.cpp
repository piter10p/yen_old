#include "stdafx.h"
#include "ManipulationError.h"

using namespace yen;

ManipulationError::ManipulationError(Flag flag, int id)
{
	this->flag = flag;
	this->id = id;
}


ManipulationError::~ManipulationError()
{
}
