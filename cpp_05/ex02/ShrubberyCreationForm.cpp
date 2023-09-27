#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", SIGN_GRADE_SCF, EXEC_GRADE_SCF) {
	this->setTarget("undefined");
	std::cout << "ShrubberyCreationForm created using default devired constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target) : AForm("ShrubberyCreationForm", SIGN_GRADE_SCF, EXEC_GRADE_SCF) {
	this->setTarget(target);
	std::cout << "ShrubberyCreationForm created using parametric devired constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) : AForm(src) {
	this->setTarget(src.getTarget());
	std::cout << "ShrubberyCreationForm created using copy devired constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm has been destroyed in devired destructor" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs) {
	if (this != &rhs) {
		this->setSigned(rhs.getSigned());
		this->setSignGrade(rhs.getSignGrade());
		this->setExecGrade(rhs.getExecGrade());
		this->setName(rhs.getName());
		this->setTarget(rhs.getTarget());
	}
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	this->checkExecPermission(executor);
	std::ofstream	out;
	std::string		fileName;

	fileName = this->getTarget() + "_shrubbery";
	out.exceptions(std::ofstream::failbit | std::ofstream::badbit);
	out.open(fileName.c_str(), std::ofstream::out | std::ofstream::trunc);
	out << ASCII_TREE;
	out.close();
}
