#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <string>
# include <iostream>
# include <algorithm>

class Span {

	public:

		Span(unsigned int N);
		Span(Span const &src);

		~Span(void);

		Span &operator=(Span const &rhs);

		unsigned int size(void) const;
		std::vector<int> getVect(void) const;

		void	addNumber(int n);
		void	addNumber(std::vector<int>::iterator const &start, std::vector<int>::iterator const &end);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

		class NoMoreSpaceException: public std::exception {
			virtual const char *what(void) const throw() {
				return ("Exception: This span is already full");
			}
		};

		class NotEnoughNumbersException: public std::exception {
			virtual const char *what(void) const throw() {
				return ("Exception: At least two numbers are needed to have a span");
			}
		};

	private:

		unsigned int _maxSize;
		std::vector<int>	_v;
		Span(void);
};

#endif