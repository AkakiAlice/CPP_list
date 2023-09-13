#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	type = "Dog";
	std::cout << "DOG default constructor called" << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src) {
	*this = src;
	std::cout << "DOG copy constructor called" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "DOG destructor called" << std::endl;
}

Dog&	Dog::operator=(Dog const & rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "Woof!" << std::endl;
}
