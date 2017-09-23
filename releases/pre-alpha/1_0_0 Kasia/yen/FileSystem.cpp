#include "stdafx.h"
#include "FileSystem.h"
#include "Error.h"

using namespace yen;

std::vector <std::string> FileSystem::getAllFilesPathsinDirectory(std::string directoryPath)
{
	std::vector <std::string> fileList;

	if (!directoryPath.empty())
	{
		boost::filesystem::directory_iterator end_itr;

		try
		{
			boost::filesystem::path path(directoryPath);

			for (boost::filesystem::directory_iterator itr(path); itr != end_itr; ++itr)
			{
				if (isFile(itr)) {
					fileList.push_back(itr->path().string());
				}
			}
		}
		catch(...)
		{
			FileManipulationError e;
			e.flag = Flag::ERROR_BAD_PATH;
			e.path = directoryPath;
			throw e;
		}
		
	}

	return fileList;
}

bool FileSystem::isFile(boost::filesystem::directory_iterator itr)
{
	if (is_regular_file(itr->path()))
		return true;
	return false;
}