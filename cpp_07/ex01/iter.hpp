#include <iostream>

template<typename T>
void iter(T const *array, int const arrayLength, void (*funcPtr)(T const & x)) {
	for (int i = 0; i < arrayLength; i++)
		funcPtr(array[i]);
}

template<typename T>
void print(T const & x) {
	std::cout << x << std::endl;
}
