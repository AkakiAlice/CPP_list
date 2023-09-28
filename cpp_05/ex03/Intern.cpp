#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const & src) {
	*this = src;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(void) {
	std::cout << "Intern destructor called" << std::endl;
}

Intern&	Intern::operator=(Intern const & rhs) {
	(void)rhs;
	return *this;
}

char const *Intern::InvalidFormException::what(void) const throw() {
	return ("Form doesn't exist");
}

AForm*	Intern::_makeShrubbery(std::string const & formTarget) {
	return (new ShrubberyCreationForm(formTarget));
}

AForm*	Intern::_makeRobotomy(std::string const & formTarget) {
	return (new RobotomyRequestForm(formTarget));
}

AForm*	Intern::_makePresidential(std::string const & formTarget) {
	return (new PresidentialPardonForm(formTarget));
}

AForm*	Intern::makeForm(std::string const & formName, std::string const & formTarget) {
	std::string	formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*functionPtr[3])(std::string const &) = { &Intern::_makeShrubbery, &Intern::_makeRobotomy, &Intern::_makePresidential};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << " form" <<  std::endl;
			return (this->*functionPtr[i])(formTarget);
		}
	}
	throw InvalidFormException();
}
