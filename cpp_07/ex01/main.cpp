#include "iter.hpp"
#include <iostream>

int	main(void) {
	int intArray[] = {1,2,3,4,5,6,7,8,9};
	char charArray[] = {'a', 'b', 'c', 'd'};
	std::string strArray[] = {"Hello", "world!", " ¯\\_(ツ)_/¯"};

	::iter(intArray, 9, ::print);
	std::cout << std::endl;
	::iter(charArray, 4, ::print);
	std::cout << std::endl;
	::iter(strArray, 3, ::print);
}
