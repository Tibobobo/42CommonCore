#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <time.h>
# include <cstdlib>

# define K 7

class PmergeMe {

	public:

		PmergeMe(void);

		~PmergeMe(void);

		void	sort(int ac, char **av);
		void	printSequence(void);

		void	avToVect(int ac, char **av, std::vector<int> &v);
		void	avToDq(int ac, char **av, std::deque<int> &l);

		void mergeInsertV(std::vector<int> &vect);
		void mergeV(std::vector<int> &left, std::vector<int> &right, std::vector<int> &result);
		void insertV(std::vector<int> &vect);

		void mergeInsertD(std::deque<int> &dq);
		void mergeD(std::deque<int> &left, std::deque<int> &right, std::deque<int> &result);
		void insertD(std::deque<int> &dq);

	private:

		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &rhs);
		std::vector<int> _v;
		std::deque<int> _d;
		float _vTime;
		float _dTime;
};

#endif