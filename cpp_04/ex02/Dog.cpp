#include "Dog.hpp"

Dog::Dog(void) : AAnimal() {
	type = "Dog";
	std::cout << "DOG default constructor called" << std::endl;
	_brain = new Brain();
	for (int i = 0; i < 100; i++) {
		_brain->ideas[i] = "Woof";
	}
}

Dog::Dog(Dog const & src) : AAnimal(src) {
	std::cout << "DOG copy constructor called" << std::endl;
	_brain = new Brain();
	*this = src;
}

Dog::~Dog(void) {
	delete _brain;
	std::cout << "DOG destructor called" << std::endl;
}

Dog&	Dog::operator=(Dog const & rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
		*this->_brain = *rhs.getBrain();
	}
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "Woof!" << std::endl;
}

std::string	Dog::getIdea(int index) const {
	return _brain->ideas[index];
}

Brain*	Dog::getBrain(void) const {
	return _brain;
}
