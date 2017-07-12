#pragma once
#include <string>
#include <boost\filesystem.hpp>
#include <vector>

namespace yen
{
	class FileSystem
	{
	public:
		static std::vector <std::string> getAllFilesPathsinDirectory(std::string directoryPath);
		static bool isFile(boost::filesystem::directory_iterator);
	};
}
