#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedValue = n << this->_fractionalBits;
}

Fixed::Fixed(float const n) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedValue = (int)round(n * (1 << this->_fractionalBits));
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const & rhs) {
	if (this != &rhs)
		this->_fixedValue = rhs.getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream &output, Fixed const &rhs) {
	output << rhs.toFloat();
	return (output);
}

Fixed	Fixed::operator+(Fixed const & rhs) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(Fixed const & rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(Fixed const & rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const & rhs) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

bool	Fixed::operator>(Fixed const & rhs) const {
	return (this->_fixedValue > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const & rhs) const {
	return (this->_fixedValue < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const & rhs) const {
	return (this->_fixedValue >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const & rhs) const {
	return (this->_fixedValue <= rhs.getRawBits());
}
bool	Fixed::operator==(Fixed const & rhs) const {
	return (this->_fixedValue == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const & rhs) const {
	return (this->_fixedValue != rhs.getRawBits());
}

Fixed	Fixed::operator++(void) {
	++this->_fixedValue;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);
	++this->_fixedValue;
	return (tmp);
}

Fixed	Fixed::operator--(void) {
	--this->_fixedValue;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);
	--this->_fixedValue;
	return (tmp);
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (Fixed::_fixedValue);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	Fixed::_fixedValue = raw;
}


float	Fixed::toFloat(void) const {
	return (static_cast<float>(this->_fixedValue) / (1 << this->_fractionalBits));
}

int	Fixed::toInt(void) const {
	return (this->_fixedValue >> this->_fractionalBits);
}

Fixed	&Fixed::min(Fixed &fixed1, Fixed &fixed2) {
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

const Fixed	&Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
	return (fixed1 < fixed2 ? fixed1 : fixed2);
}

Fixed	&Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

const Fixed	&Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
	return (fixed1 > fixed2 ? fixed1 : fixed2);
}

