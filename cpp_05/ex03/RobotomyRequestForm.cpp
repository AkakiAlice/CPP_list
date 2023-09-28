#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("PresidentialPardonForm", SIGN_GRADE_RRF, EXEC_GRADE_RRF) {
	this->setTarget("undefined");
	std::cout << "RobotomyRequestForm created using default devired constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : AForm("RobotomyRequestForm", SIGN_GRADE_RRF, EXEC_GRADE_RRF) {
	this->setTarget(target);
	std::cout << "RobotomyRequestForm created using parametric devired constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src) {
	this->setTarget(src.getTarget());
	std::cout << "RobotomyRequestForm created using copy devired constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm has been destroyed in devired destructor" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs) {
	if (this != &rhs) {
		this->setSigned(rhs.getSigned());
		this->setSignGrade(rhs.getSignGrade());
		this->setExecGrade(rhs.getExecGrade());
		this->setName(rhs.getName());
		this->setTarget(rhs.getTarget());
	}
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	this->checkExecPermission(executor);
	std::cout << "**SOME DRILLING NOISES**" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}
