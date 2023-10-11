#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cfloat>

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define PSEUDO_FLT 5
#define PSEUDO_DBL 6

class ScalarConverter {
public:
	static void	convert(std::string const & literal);

private:
	ScalarConverter(void);
	ScalarConverter(ScalarConverter const & src);
	~ScalarConverter(void);

	ScalarConverter&	operator=(ScalarConverter const & rhs);

	static void	_findType(void);
	static void	_isChar(void);
	static void	_isInt(void);
	static void	_isFloat(void);
	static void	_isDouble(void);
	static void	_isPseudo(void);

	static void	_convertTypes(void);
	static void	_convertChar(void);
	static void	_convertInt(void);
	static void	_convertFloat(void);
	static void	_convertDouble(void);

	static void	_printTypes(void);
	static void	_printChar(void);
	static void	_printInt(void);
	static void	_printFloat(void);
	static void	_printDouble(void);

	static int	_countDecimalPoint(void);
	static bool	_isDecimalNumberFloat(void);
	static bool	_isDecimalNumberDouble(void);

	static std::string	_inputValue;
	static char			_charValue;
	static int			_intValue;
	static float		_floatValue;
	static double		_doubleValue;
	static double		_rangeChecker;
	static int			_type;
};

#endif
