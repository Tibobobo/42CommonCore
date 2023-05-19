#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>

class NotFoundException: public std::exception {
	virtual const char *what() const throw() {
		return ("Value not found in container");
	}
};

template <typename T>
typename T::iterator	easyfind(T &container, int n) {

	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw (NotFoundException());
	else
		return (it);
}

#endif