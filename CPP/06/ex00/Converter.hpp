#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>
# include <iostream>
# include <limits>

# define CHAR 0
# define INT 1
# define FLOAT 2
# define DOUBLE 3
# define OTHER 4

class Converter {

	public:

		Converter(void);
		Converter(std::string str);
		Converter(Converter const &src);

		virtual ~Converter( void);

		Converter &operator=(Converter const &rhs);

		char	getChar(void) const;
		int		getInt(void) const;
		float	getFloat(void) const;
		double	getDouble(void) const;
		bool	getOverflow(void) const;

		class	UnknownInput: public std::exception {
			virtual const char *what(void) const throw();
		};

	private:

		char	_c;
		int		_i;
		float	_f;
		double	_d;
		bool	_overflow;
		int		_type;
};

#endif