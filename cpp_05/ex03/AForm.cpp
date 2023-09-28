#include "AForm.hpp"

AForm::AForm(void) : _is_signed(false), _sign_grade(MIN_GRADE), _exec_grade(MIN_GRADE), _name("default_form") {
	std::cout << "Form " << _name << " created using default base constructor" << std::endl;
}

AForm::AForm(std::string name, int const sign_grade, int const exec_grade) :
	_is_signed(false),
	_sign_grade(sign_grade),
	_exec_grade(exec_grade),
	_name(name)
{
	checkGrade(this->_sign_grade);
	checkGrade(this->_exec_grade);
	std::cout << "Form " << _name << " created using parametric base constructor" << std::endl;
}

AForm::AForm(AForm const & src) :
	_is_signed(src.getSigned()),
	_sign_grade(src.getSignGrade()),
	_exec_grade(src.getExecGrade()),
	_name(src.getName())
{
	std::cout << "Form " << _name << " created using copy base constructor" << std::endl;
}

AForm::~AForm(void) {
	std::cout << "Form " << _name << " has been destroyed in base destructor" << std::endl;
}

AForm&	AForm::operator=(AForm const & rhs) {
	if (this != &rhs) {
		this->_is_signed = rhs.getSigned();
		const_cast<int &>(this->_sign_grade) = rhs.getSignGrade();
		const_cast<int &>(this->_exec_grade) = rhs.getExecGrade();
		const_cast<std::string &>(this->_name) = rhs.getName();
	}
	return *this;
}

char const *AForm::GradeTooLowException::what(void) const throw() {
	return ("Form: Grade is too low");
}

char const *AForm::GradeTooHighException::what(void) const throw() {
	return ("Form: Grade is too high");
}

char const *AForm::NotSignedException::what(void) const throw() {
	return ("Form: form is not signed");
}

void	AForm::checkGrade(int const grade) {
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
}

bool	AForm::getSigned(void) const {
	return _is_signed;
}

int	AForm::getSignGrade(void) const {
	return _sign_grade;
}

int	AForm::getExecGrade(void) const {
	return _exec_grade;
}

std::string	AForm::getName(void) const {
	return _name;
}

std::string	AForm::getTarget(void) const {
	return _target;
}

void	AForm::setSigned(bool sign) {
	this->_is_signed = sign;
}

void	AForm::setSignGrade(int grade) {
	const_cast<int &>(this->_sign_grade) = grade;
}

void	AForm::setExecGrade(int grade) {
	const_cast<int &>(this->_exec_grade) = grade;
}

void	AForm::setName(std::string name) {
	const_cast<std::string &>(this->_name) = name;
}

void	AForm::setTarget(std::string target) {
	const_cast<std::string &>(this->_target) = target;
}

void	AForm::checkExecPermission(Bureaucrat const & executor) const {
	if (this->getSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
}

void	AForm::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw GradeTooLowException();
	this->_is_signed = true;
}

std::ostream&	operator<<(std::ostream &output, AForm const &rhs) {
	output << "Form " << rhs.getName()
	<< " | " << (rhs.getSigned() ? "Signed" : "Not signed")
	<< " | Sign grade: " << rhs.getSignGrade()
	<< " | Exec grade: " << rhs.getExecGrade();
	return output;
}
