#include "Span.hpp"
#include <iostream>
#include <ctime>

void	outOfLimitTest(void) {
	std::cout << "---------------OUT OF LIMIT TEST---------------" << std::endl;
	Span	sp(5);
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(1);
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void	notEnoughElementsTest(void) {
	std::cout << "---------------NOT ENOUGH ELEMENTS TEST---------------" << std::endl;
	Span	sp(5);
	try {
		sp.addNumber(6);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

void	subjectTest(void) {
	std::cout << "---------------SUBJECT TEST---------------" << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Vector: ";
	for (size_t i = 0; i < 5; i++) {
		std::cout << "["<< sp.getElement(i) << "]"<< " ";
	} std::cout << std::endl;

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

}

void	addNumberRangeTest(int N) {
	std::cout << "---------------ADD NUMBER RANGE TEST---------------" << std::endl;

	Span sp = Span(N);
	std::vector<int> vector;

	for (int i = 1; i <= N; ++i) {
		vector.push_back(i * i);
	}

	sp.addNumberRange(vector.begin(), vector.end());

	std::cout << "Vector: ";
	for (size_t i = 0; i < vector.size(); i++) {
		std::cout << "["<< vector[i] << "]"<< " ";
	} std::cout << std::endl;

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

}

int	main(void) {
	outOfLimitTest();
	std::cout << std::endl;
	notEnoughElementsTest();
	std::cout << std::endl;
	subjectTest();
	std::cout << std::endl;
	addNumberRangeTest(100);
	std::cout << std::endl;
	addNumberRangeTest(10000);
	return 0;
}
