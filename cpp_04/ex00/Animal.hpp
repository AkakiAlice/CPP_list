#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
public:
	Animal(void);
	Animal(Animal const & src);
	virtual ~Animal(void);

	Animal&	operator=(Animal const & rhs);

	virtual void	makeSound(void) const;
	std::string		getType(void) const;

protected:
	std::string	type;
};

#endif
