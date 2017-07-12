#include "stdafx.h"
#include "FileSystem.h"

using namespace yen;

std::vector <std::string> FileSystem::getAllFilesPathsinDirectory(std::string directoryPath)
{
	std::vector <std::string> fileList;

	if (!directoryPath.empty())
	{
		boost::filesystem::directory_iterator end_itr;

		boost::filesystem::path path(directoryPath);

		for (boost::filesystem::directory_iterator itr(path); itr != end_itr; ++itr)
		{
			if (isFile(itr)) {
				fileList.push_back(itr->path().string());
			}
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