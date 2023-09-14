#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("default") {
	std::cout << "AANIMAL default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src) {
	*this = src;
	std::cout << "AANIMAL copy constructor called" << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "AANIMAL destructor called" << std::endl;
}

AAnimal&	AAnimal::operator=(AAnimal const & rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

std::string	AAnimal::getType(void) const{
	return type;
}
