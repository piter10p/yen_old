#include "stdafx.h"
#include "FontResource.h"
#include "Error.h"
#include "Paths.h"

using namespace yen;

FontResource::FontResource(std::string path)
{
	this->path = path;
}


FontResource::~FontResource()
{
}

void FontResource::load()
{
	std::string filePath = generatePath();

	if (font.loadFromFile(filePath) != true)
	{
		Error e;
		e.message = "Can not load font file: \"" + filePath + "\".";
		e.flag = Flag::ERROR_CAN_NOT_OPEN_FILE;
		Logger::errorLog(0, e.message);
		throw e;
	}
}
void FontResource::unLoad()
{
}

sf::Font& FontResource::getFont()
{
	return font;
}

std::string FontResource::generatePath()
{
	std::string filePath;
	filePath = Paths::DATA_FOLDER;
	filePath += Paths::FONTS_FOLDER;
	filePath += this->path;

	return filePath;
}
