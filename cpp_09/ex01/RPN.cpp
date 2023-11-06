#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(std::string inputExpression) : _expression(inputExpression) {}

RPN::RPN(RPN const & src) {
	*this = src;
}

RPN::~RPN(void) {}

RPN&	RPN::operator=(RPN const & rhs) {
	if (this != &rhs) {
		this->_num1 = rhs._num1;
		this->_num2 = rhs._num2;
		this->_expression = rhs._expression;
		this->_rpnStack = rhs._rpnStack;
	}
	return *this;
}

double	RPN::calculate(void) {
	int i = -1;
	while (_expression[++i]) {
		if (isdigit(_expression[i])) {
			_rpnStack.push(static_cast<double>(_expression[i] - '0'));
		}
		else if (_expression[i] != ' ')
			doOperation(_expression[i]);
	}
	if (_rpnStack.size() > 1)
		throw std::runtime_error("invalid operation");
	return _rpnStack.top();
}

void	RPN::doOperation(char op) {

	if (_rpnStack.size() < 2)
		throw std::runtime_error("invalid operation");
	_num2 = _rpnStack.top();
	_rpnStack.pop();
	_num1 = _rpnStack.top();
	_rpnStack.pop();

	if (op == '+')
		_rpnStack.push(_num1 + _num2);

	if (op == '-')
		_rpnStack.push(_num1 - _num2);

	if (op == '*')
		_rpnStack.push(_num1 * _num2);

	if (op == '/') {
		if (_num2 == 0)
			throw std::runtime_error("division by 0");
		_rpnStack.push(_num1 / _num2);
	}
}
