#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <time.h>

# define K 6

class PmergeMe {

	public:

		PmergeMe(std::vector<int> v, std::deque<int> l);

		~PmergeMe(void);

		void	sort(void);
		void	printSequence(void);

		void mergeInsertV(std::vector<int> &vect);
		void mergeV(std::vector<int> &left, std::vector<int> &right, std::vector<int> &result);
		void insertV(std::vector<int> &vect);

		void mergeInsertD(std::deque<int> &dq);
		void mergeD(std::deque<int> &left, std::deque<int> &right, std::deque<int> &result);
		void insertD(std::deque<int> &dq);

	private:

		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &rhs);
		std::vector<int> _v;
		std::deque<int> _d;
		float _time;
};

#endif