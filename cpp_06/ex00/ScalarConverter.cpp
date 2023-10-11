#include "ScalarConverter.hpp"

	std::string	ScalarConverter::_inputValue = "";
	char		ScalarConverter::_charValue = 0;
	int			ScalarConverter::_intValue = 0;
	float		ScalarConverter::_floatValue = 0;
	double		ScalarConverter::_doubleValue = 0;
	double		ScalarConverter::_rangeChecker = 0;
	int			ScalarConverter::_type = 0;

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
	_rangeChecker = strtod(literal.c_str(), NULL);
	_findType();
	_convertTypes();
	_printTypes();
}

/*-------------------------TYPE_IDENTIFICATION--------------------------------*/

void	ScalarConverter::_findType(void) {
	_isChar();
	_isInt();
	_isFloat();
	_isDouble();
	_isPseudo();
	if (!_type)
		throw "Invalid input";
}

void	ScalarConverter::_isChar(void) {
	if (_inputValue.length() == 1 && !isdigit(_inputValue[0]))
		_type = CHAR;
}

void	ScalarConverter::_isInt(void) {
	if (!_type) {
		for (size_t i = 0; i < _inputValue.length(); i++) {
			if (i == 0 && (_inputValue[i] == '-' || _inputValue[i] == '+'))
				continue;
			else if (!std::isdigit(_inputValue[i]))
				return;
		}
		if (_rangeChecker > INT_MAX || _rangeChecker < INT_MIN)
			throw "Int overflow";
		_type = INT;
	}
}

void	ScalarConverter::_isFloat(void) {
	if (!_type) {
		size_t	findF = _inputValue.find("f");
		size_t	findDecimalPoint = _inputValue.find(".");
		size_t	len = _inputValue.length();

		if (findF == std::string::npos || findF != (len - 1))
			return;
		if (findDecimalPoint == std::string::npos || findDecimalPoint == 0
			|| findDecimalPoint == (len - 2) || _countDecimalPoint() != 1)
			return;
		if (!_isDecimalNumberFloat())
			return;
		if (_rangeChecker > FLT_MAX || _rangeChecker < -FLT_MAX)
			throw "Float overflow";
		_type = FLOAT;
	}
}

void	ScalarConverter::_isDouble(void) {
	if (!_type) {
		size_t	findDecimalPoint = _inputValue.find(".");
		size_t	len = _inputValue.length();

		if (findDecimalPoint == std::string::npos || findDecimalPoint == 0
			|| findDecimalPoint == (len - 1) || _countDecimalPoint() != 1)
			return;
		if (!_isDecimalNumberDouble())
			return;
		if (_rangeChecker > DBL_MAX || _rangeChecker < -DBL_MAX)
			throw "Double overflow";
		_type = DOUBLE;
	}
}

void	ScalarConverter::_isPseudo(void) {
	if (!_type) {
		std::string pseudoF[3] = {"-inff", "+inff", "nanf"};
		std::string pseudoD[3] = {"-inf", "+inf", "nan"};
		for (int i = 0; i < 6; i++) {
			if (_inputValue == pseudoF[i])
				_type = PSEUDO_FLT;
			else if (_inputValue == pseudoD[i])
				_type = PSEUDO_DBL;
		}
	}
}

/*----------------------------TYPE_CONVERSION---------------------------------*/

void	ScalarConverter::_convertTypes(void) {
	if (_type == CHAR)
		_convertChar();
	if (_type == INT)
		_convertInt();
	if (_type == FLOAT || _type == PSEUDO_FLT)
		_convertFloat();
	if (_type == DOUBLE || _type == PSEUDO_DBL)
		_convertDouble();
}

void	ScalarConverter::_convertChar(void) {
	_charValue = _inputValue[0];
	_intValue = static_cast<int>(_charValue);
	_floatValue = static_cast<float>(_charValue);
	_doubleValue = static_cast<double>(_charValue);
}

void	ScalarConverter::_convertInt(void) {
	_intValue = atoi(_inputValue.c_str());
	_charValue = static_cast<char>(_intValue);
	_floatValue = static_cast<float>(_intValue);
	_doubleValue = static_cast<double>(_intValue);
}

void	ScalarConverter::_convertFloat(void) {
	_floatValue = atof(_inputValue.c_str());
	_intValue = static_cast<int>(_floatValue);
	_charValue = static_cast<char>(_floatValue);
	_doubleValue = static_cast<double>(_floatValue);
}

void	ScalarConverter::_convertDouble(void) {
	_doubleValue = strtod(_inputValue.c_str(), NULL);
	_intValue = static_cast<int>(_doubleValue);
	_charValue = static_cast<char>(_doubleValue);
	_floatValue = static_cast<float>(_doubleValue);
}

/*-----------------------------TYPE_PRINTING----------------------------------*/

void	ScalarConverter::_printTypes(void) {
	_printChar();
	_printInt();
	_printFloat();
	_printDouble();
}

void	ScalarConverter::_printChar(void) {
	if ((_rangeChecker > CHAR_MAX || _rangeChecker < CHAR_MIN)
		|| (_type == PSEUDO_DBL || _type == PSEUDO_FLT))
		std::cout << "char: Impossible" << std::endl;
	else if (isprint(_charValue))
		std::cout << "char: '" << _charValue << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
}

void	ScalarConverter::_printInt(void) {
	if ((_rangeChecker > INT_MAX || _rangeChecker < INT_MIN)
		|| (_type == PSEUDO_DBL || _type == PSEUDO_FLT))
		std::cout << "int: Impossible" << std::endl;
	else
		std::cout << "int: " << _intValue << std::endl;
}

void	ScalarConverter::_printFloat(void) {
	if (_rangeChecker > FLT_MAX || _rangeChecker < -FLT_MAX)
		std::cout << "float: Impossible" << std::endl;
	else {
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << _floatValue << "f" << std::endl;
	}
}

void	ScalarConverter::_printDouble(void) {
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "double: " << _doubleValue << std::endl;
}

/*---------------------------------UTILS--------------------------------------*/

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
