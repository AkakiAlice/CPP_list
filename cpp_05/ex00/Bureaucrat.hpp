#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat {
public:
	Bureaucrat(void);
	Bureaucrat(std::string const name, int grade);
	Bureaucrat(Bureaucrat const & src);
	~Bureaucrat(void);

	Bureaucrat&	operator=(Bureaucrat const & rhs);

	class GradeTooLowException : public std::exception {
	public:
			const char *what(void) const throw();
	};

	class GradeTooHighException : public std::exception {
	public:
			const char *what(void) const throw();
	};

	void		incrementGrade(void);
	void		decrementGrade(void);
	int			getGrade(void) const;
	std::string	getName(void) const;

private:
	std::string const	_name;
	int					_grade;

};

	std::ostream&	operator<<(std::ostream &output, Bureaucrat const &rhs);

#endif