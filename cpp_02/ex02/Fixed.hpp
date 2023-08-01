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

	Fixed	operator+(Fixed const & rhs) const;
	Fixed	operator-(Fixed const & rhs) const;
	Fixed	operator*(Fixed const & rhs) const;
	Fixed	operator/(Fixed const & rhs) const;

	bool	operator>(Fixed const & rhs) const;
	bool	operator<(Fixed const & rhs) const;
	bool	operator>=(Fixed const & rhs) const;
	bool	operator<=(Fixed const & rhs) const;
	bool	operator==(Fixed const & rhs) const;
	bool	operator!=(Fixed const & rhs) const;

	// empty parameter list => PREFIX
	// dummy parameter => POSTFIX
	Fixed	operator++(void);
	Fixed	operator++(int);
	Fixed	operator--(void);
	Fixed	operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed		&min(Fixed &fixed1, Fixed &fixed2);
	static const Fixed	&min(const Fixed &fixed1, const Fixed &fixed2);
	static Fixed		&max(Fixed &fixed1, Fixed &fixed2);
	static const Fixed	&max(const Fixed &fixed1, const Fixed &fixed2);

private:
	int					_fixedValue;
	static int const	_fractionalBits = 8;

};

std::ostream&	operator<<(std::ostream &output, Fixed const &rhs);

#endif
