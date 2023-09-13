#include "Animal.hpp"

Animal::Animal(void) : type("default") {
	std::cout << "ANIMAL default constructor called" << std::endl;
}

Animal::Animal(Animal const & src) {
	*this = src;
	std::cout << "ANIMAL copy constructor called" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "ANIMAL destructor called" << std::endl;
}

Animal&	Animal::operator=(Animal const & rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void	Animal::makeSound(void) const {
	std::cout << "Default animal sound" << std::endl;
}

std::string	Animal::getType(void) const{
	return type;
}
