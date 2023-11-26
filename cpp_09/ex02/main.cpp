#include <iostream>
#include "PmergeMe.hpp"
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <deque>
#include <vector>
#include <climits>

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

template <typename Container>
bool	hasDuplicates(const Container& container) {
	typedef typename Container::const_iterator Iterator;

	for (Iterator it = container.begin(); it != container.end(); ++it) {
		Iterator duplicateIt = std::find(it + 1, container.end(), *it);
		if (duplicateIt != container.end()) {
			return true;
		}
	}
	return false;
}

void	parseInput(std::string input, std::vector<int> & numbers) {
	std::istringstream	iss(input);
	double	num;

	while (iss >> num) {
		if (num > INT_MAX)
			throw std::invalid_argument("too large number");
		numbers.push_back(num);
	}
	if (hasDuplicates(numbers))
		throw std::invalid_argument("duplicate numbers");
}

void	parseInput(std::string input, std::deque<int> & numbers) {
	std::istringstream	iss(input);
	double	num;

	while (iss >> num) {
		if (num > INT_MAX)
			throw std::invalid_argument("too large number");
		numbers.push_back(num);
	}
	if (hasDuplicates(numbers))
		throw std::invalid_argument("duplicate numbers");
}

template <typename Iterator>
void printRange(Iterator first, Iterator last) {
	for (Iterator it = first; it != last; it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename Iterator>
bool is_sorted(Iterator first, Iterator last)
{
	if (first == last)
		return true;

	Iterator next = first;
	while (++next != last)
	{
		if (*next < *first)
			return false;
		++first;
	}
	return true;
}

void	sortVector(char* input) {
	clock_t	start, end;
	double	time;
	std::vector<int> numbers;

	std::cout << "Before: ";
	std::cout << input << std::endl;

	start = clock();
	parseInput(input, numbers);
	PmergeMe::sort(numbers);
	end = clock();

	if (!is_sorted(numbers.begin(), numbers.end()))
		throw std::runtime_error("Failed to sort");

	std::cout << "After:  ";
	printRange(numbers.begin(), numbers.end());
	time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of ";
	std::cout << numbers.size();
	std::cout << " elements with std::vector : ";
	std::cout << time << " ms" << std::endl;
}

void	sortDeque(char* input) {
	clock_t	start, end;
	double	time;
	std::deque<int> numbers;

	start = clock();
	parseInput(input, numbers);
	PmergeMe::sort(numbers);
	end = clock();

	if (!is_sorted(numbers.begin(), numbers.end()))
		throw std::runtime_error("Failed to sort");

	time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time to process a range of ";
	std::cout << numbers.size();
	std::cout << " elements with std::deque : ";
	std::cout << time << " ms" << std::endl;
}

int	main(int argc, char** argv) {
	try {
		checkArg(argc, argv[1]);
		sortVector(argv[1]);
		sortDeque(argv[1]);
	} catch(std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}
