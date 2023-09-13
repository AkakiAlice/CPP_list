#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
	{
		const Animal* animals[] = {new Animal(), new Dog(), new Cat()};
		const int arraySize = (int)(sizeof(animals)/sizeof(animals[0]));
		std::cout << std::endl;

		for (int i = 0; i < arraySize; ++i) {
			std::cout << "Type: " << animals[i]->getType() << std::endl;
			std::cout << "Sound: ";
			animals[i]->makeSound();
			delete animals[i];
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	{
		const WrongAnimal* wrong[] = {new WrongAnimal(), new WrongCat()};
		const int arraySize = (int)(sizeof(wrong)/sizeof(wrong[0]));
		std::cout << std::endl;

		for (int i = 0; i < arraySize; ++i) {
			std::cout << "Type: " << wrong[i]->getType() << std::endl;
			std::cout << "Sound: ";
			wrong[i]->makeSound();
			delete wrong[i];
			std::cout << std::endl;
		}
	}
	return 0;
}

