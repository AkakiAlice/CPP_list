#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
public:
	Bureaucrat(void);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat(void);

	Bureaucrat&	operator=(Bureaucrat const & rhs);

private:
	// Member variables

};

#endif
