#include "Form.hpp"

Form::Form(void) : _is_signed(false), _sign_grade(MIN_GRADE), _exec_grade(MIN_GRADE), _name("default_form") {
	std::cout << "Form " << _name << " created using default constructor" << std::endl;
}

Form::Form(std::string name, int const sign_grade, int const exec_grade) :
	_is_signed(false),
	_sign_grade(sign_grade),
	_exec_grade(exec_grade),
	_name(name)
{
	checkGrade(this->_sign_grade);
	checkGrade(this->_exec_grade);
	std::cout << "Form " << _name << " created using parametric constructor" << std::endl;
}

Form::Form(Form const & src) :
	_is_signed(src.getSigned()),
	_sign_grade(src.getSignGrade()),
	_exec_grade(src.getExecGrade()),
	_name(src.getName())
{
	std::cout << "Form " << _name << " created using copy constructor" << std::endl;
}

Form::~Form(void) {
	std::cout << "Form " << _name << " has been destroyed" << std::endl;
}

Form&	Form::operator=(Form const & rhs) {
	if (this != &rhs) {
		this->_is_signed = rhs.getSigned();
		const_cast<int &>(this->_sign_grade) = rhs.getSignGrade();
		const_cast<int &>(this->_exec_grade) = rhs.getExecGrade();
		const_cast<std::string &>(this->_name) = rhs.getName();
	}
	return *this;
}

char const *Form::GradeTooLowException::what(void) const throw() {
	return ("Form: Grade is too low");
}

char const *Form::GradeTooHighException::what(void) const throw() {
	return ("Form: Grade is too high");
}

void	Form::checkGrade(int const grade) {
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
}

bool	Form::getSigned(void) const {
	return _is_signed;
}

int	Form::getSignGrade(void) const {
	return _sign_grade;
}

int	Form::getExecGrade(void) const {
	return _exec_grade;
}

std::string	Form::getName(void) const {
	return _name;
}

void	Form::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.getGrade() > this->_sign_grade)
		throw GradeTooLowException();
	this->_is_signed = true;
}

std::ostream&	operator<<(std::ostream &output, Form const &rhs) {
	output << "Form " << rhs.getName()
	<< " | " << (rhs.getSigned() ? "Is signed" : "Is not signed")
	<< " | Sign grade: " << rhs.getSignGrade()
	<< " | Exec grade: " << rhs.getExecGrade();
	return output;
}
