#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
	Fixed(void);
	Fixed(int const n);
	Fixed(float const n);
	Fixed(Fixed const & src);
	~Fixed(void);

	Fixed&	operator=(Fixed const & rhs);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	int					_fixedValue;
	static int const	_fractionalBits = 8;

};

std::ostream&	operator<<(std::ostream &output, Fixed const &rhs);

#endif

