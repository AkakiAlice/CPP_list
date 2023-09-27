#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>

#define SIGN_GRADE_RRF 72
#define EXEC_GRADE_RRF 45

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm const & src);
	RobotomyRequestForm(std::string const target);
	virtual ~RobotomyRequestForm(void);

	RobotomyRequestForm&	operator=(RobotomyRequestForm const & rhs);

	virtual void	execute(Bureaucrat const & executor) const;
};

#endif
