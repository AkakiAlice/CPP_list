#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat;

class AForm {
public:
	AForm(void);
	AForm(std::string const name, int const sign_grade, int const exec_grade);
	AForm(AForm const & src);
	virtual ~AForm(void);

	AForm&	operator=(AForm const & rhs);

	class GradeTooLowException : public std::exception {
	public:
			virtual const char* what(void) const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
			virtual const char* what(void) const throw();
	};

	class NotSignedException : public std::exception {
	public:
			virtual const char* what(void) const throw();
	};

	virtual void	execute(Bureaucrat const & executor) const = 0;

	bool		getSigned(void) const;
	int			getSignGrade(void) const;
	int			getExecGrade(void) const;
	std::string	getName(void) const;
	std::string	getTarget(void) const;
	void		beSigned(Bureaucrat & bureaucrat);

protected:
	void		setSigned(bool sign);
	void		setSignGrade(int grade);
	void		setExecGrade(int grade);
	void		setName(std::string name);
	void		setTarget(std::string target);
	void		checkExecPermission(Bureaucrat const & executor) const;

private:
	bool				_is_signed;
	int const			_sign_grade;
	int const			_exec_grade;
	std::string const	_name;
	std::string const	_target;

	void	checkGrade(int const grade);

};

std::ostream&	operator<<(std::ostream &output, AForm const &rhs);

#endif
