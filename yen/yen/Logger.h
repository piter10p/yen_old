#pragma once
#include <string>
#include <fstream>
#include "Flag.h"

namespace yen
{
	static class Logger
	{
	public:
		static Flag log(unsigned int indentation, std::string sign, std::string message);
		static Flag infoLog(unsigned int indentation, std::string message);
		static Flag errorLog(unsigned int indentation, std::string message);
		static Flag insertReturn();

		static Flag prepareFile();

		static constexpr const char* LOG_FILE_PATH = "log.txt";
		static constexpr const char* INFO_SIGN = "@";
		static constexpr const char* ERROR_SIGN = "!!!";
		static constexpr const char* UNSURE_SIGN = "??";

	private:
		static Flag openFileAtEnd(std::fstream *file);
		static void closeFile(std::fstream *file);
		static void insertTabs(unsigned int indentation, std::string *text);
		static std::string prepareLogText(unsigned int indentation, std::string sign, std::string message);
		static void insertLogHeader(std::fstream *file);
		static void insertLine(std::fstream *file, unsigned int length);
		static std::string getDate();
	};
}
