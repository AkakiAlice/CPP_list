#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
	{
		std::cout << std::endl;
		std::cout << "---------------Testing Deep Copy-----------------" << std::endl;
		std::cout << std::endl;
		Dog	dog1;
		Dog	dog2(dog1);
		std::cout << std::endl;

		std::cout << "dog1 sound: ";
		dog1.makeSound();
		std::cout << "dog1 idea: " << dog1.getIdea(0) << std::endl;
		std::cout << "dog2 sound: ";
		dog2.makeSound();
		std::cout << "dog2 idea: " << dog2.getIdea(0) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << "---------------Creating Array Animals-----------------" << std::endl;
		std::cout << std::endl;
		Animal* animals[10];

		for (int i = 0; i < 10; i++) {
			i <= 4 ? animals[i] = new Dog() : animals[i] = new Cat();
			std::cout << std::endl;
		}

		std::cout << std::endl;
		std::cout << "---------------Checking Animals-----------------" << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			animals[i]->makeSound();

		std::cout << std::endl;
		std::cout << "---------------Deleting Animals-----------------" << std::endl;
		std::cout << std::endl;
		for (int i = 0; i < 10; i++) {
			delete animals[i];
			std::cout << std::endl;
		}
	}
	return 0;
}

