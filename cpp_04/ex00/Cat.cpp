#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	type = "Cat";
	std::cout << "CAT default constructor called" << std::endl;
}

Cat::Cat(Cat const & src) : Animal(src) {
	*this = src;
	std::cout << "CAT copy constructor called" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "CAT destructor called" << std::endl;
}

Cat&	Cat::operator=(Cat const & rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "Meoow!" << std::endl;
}
