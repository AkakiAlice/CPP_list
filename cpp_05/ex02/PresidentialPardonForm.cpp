#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", SIGN_GRADE_PPF, EXEC_GRADE_PPF) {
	this->setTarget("undefined");
	std::cout << "PresidentialPardonForm created using default devired constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : AForm("PresidentialPardonForm", SIGN_GRADE_PPF, EXEC_GRADE_PPF) {
	this->setTarget(target);
	std::cout << "PresidentialPardonForm created using parametric devired constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src) {
	this->setTarget(src.getTarget());
	std::cout << "PresidentialPardonForm created using copy devired constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm has been destroyed in devired destructor" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs) {
	if (this != &rhs) {
		this->setSigned(rhs.getSigned());
		this->setSignGrade(rhs.getSignGrade());
		this->setExecGrade(rhs.getExecGrade());
		this->setName(rhs.getName());
		this->setTarget(rhs.getTarget());
	}
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	this->checkExecPermission(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
