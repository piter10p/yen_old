#include "stdafx.h"
#include "StringResource.h"
#include "Paths.h"
#include <pugixml.hpp>

using namespace yen;

StringResource::StringResource(std::string path, int id, Language *actualLanguage)
{
	this->path = path;
	this->actualLanguage = actualLanguage;
	setId(id);
}


StringResource::~StringResource()
{
}

void StringResource::load()
{
	std::string filePath = Paths::DATA_FOLDER;
	filePath += Paths::LANG_FOLDER;
	filePath += path;
}

void StringResource::unLoad()
{

}
