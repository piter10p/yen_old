#include "stdafx.h"
#include "StringResource.h"
#include "Paths.h"
#include "Error.h"
#include "Logger.h"

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
	std::string filePath = generatePath();

	try
	{
		pugi::xml_document doc;
		openDocument(&doc, filePath);
		loadStrings(&doc);
	}
	catch (Error e)
	{
		if (e.flag == Flag::ERROR_CAN_NOT_OPEN_FILE)
			e.message = "Can not open string file with path: \"" + filePath + "\".";
		else
			e.message = "Undefined error.";

		Logger::errorLog(0, e.message);
	}
	catch (...)
	{
		Logger::errorLog(0, "Undefined error.");
	}
}

void StringResource::unLoad()
{

}

std::string StringResource::getString(std::string stringName)
{
	for (unsigned int i = 0; i < strings.size(); i++)
	{
		if (strings[i].getName() == stringName)
			return strings[i].getText();
	}

	Error e;
	e.flag = Flag::ERROR_CAN_NOT_FIND_STRING_WITH_SPECIFIC_NAME;
	e.message = "String with name: \"" + stringName + "\" was not found.";
	Logger::errorLog(0, e.message);
	throw e;
}

std::string StringResource::generatePath()
{
	std::string filePath = Paths::DATA_FOLDER;
	filePath += Paths::LANG_FOLDER;
	filePath += actualLanguage->getCode();
	filePath += "\\";
	filePath += path;

	return filePath;
}

void StringResource::openDocument(pugi::xml_document *doc, std::string filePath)
{
	pugi::xml_parse_result result = doc->load_file(filePath.c_str());
	if (result.status != pugi::status_ok)
	{
		Error e;
		e.flag = Flag::ERROR_CAN_NOT_OPEN_FILE;
		throw e;
	}
}

void StringResource::loadStrings(pugi::xml_document *doc)
{
	pugi::xml_node root = doc->first_child();
	
	for (pugi::xml_node string = root.first_child(); string; string = string.next_sibling())
	{
		LangString langString(string.name() , string.child_value());
		strings.push_back(langString);
	}
}