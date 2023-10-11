#include "ScalarConverter.hpp"

	std::string	ScalarConverter::_inputValue = "";
	char		ScalarConverter::_charValue = 0;
	int			ScalarConverter::_intValue = 0;
	float		ScalarConverter::_floatValue = 0;
	double		ScalarConverter::_doubleValue = 0;
	double		ScalarConverter::_rangeCheck = 0;

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	*this = src;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter&	ScalarConverter::operator=(ScalarConverter const & rhs) {
	(void)rhs;
	return *this;
}

void	ScalarConverter::convert(std::string const & literal) {
	_inputValue = literal;
	_rangeCheck = strtod(literal.c_str(), NULL);
	if (_isChar())
		_convertChar(literal);
	else if (_isInt())
		_convertInt(literal);
	else if (_isFloat())
		_convertFloat(literal);
	else if (_isDouble())
		_convertDouble(literal);
	else
		throw "Invalid input";

	_printTypes();
}

bool	ScalarConverter::_isChar(void) {
	if (_inputValue.length() == 1 && !isdigit(_inputValue[0]))
		return true;
	return false;
}

bool	ScalarConverter::_isInt(void) {
	for (size_t i = 0; i < _inputValue.length(); i++) {
		if (i == 0 && (_inputValue[i] == '-' || _inputValue[i] == '+'))
			continue;
		else if (!std::isdigit(_inputValue[i]))
			return false;
	}
	if (atol(_inputValue.c_str()) > MAX_INT || atol(_inputValue.c_str()) < MIN_INT)
		return false;
	return true;
}

bool	ScalarConverter::_isFloat(void) {
	size_t	findF = _inputValue.find("f");
	size_t	findDecimalPoint = _inputValue.find(".");
	size_t	len = _inputValue.length();

	if (findF == std::string::npos || findF != (len - 1))
		return false;
	if (findDecimalPoint == std::string::npos || findDecimalPoint == 0 || findDecimalPoint == (len - 2))
		return false;
	if (_countDecimalPoint() != 1)
		return false;
	if (!_isDecimalNumberFloat())
		return false;
	return true;
}

bool	ScalarConverter::_isDouble(void) {
	size_t	findDecimalPoint = _inputValue.find(".");
	size_t	len = _inputValue.length();

	if (findDecimalPoint == std::string::npos || findDecimalPoint == 0 || findDecimalPoint == (len - 1))
		return false;
	if (_countDecimalPoint() != 1)
		return false;
	if (!_isDecimalNumberDouble())
		return false;
	return true;
}

void	ScalarConverter::_convertChar(std::string const & literal) {
	_charValue = literal[0];
	_intValue = static_cast<int>(_charValue);
	_floatValue = static_cast<float>(_charValue);
	_doubleValue = static_cast<double>(_charValue);
}

void	ScalarConverter::_convertInt(std::string const & literal) {
	_intValue = atoi(literal.c_str());
	_charValue = static_cast<char>(_intValue);
	_floatValue = static_cast<float>(_intValue);
	_doubleValue = static_cast<double>(_intValue);
}

void	ScalarConverter::_convertFloat(std::string const & literal) {
	_floatValue = atof(literal.c_str());
	_intValue = static_cast<int>(_floatValue);
	_charValue = static_cast<char>(_floatValue);
	_doubleValue = static_cast<double>(_floatValue);
}

void	ScalarConverter::_convertDouble(std::string const & literal) {
	_doubleValue = strtod(literal.c_str(), NULL);
	_intValue = static_cast<int>(_doubleValue);
	_charValue = static_cast<char>(_doubleValue);
	_floatValue = static_cast<float>(_doubleValue);
}

void	ScalarConverter::_printTypes(void) {
	std::cout << "char: " << _charValue << std::endl;
	_printInt();
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << _floatValue << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "double: " << _doubleValue << std::endl;
}

void	ScalarConverter::_printInt(void) {
	if (_rangeCheck > MAX_INT || _rangeCheck < MIN_INT)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << _intValue << std::endl;
}


int	ScalarConverter::_countDecimalPoint(void) {
	int		countDecimalPoint = 0;
	size_t	len = _inputValue.length();

	for (size_t i = 0; i < len; ++i) {
		if (_inputValue[i] == '.')
			countDecimalPoint++;
	}
	return (countDecimalPoint);
}

bool	ScalarConverter::_isDecimalNumberFloat(void) {
	char	c;
	size_t	len = _inputValue.length();

	for (size_t i = 0; i < len; ++i) {
		c = _inputValue[i];
		if (i == 0 && (c == '-' || c == '+'))
			continue;
		else if (!isdigit(c) && (c != '.' && c != 'f'))
			return false;
	}
	return true;
}

bool	ScalarConverter::_isDecimalNumberDouble(void) {
	char	c;
	size_t	len = _inputValue.length();

	for (size_t i = 0; i < len; ++i) {
		c = _inputValue[i];
		if (i == 0 && (c == '-' || c == '+'))
			continue;
		else if (!isdigit(c) && (c != '.'))
			return false;
	}
	return true;
}

