#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("nameless"), _grade(MIN_GRADE) {
	std::cout << "Bureaucrat " << _name << " created using default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) , _grade(grade) {
	if (_grade > MIN_GRADE)
		throw GradeTooLowException();
	if (_grade < MAX_GRADE)
		throw GradeTooHighException();
	std::cout << "Bureaucrat " << _name << " created using parametric constructor" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName()){
	*this = src;
	std::cout << "Bureaucrat " << _name << " created using copy constructor" << std::endl;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat " << _name << " has been destroyed" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const & rhs) {
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return *this;
}

char const *Bureaucrat::GradeTooLowException::what(void) const throw() {
	return ("Bureaucrat: Grade is too low");
}

char const *Bureaucrat::GradeTooHighException::what(void) const throw() {
	return ("Bureaucrat: Grade is too high");
}

void	Bureaucrat::incrementGrade(void) {
	int	tmpGrade = this->_grade - 1;
	if (tmpGrade < MAX_GRADE)
		throw GradeTooHighException();
	--this->_grade;
}

void	Bureaucrat::decrementGrade(void) {
	int	tmpGrade = this->_grade + 1;
	if (tmpGrade > MIN_GRADE)
		throw GradeTooLowException();
	++this->_grade;
}

int	Bureaucrat::getGrade(void) const {
	return _grade;
}

std::string	Bureaucrat::getName(void) const {
	return _name;
}

void	Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
		std::cout << this->_name << " couldn't execute " << form.getName() << std::endl;
	}
}

void	Bureaucrat::signForm(AForm & form) {
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	} catch (std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
		std::cout << this->_name << " couldn't sign " << form.getName() << " because its grade is too low" << std::endl;
	}
}

std::ostream&	operator<<(std::ostream &output, Bureaucrat const &rhs) {
	output << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return output;
}
