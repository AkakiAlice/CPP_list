#include <iostream>
#include "RPN.hpp"

void	checkExpression(std::string expression) {
	for (size_t i = 0; i < expression.length(); i++) {
		if (expression[i] != '+' && expression[i] != '-' &&
			expression[i] != '/' && expression[i] != '*' &&
			expression[i] != ' ' && !isdigit(expression[i]))
				throw std::invalid_argument("invalid expression");
	}
}

void	checkArg(int argc, char * argv) {
	if (argc != 2)
		throw std::invalid_argument("invalid number of arguments");
	checkExpression(argv);
}

int	main(int argc, char** argv) {
	try {
		checkArg(argc, argv[1]);
		RPN	rpn(argv[1]);
		std::cout << rpn.calculate() << std::endl;
	} catch(std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}
