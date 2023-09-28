#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
public:
	Intern(void);
	Intern(Intern const & src);
	~Intern(void);

	Intern&	operator=(Intern const & rhs);

	class InvalidFormException : public std::exception {
	public:
			virtual const char* what(void) const throw();
	};

	AForm*	makeForm(std::string const & formName, std::string const & formTarget);

private:
	AForm*	_makeShrubbery(std::string const & formTarget);
	AForm*	_makeRobotomy(std::string const & formTarget);
	AForm*	_makePresidential(std::string const & formTarget);
};

#endif
