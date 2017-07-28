#include "stdafx.h"
#include "LangString.h"

using namespace yen;

LangString::LangString(std::string name, std::string text)
{
	this->name = name;
	this->text = text;
}


LangString::~LangString()
{
}

std::string LangString::getName()
{
	return name;
}

std::string LangString::getText()
{
	return text;
}
