#include "Cat.hpp"

Cat::Cat(void) : AAnimal() {
	type = "Cat";
	std::cout << "CAT default constructor called" << std::endl;
	_brain = new Brain();
	for (int i = 0; i < 100; i++) {
		_brain->ideas[i] = "Meow";
	}
}

Cat::Cat(Cat const & src) : AAnimal(src) {
	std::cout << "CAT copy constructor called" << std::endl;
	_brain = new Brain();
	*this = src;
}

Cat::~Cat(void) {
	delete _brain;
	std::cout << "CAT destructor called" << std::endl;
}

Cat&	Cat::operator=(Cat const & rhs) {
	if (this != &rhs) {
		this->type = rhs.type;
		*this->_brain = *rhs.getBrain();
	}
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "Meoow!" << std::endl;
}

std::string	Cat::getIdea(int index) const {
	return _brain->ideas[index];
}

Brain*	Cat::getBrain(void) const {
	return _brain;
}
