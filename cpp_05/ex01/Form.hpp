#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat;

class Form {
public:
	Form(void);
	Form(std::string const name, int const sign_grade, int const exec_grade);
	Form(Form const & src);
	~Form(void);

	Form&	operator=(Form const & rhs);

	class GradeTooLowException : public std::exception {
	public:
			virtual const char* what(void) const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
			virtual const char* what(void) const throw();
	};

	bool		getSigned(void) const;
	int			getSignGrade(void) const;
	int			getExecGrade(void) const;
	std::string	getName(void) const;
	void		beSigned(Bureaucrat & bureaucrat);

private:
	bool				_is_signed;
	int const			_sign_grade;
	int const			_exec_grade;
	std::string const	_name;

	void	checkGrade(int const grade);

};

std::ostream&	operator<<(std::ostream &output, Form const &rhs);

#endif
