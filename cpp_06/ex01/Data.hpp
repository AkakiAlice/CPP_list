#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data {
public:
	Data(void);
	Data(std::string name, int age);
	Data(Data const & src);
	~Data(void);

	Data&	operator=(Data const & rhs);

	std::string	name;
	int			age;
};

std::ostream&	operator<<(std::ostream &output, Data const &rhs);

#endif
