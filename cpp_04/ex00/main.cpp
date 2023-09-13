#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
	{
		const Animal* animal = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		std::cout << std::endl;

		std::cout << "Type: " << animal->getType() << std::endl;
		std::cout << "Sound: ";
		animal->makeSound();
		std::cout << std::endl;

		std::cout << "Type: " << dog->getType() << std::endl;
		std::cout << "Sound: ";
		dog->makeSound();
		std::cout << std::endl;

		std::cout << "Type: " << cat->getType() << std::endl;
		std::cout << "Sound: ";
		cat->makeSound();
		std::cout << std::endl;

		delete cat;
		delete dog;
		delete animal;
		std::cout << std::endl;
	}
	{
		const WrongAnimal* wrongAnimal = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();
		std::cout << std::endl;

		std::cout << "Type: " << wrongAnimal->getType() << std::endl;
		std::cout << "Sound: ";
		wrongAnimal->makeSound();
		std::cout << std::endl;

		std::cout << "Type: " << wrongCat->getType() << std::endl;
		std::cout << "Sound: ";
		wrongCat->makeSound();
		std::cout << std::endl;

		delete wrongAnimal;
		delete wrongCat;
	}
	return 0;
}
