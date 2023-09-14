#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "BRAIN default constructor called" << std::endl;
}

Brain::Brain(Brain const & src) {
	*this = src;
	std::cout << "BRAIN copy constructor called" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "BRAIN destructor called" << std::endl;
}

Brain&	Brain::operator=(Brain const & rhs) {
	if (this != &rhs) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	std::cout << "BRAIN assignment operator called" << std::endl;
	return *this;
}
