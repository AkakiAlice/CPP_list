#include <iostream>
#include <list>
#include "MutantStack.hpp"

void	memberFunctionsTest(void) {
	std::cout << "---------------MEMBER FUNCTIONS TEST---------------" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Stack size: " << mstack.size() << std::endl;

	std::cout << "Stack elements: ";
	while (!mstack.empty()) {
		int element = mstack.top();
		mstack.pop();
		std::cout << "["<< element << "]"<< " ";
	}
	std::cout << std::endl;

	std::cout << "Stack size: " << mstack.size() << std::endl;
}

void	iteratorsTest(void) {
	std::cout << "------------------ITERATORS TEST-------------------" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "Stack size: " << mstack.size() << std::endl;

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "Stack elements: ";
	while (it != ite)
		std::cout << "["<< *it++ << "]"<< " ";
	std::cout << std::endl;

	std::cout << "Stack size: " << mstack.size() << std::endl;
}

void	listTest(void) {
	std::cout << "--------------------LIST TEST----------------------" << std::endl;
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::cout << "List size: " << list.size() << std::endl;

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();

	std::cout << "List elements: ";
	while (it != ite)
		std::cout << "["<< *it++ << "]"<< " ";
	std::cout << std::endl;

	std::cout << "List size: " << list.size() << std::endl;
}

int main()
{
	memberFunctionsTest();
	iteratorsTest();
	listTest();
	return 0;
}
