#include <iostream>
#include "Array.hpp"

template<typename T>
void printArray(Array<T> &array, int const arrayLength) {
	for (int i = 0; i < arrayLength; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}

void	intArrayTest(void) {
	std::cout << "-------------------INT ARRAY TEST---------------------" << std::endl;
	Array<int> numbers(10);

	for (int i = 0; i < 10; i++)
		numbers[i] = i;

	std::cout << "Int array: ";
	printArray(numbers, 10);
}

void	stringArrayTest(void) {
	std::cout << "-----------------STRING ARRAY TEST--------------------" << std::endl;
	Array<std::string> strings(3);
	strings[0] = "Hello";
	strings[1] = "world!";
	strings[2] = "¯\\_(ツ)_/¯";
	std::cout << "String array: ";
	printArray(strings, 3);
}

void	copyConstructorTest(void) {
	std::cout << "----------------COPY CONSTRUCTOR TEST-----------------" << std::endl;
	Array<char> original(3);
	Array<char> copy1;

	for (int i = 0; i < 3; i++) {
		original[i] = i + 'a';
	}
	copy1 = original;
	Array<char> copy2(original);
	std::cout << std::endl;

	std::cout << "Original array: ";
	printArray(original, 3);

	std::cout << "Copy array (using '=' operator): ";
	printArray(copy1, 3);

	std::cout << "Copy array (using copy constructor): ";
	printArray(copy2, 3);
	std::cout << std::endl;
}

void	indexOutOfRange(void) {
	std::cout << "--------------INDEX OUT OF RANGE TEST-----------------" << std::endl;
	Array<int> numbers(3);
	std::cout << std::endl;
	try {
		for (int i = 0; i < 4; i++)
			numbers[i] = i;
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main(void) {
	std::cout << std::endl;
	intArrayTest();
	std::cout << std::endl;
	stringArrayTest();
	std::cout << std::endl;
	copyConstructorTest();
	std::cout << std::endl;
	indexOutOfRange();
	std::cout << std::endl;
	return 0;
}
