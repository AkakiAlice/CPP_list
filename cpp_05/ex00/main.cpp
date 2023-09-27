#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

void	validBureaucratTest(void) {
	try {
		std::cout << "-----Instantiate Bureaucrat using valid grade 150-------" << std::endl;
		Bureaucrat	a("Renan", 150);
		std::cout << a << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void	higherThanMaxTest(void) {
	try {
		std::cout << "-----Instantiate Bureaucrat using invalid grade 0-------" << std::endl;
		Bureaucrat	a("Maurilio", 0);
		std::cout << a << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void	lowerThanMinTest(void) {
	try {
		std::cout << "-----Instantiate Bureaucrat using invalid grade 151-----" << std::endl;
		Bureaucrat	a("Rogerinho", 151);
		std::cout << a << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void	incrementTest(void) {
	std::cout << "-----Incrementing a grade 3 should give a grade 2 to the Bureaucrat-----" << std::endl;
	Bureaucrat	a("Julinho", 3);

	std::cout << "Before: " << a << std::endl;
	a.incrementGrade();
	std::cout << "After: " << a << std::endl;
}

void	incrementLoopTest(void) {
	try {
		std::cout << "-----Increment the Bureaucrat's grade until it is out of range----------" << std::endl;
		Bureaucrat	a("Maurilio", 5);

		std::cout << a << std::endl;
		for (int i = 0; i < 10; i++) {
			a.incrementGrade();
			std::cout << a << std::endl;
		}

	} catch (std::exception & e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void	decrementLoopTest(void) {
	try {
		std::cout << "-----Decrement the Bureaucrat's grade until it is out of range----------" << std::endl;
		Bureaucrat	a("Rogerinho", 145);

		std::cout << a << std::endl;
		for (int i = 0; i < 10; i++) {
			a.decrementGrade();
			std::cout << a << std::endl;
		}

	} catch (std::exception & e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

int	main(void) {
	std::cout << std::endl;
	validBureaucratTest();
	std::cout << std::endl;
	higherThanMaxTest();
	std::cout << std::endl;
	lowerThanMinTest();
	std::cout << std::endl;
	incrementTest();
	std::cout << std::endl;
	incrementLoopTest();
	std::cout << std::endl;
	decrementLoopTest();
	std::cout << std::endl;
}
