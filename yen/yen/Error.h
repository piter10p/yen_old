#pragma once
#include "Flag.h"
#include <string>
#include "Logger.h"

namespace yen
{
	class Error
	{
	public:
		Flag flag;

		std::string message;

		static Error generateUndefinedError()
		{
			Error e;
			e.flag = Flag::ERROR_UNDEFINED;
			e.message = "Undefined Error";
			return e;
		}
	};

	class FileManipulationError: public Error
	{
	public:
		std::string path;
		int fileNumber;
	};

	class ManipulatorError : public Error
	{
	public:
		int id;
		std::string type;
	};
}
