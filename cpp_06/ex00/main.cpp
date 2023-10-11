#include <iostream>
#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	try {
		if (argc != 2)
			throw "Invalid number of arguments";
		ScalarConverter::convert(argv[1]);
	} catch (char const *exceptionMessage) {
		std::cout << "Exception caught: "<< exceptionMessage << std::endl;
	}
}
