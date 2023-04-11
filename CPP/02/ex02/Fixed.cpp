#include "Fixed.hpp"

//Constructors

Fixed::Fixed(void) : _val(0){

}

Fixed::Fixed(Fixed const &src) {

	*this = src;
}

Fixed::Fixed(int const src) {

	this->_val = src << _fract;
}

Fixed::Fixed(float const src) {

	this->_val = roundf(src * (1 << _fract));
}

//Destructor

Fixed::~Fixed(void) {

}

//Operators

Fixed	&Fixed::operator=(Fixed const &rhs) {

	if (this != &rhs)
		this->_val = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const rhs) const {

	if (this->toFloat() > rhs.toFloat())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(Fixed const rhs) const {

	if (this->toFloat() < rhs.toFloat())
		return (true);
	else
		return (false);
}

bool	Fixed::operator>=(Fixed const rhs) const {

	if (this->toFloat() >= rhs.toFloat())
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(Fixed const rhs) const {

	if (this->toFloat() <= rhs.toFloat())
		return (true);
	else
		return (false);
}

bool	Fixed::operator==(Fixed const rhs) const {

	if (this->toFloat() == rhs.toFloat())
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(Fixed const rhs) const {

	if (this->toFloat() != rhs.toFloat())
		return (true);
	else
		return (false);
}

Fixed	Fixed::operator+(Fixed const rhs) const {

	Fixed	res;

	res.setRawBits(this->getRawBits() + rhs.getRawBits());
	return (res);
}

Fixed	Fixed::operator-(Fixed const rhs) const {

	Fixed	res;

	res.setRawBits(this->getRawBits() - rhs.getRawBits());
	return (res);
}

Fixed	Fixed::operator*(Fixed const rhs) const {

	Fixed	res(this->toFloat() * rhs.toFloat());

	return (res);
}

Fixed	Fixed::operator/(Fixed const rhs) const {

	Fixed	res(this->toFloat() * rhs.toFloat());

	return (res);
}

Fixed	Fixed::operator++(void) {

	this->_val++;
	return (*this);
}

Fixed	Fixed::operator--(void) {

	this->_val--;
	return (*this);
}

Fixed	Fixed::operator++(int) {

	Fixed old = *this;

	++this->_val;
	return (old);
}

Fixed	Fixed::operator--(int) {

	Fixed old = *this;

	--this->_val;
	return (old);
}

//getter,setter

int	Fixed::getRawBits(void) const {

	return (this->_val);
}

void	Fixed::setRawBits(int const raw) {

	this->_val = raw;
}

//Other

float	Fixed::toFloat(void) const {

	return ((float)this->_val / (float)(1 << _fract));
}

int		Fixed::toInt(void) const {

	return (this->_val >> _fract);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {

	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(Fixed const &a, Fixed const &b) {

	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b) {

	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b) {

	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &instance) {

	o << instance.toFloat();
	return (o);
}

int const Fixed::_fract = 8;