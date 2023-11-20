#include <iostream>
#include "PmergeMe.hpp"
#include <stdlib.h>
#include <sstream>

bool	isBlankSpaceOnly(std::string str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!std::isspace(str[i]))
			return false;
	}
	return true;
}

void	checkInput(std::string sequence) {
	if (sequence.empty() || isBlankSpaceOnly(sequence))
		throw std::invalid_argument("invalid input");
	for (size_t i = 0; i < sequence.length(); i++) {
		if (sequence[i] != ' ' && !isdigit(sequence[i]))
				throw std::invalid_argument("invalid input");
	}
}

void	checkArg(int argc, char * argv) {
	if (argc != 2)
		throw std::invalid_argument("invalid number of arguments");
	checkInput(argv);
}

// int	jacobsthal(int n) {
// 	if (n == 0) return 0;
// 	if (n == 1) return 1;
// 	std::cout << "[" << n << "]" << '\n';
// 	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
// }

// void	jacobsthalNumbers() {
// 	int	n = 0;

// 	while (1) {
// 		int result = jacobsthal(n);
// 		if (result > 171)
// 			break;
// 		std::cout << result << " ";
// 		n++;
// 	}
// 	std::cout << '\n';
// }

void	parseInput(std::string input, std::vector<int> & numbers) {
	std::istringstream	iss(input);
	int	num;

	while (iss >> num) {
		numbers.push_back(num);
	}
}

int	main(int argc, char** argv) {
	try {
		std::vector<int> numbers;
		checkArg(argc, argv[1]);
		parseInput(argv[1], numbers);
		PmergeMe::sort(numbers);
	} catch(std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}
