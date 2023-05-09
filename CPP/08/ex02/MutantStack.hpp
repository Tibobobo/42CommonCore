#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <algorithm>

template <typename T>
class MutantStack : public std::stack<T> {

	public:

		MutantStack(void) : std::stack<T>() {};
		MutantStack(MutantStack const &src) : std::stack<T>(src) {};

		virtual ~MutantStack(void) {};

		MutantStack &operator=(MutantStack const &rhs) {
			if (this == &rhs)
				return (*this);
			std::stack<T>::operator=(rhs);
			return (*this);
		};

		typedef typename std::stack<T>::container_type::iterator iterator;

		iterator	begin(void) {
			return (std::stack<T>::c.begin());
		}

		iterator	end(void) {
			return (std::stack<T>::c.end());
		}
	
	private:

};

#endif