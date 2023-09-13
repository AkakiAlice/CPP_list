#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
	std::cout << "WRONG_ANIMAL default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
	*this = src;
	std::cout << "WRONG_ANIMAL copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WRONG_ANIMAL destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const & rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return type;
}
