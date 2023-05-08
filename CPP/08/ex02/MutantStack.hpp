#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

template <typename T>
class MutantStack : public std::stack<T> {

	public:

		MutantStack(void) {}
		MutantStack(MutantStack const &src) {}

		~MutantStack(void) {}

		MutantStack &operator=(MutantStack const &rhs) {}
	
	private:

};

#endif