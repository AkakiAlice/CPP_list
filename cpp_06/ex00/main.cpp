#include <iostream>
#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	(void)argc;
	try {
		if (argc != 2)
			throw "Invalid number of arguments";
		ScalarConverter::convert(argv[1]);
	} catch (char const *exceptionMessage) {
		std::cout << exceptionMessage << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
