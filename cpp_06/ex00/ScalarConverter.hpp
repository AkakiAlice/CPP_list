#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <iomanip>
#include <cstdlib>

#define MAX_INT 2147483647
#define MIN_INT -2147483648

class ScalarConverter {
public:
	static void	convert(std::string const & literal);

private:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter const & src);
	~ScalarConverter(void);

	ScalarConverter&	operator=(ScalarConverter const & rhs);

	static bool	_isChar(void);
	static bool	_isInt(void);
	static bool	_isFloat(void);
	static bool	_isDouble(void);

	static void	_convertChar(std::string const & lieteral);
	static void	_convertInt(std::string const & literal);
	static void	_convertFloat(std::string const & literal);
	static void	_convertDouble(std::string const & literal);

	static void	_printTypes(void);
	static void	_printInt(void);

	static int	_countDecimalPoint(void);
	static bool	_isDecimalNumberFloat(void);
	static bool	_isDecimalNumberDouble(void);

	static std::string	_inputValue;
	static char			_charValue;
	static int			_intValue;
	static float		_floatValue;
	static double		_doubleValue;
	static double		_rangeCheck;
};

#endif
