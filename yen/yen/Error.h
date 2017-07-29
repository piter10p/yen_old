#pragma once
#include "Flag.h"
#include <string>

namespace yen
{
	class Error
	{
	public:
		Flag flag;

		static Error generateUndefinedError()
		{
			Error e;
			e.flag = Flag::ERROR_UNDEFINED;
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
