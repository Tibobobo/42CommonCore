#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <ctime>

# define K 6

class PmergeMe {

	public:

		PmergeMe(std::vector<int> v, std::list<int> l);

		~PmergeMe(void);

		void	sort(void);
		void	printSequence(void);

		void mergeInsertV(std::vector<int> &vect);
		void mergeV(std::vector<int> &left, std::vector<int> &right, std::vector<int> &result);
		void insertV(std::vector<int> &vect);

		void mergeInsertL(std::list<int> lst, std::list<int> temp, int l, int size, int threshold);
		void mergeL(std::list<int> lst, std::list<int> temp, int l, int m, int size);
		void insertL(std::list<int> lst, int l, int size);

		long long int getTime(void) const;

	private:

		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &rhs);
		std::vector<int> _v;
		std::list<int> _l;
		float _time;
};

#endif