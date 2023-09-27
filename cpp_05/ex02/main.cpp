#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <string>
#include <iostream>
#include <exception>

void	PresidentialPardonFormTest(void) {
	std::cout << "############################################## PRESIDENTIAL PARDON FORM TEST ##############################################" << std::endl;
	std::cout << std::endl;
	Bureaucrat	Rogerinho("Rogerinho", 5);
	Bureaucrat	Renan("Renan", 20);
	Bureaucrat	Julinho("Julinho", 30);
	std::cout << std::endl;
	PresidentialPardonForm ppf("Maurilio");
	std::cout << std::endl;

	std::cout << "-------------------------Bureucrat can't sign the form-----------------------------" << std::endl;
	std::cout << Julinho << std::endl;
	std::cout << ppf << std::endl;
	Julinho.signForm(ppf);
	std::cout << std::endl;

	std::cout << "-------------------------------Form is not signed----------------------------------" << std::endl;
	std::cout << Renan << std::endl;
	std::cout << ppf << std::endl;
	Renan.executeForm(ppf);
	std::cout << std::endl;

	std::cout << "----------------Bureucrat can sign the form but can't execute it-------------------" << std::endl;
	std::cout << Renan << std::endl;
	std::cout << ppf << std::endl;
	Renan.signForm(ppf);
	Renan.executeForm(ppf);
	std::cout << std::endl;

	std::cout << "-------------------------Bureucrat can execute the form----------------------------" << std::endl;
	std::cout << Rogerinho << std::endl;
	std::cout << ppf << std::endl;
	Rogerinho.executeForm(ppf);
	std::cout << std::endl;
}

void	ShrubberyCreationFormTest(void) {
	std::cout << "######################################## SHRUBBERY CREATION FORM TEST #########################################" << std::endl;
	std::cout << std::endl;
	Bureaucrat	Rogerinho("Rogerinho", 137);
	Bureaucrat	Renan("Renan", 140);
	Bureaucrat	Julinho("Julinho", 150);
	std::cout << std::endl;
	ShrubberyCreationForm scf("Garden");
	std::cout << std::endl;

	std::cout << "-------------------------Bureucrat can't sign the form-----------------------------" << std::endl;
	std::cout << Julinho << std::endl;
	std::cout << scf << std::endl;
	Julinho.signForm(scf);
	std::cout << std::endl;

	std::cout << "-------------------------------Form is not signed----------------------------------" << std::endl;
	std::cout << Renan << std::endl;
	std::cout << scf << std::endl;
	Renan.executeForm(scf);
	std::cout << std::endl;

	std::cout << "----------------Bureucrat can sign the form but can't execute it-------------------" << std::endl;
	std::cout << Renan << std::endl;
	std::cout << scf << std::endl;
	Renan.signForm(scf);
	Renan.executeForm(scf);
	std::cout << std::endl;

	std::cout << "-------------------------Bureucrat can execute the form----------------------------" << std::endl;
	std::cout << Rogerinho << std::endl;
	std::cout << scf << std::endl;
	Rogerinho.executeForm(scf);
	std::cout << std::endl;
}

void	RobotomyRequestFormTest(void) {
	std::cout << "######################################## ROBOTOMY REQUEST FORM TEST #########################################" << std::endl;
	std::cout << std::endl;
	Bureaucrat	Rogerinho("Rogerinho", 40);
	Bureaucrat	Renan("Renan", 72);
	Bureaucrat	Julinho("Julinho", 73);
	std::cout << std::endl;
	RobotomyRequestForm rrf("Maurilio");
	std::cout << std::endl;

	std::cout << "-------------------------Bureucrat can't sign the form-----------------------------" << std::endl;
	std::cout << Julinho << std::endl;
	std::cout << rrf << std::endl;
	Julinho.signForm(rrf);
	std::cout << std::endl;

	std::cout << "-------------------------------Form is not signed----------------------------------" << std::endl;
	std::cout << Renan << std::endl;
	std::cout << rrf << std::endl;
	Renan.executeForm(rrf);
	std::cout << std::endl;

	std::cout << "----------------Bureucrat can sign the form but can't execute it-------------------" << std::endl;
	std::cout << Renan << std::endl;
	std::cout << rrf << std::endl;
	Renan.signForm(rrf);
	Renan.executeForm(rrf);
	std::cout << std::endl;

	std::cout << "-------------------------Bureucrat can execute the form----------------------------" << std::endl;
	std::cout << Rogerinho << std::endl;
	std::cout << rrf << std::endl;
	Rogerinho.executeForm(rrf);
	std::cout << std::endl;
}

int	main(void) {
	std::cout << std::endl;
	PresidentialPardonFormTest();
	std::cout << std::endl << std::endl;
	ShrubberyCreationFormTest();
	std::cout << std::endl << std::endl;
	RobotomyRequestFormTest();
	std::cout << std::endl;
}
