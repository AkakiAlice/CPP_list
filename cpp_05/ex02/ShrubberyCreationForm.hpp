#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

#define SIGN_GRADE_SCF 145
#define EXEC_GRADE_SCF 137

#define ASCII_TREE \
 "\
        *\n\
        ^\n\
       ^^^\n\
      ^^^^^\n\
     ^^^^^^^\n\
    ^^^^^^^^^\n\
        |\n\
"

class ShrubberyCreationForm : public AForm {
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm const & src);
	ShrubberyCreationForm(std::string const target);
	virtual ~ShrubberyCreationForm(void);

	ShrubberyCreationForm&	operator=(ShrubberyCreationForm const & rhs);

	virtual void	execute(Bureaucrat const & executor) const;
};

#endif
