#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>

class RPN {
public:
	RPN(std::string inputExpression);
	RPN(void);
	RPN(RPN const & src);
	~RPN(void);

	RPN&	operator=(RPN const & rhs);

	double	calculate(void);

private:

	void	doOperation(char op);

	double	_num1;
	double	_num2;
	std::string	_expression;
	std::stack<double>	_rpnStack;

};

#endif
