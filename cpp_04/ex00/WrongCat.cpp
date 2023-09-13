#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	type = "WrongCat";
	std::cout << "WRONG_CAT default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src) {
	*this = src;
	std::cout << "WRONG_CAT copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WRONG_CAT destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const & rhs) {
	if (this != &rhs)
		this->type = rhs.type;
	return *this;
}

void	WrongCat::makeSound(void) const {
	std::cout << "WrongCat sound" << std::endl;
}
