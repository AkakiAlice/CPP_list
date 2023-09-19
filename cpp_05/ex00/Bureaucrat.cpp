#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
	*this = src;
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this != &rhs) {
		//assign
	}
	return *this;
}
