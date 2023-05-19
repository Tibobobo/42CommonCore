#include "Fixed.hpp"

Fixed::Fixed(void) : _val(0){

	std:: cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {

	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const src) {

	std::cout << "Int constructor called" << std::endl;
	this->_val = src << _fract;
}

Fixed::Fixed(float const src) {

	std::cout << "Float constructor called" << std::endl;
	this->_val = roundf(src * (1 << _fract));
}

Fixed::~Fixed(void) {

	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &rhs) {

	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_val = rhs.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const {

	return (this->_val);
}

void	Fixed::setRawBits(int const raw) {

	this->_val = raw;
}

float	Fixed::toFloat(void) const {

	return ((float)this->_val / (float)(1 << _fract));
}

int		Fixed::toInt(void) const {

	return (this->_val >> _fract);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &instance) {

	o << instance.toFloat();
	return (o);
}

int const Fixed::_fract = 8;