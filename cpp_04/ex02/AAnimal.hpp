#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal {
public:
	AAnimal(void);
	AAnimal(AAnimal const & src);
	virtual ~AAnimal(void);

	AAnimal&	operator=(AAnimal const & rhs);

	virtual void	makeSound(void) const = 0;
	std::string		getType(void) const;

protected:
	std::string	type;
};

#endif
