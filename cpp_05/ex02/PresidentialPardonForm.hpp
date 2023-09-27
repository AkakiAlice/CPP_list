#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#define SIGN_GRADE_PPF 25
#define EXEC_GRADE_PPF 5

class PresidentialPardonForm : public AForm {
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm const & src);
	PresidentialPardonForm(std::string const target);
	virtual ~PresidentialPardonForm(void);

	PresidentialPardonForm&	operator=(PresidentialPardonForm const & rhs);

	virtual void	execute(Bureaucrat const & executor) const;
};

#endif
