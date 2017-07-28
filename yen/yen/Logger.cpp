#include "stdafx.h"
#include "Logger.h"
#include <iomanip>
#include <ctime>
#include "Paths.h"

using namespace yen;

Flag Logger::log(unsigned int indentation, std::string sign, std::string message)
{
	std::fstream file;

	if (openFileAtEnd(&file) != Flag::OK)
		return ERROR_CAN_NOT_OPEN_FILE;

	std::string logText = prepareLogText(indentation, sign, message);
	file << logText << "\n";

	closeFile(&file);
	return Flag::OK;
}

Flag Logger::infoLog(unsigned int indentation, std::string message)
{
	return log(indentation, INFO_SIGN, message);
}

Flag Logger::insertReturn()
{
	std::fstream file;

	if (openFileAtEnd(&file) != Flag::OK)
		return ERROR_CAN_NOT_OPEN_FILE;

	file << "\n";

	closeFile(&file);
	return Flag::OK;
}

Flag Logger::prepareFile()
{
	std::fstream file;
	file.open(Paths::LOG_FILE, std::ios::out | std::ios::trunc);

	if (!file.good())
		return Flag::ERROR_CAN_NOT_OPEN_FILE;

	insertLogHeader(&file);

	file.close();

	return Flag::OK;
}

Flag Logger::errorLog(unsigned int indentation, std::string message)
{
	return log(indentation, ERROR_SIGN, message);
}

Flag Logger::openFileAtEnd(std::fstream *file)
{
	file->open(Paths::LOG_FILE, std::ios::out | std::ios::app);

	if (file->good())
		return Flag::OK;
	return Flag::ERROR_CAN_NOT_OPEN_FILE;
}

void Logger::closeFile(std::fstream *file)
{
	file->close();
}

void Logger::insertTabs(unsigned int indentation, std::string *text)
{
	for (unsigned int i = 0; i < indentation; i++)
	{
		*text += "\t";
	}
}

std::string Logger::prepareLogText(unsigned int indentation, std::string sign, std::string message)
{
	std::string logText;
	insertTabs(indentation, &logText);
	logText += "[";
	logText += sign;
	logText += "]";
	logText += "> ";
	logText += message;

	return logText;
}

void Logger::insertLogHeader(std::fstream *file)
{
	std::string header = "|| YEN Log File || ";
	header += getDate();
	header += " ||";

	insertLine(file, static_cast<unsigned int>(header.size()));
	*file << header;
	*file << "\n";
	insertLine(file, static_cast<unsigned int>(header.size()));
	*file << "\n\n";
}

void Logger::insertLine(std::fstream *file, unsigned int length)
{
	for (unsigned int i = 0; i < length; i++)
	{
		*file << "=";
	}
	*file << "\n";
}

std::string Logger::getDate()
{
	time_t t = std::time(nullptr);
	tm *tm = std::localtime(&t);

	std::string out = asctime(tm);
	out.resize(out.size() - 1);	//remove end line char

	return out;
}
