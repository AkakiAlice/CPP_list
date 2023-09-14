#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	Cat(void);
	Cat(Cat const & src);
	virtual ~Cat(void);

	Cat&	operator=(Cat const & rhs);

	virtual void	makeSound(void) const;
	std::string		getIdea(int index) const;
	Brain*			getBrain() const ;

private:
	Brain* _brain;
};

#endif
