#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <string>
#include <iostream>
#include <exception>

void	CreateForms (std:: string const & formName, std:: string const & formTarget) {
	Intern someRandomIntern;
	Bureaucrat bureaucrat("Rogerinho", 5);
	AForm *form;
	std::cout << std::endl;

	try {
		form = someRandomIntern.makeForm(formName, formTarget);
		std::cout << std::endl;
		std::cout << bureaucrat << std::endl;
		std::cout << *form << std::endl;
		std::cout << std::endl;
		bureaucrat.signForm(*form);
		std::cout << std::endl;
		bureaucrat.executeForm(*form);
		std::cout << std::endl;
		delete form;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

void	InternCreateShrubberyFormTest (void) {
	std::cout << "######################################## INTERN CREATES SHRUBBERY FORM TEST #########################################" << std::endl;
	CreateForms("shrubbery creation", "forest");
}

void	InternCreateRobotomyFormTest (void) {
	std::cout << "######################################## INTERN CREATES ROBOTOMY FORM TEST #########################################" << std::endl;
	CreateForms("robotomy request", "Renan");
}

void	InternCreatePresidentialFormTest (void) {
	std::cout << "######################################## INTERN CREATES PRESIDENTIAL FORM TEST #########################################" << std::endl;
	CreateForms("presidential pardon", "Julinho");
}

void	InternCreateInvalidFormTest (void) {
	std::cout << "######################################## INTERN CREATES INVALID FORM TEST #########################################" << std::endl;
	CreateForms("it's not gonna work", ":(");
}

int	main(void) {
	std::cout << std::endl;
	InternCreateShrubberyFormTest();
	std::cout << std::endl << std::endl;
	InternCreateRobotomyFormTest();
	std::cout << std::endl << std::endl;
	InternCreatePresidentialFormTest();
	std::cout << std::endl << std::endl;
	InternCreateInvalidFormTest();
	std::cout << std::endl;
}
