#include "stdafx.h"
#include "Language.h"

using namespace yen;

Language::Language(const std::string code)
{
	this->code = code;
}


Language::~Language()
{
}

std::string Language::getCode()
{
	return code;
}
