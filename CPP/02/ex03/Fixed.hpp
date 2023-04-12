#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

	public:

		//constructors
		Fixed(void);
		Fixed(Fixed const &src);
		Fixed(int const src);
		Fixed(float const src);

		//destructor
		~Fixed(void);

		//operators
		Fixed	&operator=(Fixed const &rhs);

		bool	operator>(Fixed const rhs) const;
		bool	operator<(Fixed const rhs) const;
		bool	operator>=(Fixed const rhs) const;
		bool	operator<=(Fixed const rhs) const;
		bool	operator==(Fixed const rhs) const;
		bool	operator!=(Fixed const rhs) const;

		Fixed	operator+(Fixed const rhs) const;
		Fixed	operator-(Fixed const rhs) const;
		Fixed	operator*(Fixed const rhs) const;
		Fixed	operator/(Fixed const rhs) const;

		Fixed	operator++(void);
		Fixed	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);

		//getter, setter
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		//other
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed	&min(Fixed &a, Fixed &b);
		static const Fixed	&min(Fixed const &a, Fixed const &b);
		static Fixed	&max(Fixed &a, Fixed &b);
		static const Fixed	&max(Fixed const &a, Fixed const &b);

	private:

		int	_val;
		static int const _fract;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &instance);

#endif