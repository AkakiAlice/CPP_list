#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
	{
		const AAnimal* dog = new Dog();
		const AAnimal* cat = new Cat();
		//const AAnimal* animal = new AAnimal();
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
		std::cout << std::endl;
	}
	return 0;
}
