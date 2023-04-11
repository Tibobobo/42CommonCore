#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {

	public:

		Fixed(void);
		Fixed(Fixed const &src);
		Fixed(int const src);
		Fixed(float const src);
		~Fixed(void);
		Fixed	&operator=(Fixed const &rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

	private:

		int	_val;
		static int const _fract;
};

std::ostream	&operator<<(std::ostream &o, Fixed const &instance);

#endif