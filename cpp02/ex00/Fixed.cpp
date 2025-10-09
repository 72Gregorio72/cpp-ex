# include <iostream>
# include <cmath>
# include "Fixed.hpp"

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	fixedPointValue = 0;
};

Fixed::Fixed (const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
};

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other) {
		return *this;
	}

	setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
	std::cout << "Int constructor called" << std::endl;
	fixedPointValue = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	fixedPointValue = roundf(floatValue * (1 << fractionalBits));
}

float Fixed::ToFloat( void ) const {
	return (float)fixedPointValue / (1 << fractionalBits);
}

int Fixed::ToInt( void ) const {
	return fixedPointValue >> fractionalBits;
}

Fixed &Fixed::operator<<(const Fixed &other) {
	this->fixedPointValue = this->fixedPointValue << other.fixedPointValue;
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
	fixedPointValue = raw;
};