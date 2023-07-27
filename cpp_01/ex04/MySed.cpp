#include "MySed.hpp"

MySed::MySed(std::string fileName, std::string s1, std::string s2)
{
	this->_fileName = fileName;
	this->_s1 = s1;
	this->_s2 = s2;
	this->_fileReplaceName = fileName + ".replace";
	return ;
}

MySed::~MySed(void)
{
	return ;
}

void	replaceString(std::string& str, std::string str1, std::string str2)
{
	std::string::size_type pos = 0;

	while ((pos = str.find(str1, pos)) != std::string::npos)
	{
		str.erase(pos, str1.length());
		str.insert(pos, str2);
		pos += str2.length();
	}
}

int	MySed::replaceFile()
{
	std::ifstream	inputFile(this->_fileName.c_str());
	if (inputFile)
	{
		std::ofstream	outputFile(this->_fileReplaceName.c_str());
		std::string		line;

		while (std::getline(inputFile, line))
		{
			replaceString(line, this->_s1, this->_s2);
			outputFile << line << std::endl;
		}
		inputFile.close();
		outputFile.close();
		return (0);
	}
	std::cout << "Error: Unable to open the file " << this->_fileName << std::endl;
	return (1);
}
