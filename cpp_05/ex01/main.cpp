#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <string>
#include <iostream>
#include <exception>

void	bureucratSignedForm(void) {
	std::cout << "----------Bureaucrat can sign the form--------------------" << std::endl;
	Bureaucrat	b("Maurilio", 5);
	Form		f("Driver's License Application", 6, 4);
	std::cout << std::endl;

	std::cout << b << std::endl;
	std::cout << f << std::endl;
	b.signForm(f);
	std::cout << f << std::endl;
	std::cout << std::endl;
}

void	bureucratDidntSignForm(void) {
	std::cout << "----------Bureaucrat can't sign the form--------------------" << std::endl;
	Bureaucrat	b("Rogerinho", 7);
	Form		f("Driver's License Application", 6, 4);
	std::cout << std::endl;

	std::cout << b << std::endl;
	std::cout << f << std::endl;
	b.signForm(f);
	std::cout << f << std::endl;
	std::cout << std::endl;
}

void	lowerFormTest(void) {
	std::cout << "----------Create a invalid form using grade lower than 150----------" << std::endl;
	try {
		Form	a("invalidForm", 1, 151);
		std::cout << a << std::endl;
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

}

void	higherFormTest(void) {
	std::cout << "----------Create a invalid form using grade higher than 1----------" << std::endl;
	try {
		Form	a("invalidForm", 0, 150);
		std::cout << a << std::endl;
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

}

int	main(void) {
	std::cout << std::endl;
	bureucratSignedForm();
	std::cout << std::endl << std::endl ;
	bureucratDidntSignForm();
	std::cout << std::endl << std::endl;
	lowerFormTest();
	std::cout << std::endl << std::endl;
	higherFormTest();
	std::cout << std::endl;
}
