#ifndef MYSED_HPP
# define MYSED_HPP

#include <string>
#include <iostream>
#include <fstream>

class MySed
{
private:
	std::string	_fileName;
	std::string	_s1;
	std::string	_s2;
	std::string	_fileReplaceName;

public:
	MySed(std::string fileName, std::string s1, std::string s2);
	~MySed(void);

	int	replaceFile();
};

#endif
