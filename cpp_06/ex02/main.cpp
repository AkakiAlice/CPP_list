#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>

Base * generate(void) {
	int	randomNumber;

	srand(time(NULL));
	randomNumber = rand() % 3;
	if (randomNumber == 0) {
		std::cout << "Generating A" << std::endl;
		return new A;
	} if (randomNumber == 1) {
		std::cout << "Generating B" << std::endl;
		return new B;
	} if (randomNumber == 2) {
		std::cout << "Generating C" << std::endl;
		return new C;
	}
	return NULL;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "Object type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Object type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Object type: C" << std::endl;
}

void identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << "Object type: A" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception caught: A: " << e.what() << std::endl;
	}
	try {
		dynamic_cast<B&>(p);
		std::cout << "Object type: B" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception caught: B: " << e.what() << std::endl;
	}
	try {
		dynamic_cast<C&>(p);
		std::cout << "Object type: C" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Exception caught: C: " << e.what() << std::endl;
	}
}

int	main(void) {
	Base *base;

	base = generate();
	std::cout << std::endl;
	identify(base);
	std::cout << std::endl;
	identify(*base);

	delete base;
}
