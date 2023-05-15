# include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> v, std::list<int> l) : _v(v), _l(l) {

}

PmergeMe::~PmergeMe(void) {

}

void	PmergeMe::insertV(std::vector<int> &vect) {

	int i, j, tmp;
	int size = vect.size();

	for (i = 1; i < size; i++)
	{
		tmp = vect[i];
		j = i - 1;
		while (j >= 0 && vect[j] > tmp)
		{
			vect[j + 1] = vect[j];
			j--;
		}
		vect[j + 1] = tmp;
	}
}

void	PmergeMe::mergeV(std::vector<int> &left, std::vector<int> &right, std::vector<int> &result) {

	int i = 0, j = 0, k = 0;
	int lsize = left.size();
	int rsize = right.size();

	while (j < lsize && k < rsize)
	{
		if (left[j] < right[k])
		{
			result[i] = left[j];
			j++;
		}
		else
		{
			result[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < lsize)
	{
		result[i] = left[j];
		j++;
		i++;
	}
	while (k < rsize)
	{
		result[i] = right[k];
		k++;
		i++;
	}
}

void	PmergeMe::mergeInsertV(std::vector<int> &vect) {

	if (vect.size() <= K)
	{
		insertV(vect);
		return ;
	}
	int mid = vect.size() / 2;
	std::vector<int> left(vect.begin(), vect.end() - mid);
	if (vect.size() % 2 == 1)
		mid++;
	std::vector<int> right(vect.begin() + mid, vect.end());
	mergeInsertV(left);
	mergeInsertV(right);
	mergeV(left, right, vect);
}

void	PmergeMe::sort(void) {

	long long int start;
	start = getTime();
	mergeInsertV(_v);
}

void	PmergeMe::printSequence(void) {

	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << " " << *it;
}

long long int PmergeMe::getTime(void) const {

	std::time_t t;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}