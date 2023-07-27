#include <dirent.h>
#include "MySed.hpp"

int	checkNumberArgs(int argc)
{
	if (argc != 4)
	{
		std::cout << "Error: Invalid number of arguments." << std::endl;
		return (0);
	}
	return (1);
}

int	isDir(char *fileName)
{
	DIR* dir = opendir(fileName);

	if (dir)
	{
		closedir(dir);
		std::cout << "Error: " << fileName << " is a directory." << std::endl;
		return (1);
	}
	return 0;
}

int	firstStringIsEmpty(char *s1)
{
	std::string str = s1;
	if (str.empty())
	{
		std::cout << "Error: s1 must not be empty." << std::endl;
		return (1);
	}
	return (0);
}

int	errorHandler(int argc, char *fileName, char *s1)
{
	if (checkNumberArgs(argc) && !isDir(fileName) && !firstStringIsEmpty(s1))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	if (errorHandler(argc, argv[1], argv[2]))
	{
		MySed mySed(argv[1], argv[2], argv[3]);
		return (mySed.replaceFile());
	}
	return (1);
}
