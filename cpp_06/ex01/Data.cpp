#include "Data.hpp"

Data::Data(void) : name("nameless"), age(0){
	std::cout << "Data default constructor called" << std::endl;
}

Data::Data(std::string name, int age) : name(name), age(age){
	std::cout << "Data parametric constructor called" << std::endl;
}

Data::Data(Data const & src) {
	*this = src;
	std::cout << "Data copy constructor called" << std::endl;
}

Data::~Data(void) {
	std::cout << "Data destructor called" << std::endl;
}

Data&	Data::operator=(Data const & rhs) {
	if (this != &rhs) {
		this->name = rhs.name;
		this->age = rhs.age;
	}
	return *this;
}

std::ostream&	operator<<(std::ostream &output, Data const &rhs) {
	output << rhs.name << ", " << rhs.age;
	return (output);
}
