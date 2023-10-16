#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

void	intVectorTest(void) {
	std::cout << "-----------------INT VECTOR TEST------------------" << std::endl;

	std::vector<int> vector;
	std::vector<int>::iterator iterator;

	for (int i = 0; i < 10; i++)
		vector.push_back(i+33);

	std::cout << "Int vector: ";
	for (size_t i = 0; i < vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;

	std::cout << "Trying to find value 36" << std::endl;
	iterator = easyfind(vector, 36);
	std::cout << "Value " << *iterator;
	std::cout << " found at position " << std::distance(vector.begin(), iterator);
	std::cout << std::endl;
}

void	intListTest(void) {
	std::cout << "------------------INT LIST TEST-------------------" << std::endl;

	std::list<int> list;
	std::list<int>::iterator iterator;

	for (int i = 0; i < 10; i++)
		list.push_back(i+103);

	iterator = list.begin();
	std::cout << "Int list: ";
	while (iterator != list.end())
		std::cout << *iterator++ << " ";
	std::cout << std::endl;

	std::cout << "Trying to find value 107" << std::endl;
	iterator = easyfind(list, 107);
	std::cout << "Value " << *iterator;
	std::cout << " found at position " << std::distance(list.begin(), iterator);
	std::cout << std::endl;
}


void	valeuNotFoundTest(void) {
	std::cout << "---------------VALUE NOT FOUND TEST---------------" << std::endl;

	std::vector<int> vector;
	std::vector<int>::iterator iterator;

	try {
		for (int i = 0; i < 10; i++)
			vector.push_back(i+15);

		std::cout << "Int vector: ";
		for (size_t i = 0; i < vector.size(); i++)
			std::cout << vector[i] << " ";
		std::cout << std::endl;

		std::cout << "Trying to find value 25" << std::endl;
		iterator = easyfind(vector, 25);
		std::cout << "Value " << *iterator;
		std::cout << " found at position " << std::distance(vector.begin(), iterator);
		std::cout << std::endl;
	} catch(std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}

int	main(void) {
	intVectorTest();
	std::cout << std::endl;
	intListTest();
	std::cout << std::endl;
	valeuNotFoundTest();
}
