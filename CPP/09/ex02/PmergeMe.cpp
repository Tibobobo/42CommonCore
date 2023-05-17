# include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::vector<int> v, std::deque<int> dq) : _v(v), _d(dq) {

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

void	PmergeMe::insertD(std::deque<int> &dq) {

	int i, j, tmp;
	int size = dq.size();

	for (i = 1; i < size; i++)
	{
		tmp = dq[i];
		j = i - 1;
		while (j >= 0 && dq[j] > tmp)
		{
			dq[j + 1] = dq[j];
			j--;
		}
		dq[j + 1] = tmp;
	}
}

void	PmergeMe::mergeD(std::deque<int> &left, std::deque<int> &right, std::deque<int> &result) {

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

void	PmergeMe::mergeInsertD(std::deque<int> &dq) {

	if (dq.size() <= K)
	{
		insertD(dq);
		return ;
	}
	int mid = dq.size() / 2;
	std::deque<int> left(dq.begin(), dq.end() - mid);
	if (dq.size() % 2 == 1)
		mid++;
	std::deque<int> right(dq.begin() + mid, dq.end());
	mergeInsertD(left);
	mergeInsertD(right);
	mergeD(left, right, dq);
}

void	PmergeMe::sort(void) {

	std::cout << "Before:  ";
	printSequence();
	std::cout << std::endl;

	struct timespec vStart, vEnd, dStart, dEnd;
	double timeTaken, sec, nano;

	clock_gettime(CLOCK_REALTIME, &vStart);
	mergeInsertV(_v);
	clock_gettime(CLOCK_REALTIME, &vEnd);

	clock_gettime(CLOCK_REALTIME, &dStart);
	mergeInsertD(_d);
	clock_gettime(CLOCK_REALTIME, &dEnd);

	sec = (vEnd.tv_sec - vStart.tv_sec) * 1000000;
	nano = (vEnd.tv_nsec - vStart.tv_nsec) * 0.001;
	timeTaken = sec + nano;
	std::cout << "After:  ";
	printSequence();
	std::cout << std::endl;
	std::cout << "Time to process a range of " << _v.size() << " elements with std::vector : ";
	std::cout << std::fixed << timeTaken << " us" << std::endl;

	sec = (dEnd.tv_sec - dStart.tv_sec) * 1000000;
	nano = (dEnd.tv_nsec - dStart.tv_nsec) * 0.001;
	timeTaken = sec + nano;
	std::cout << "Time to process a range of " << _v.size() << " elements with std::deque : ";
	std::cout << std::fixed << timeTaken << " us" << std::endl;
}

void	PmergeMe::printSequence(void) {

	for (std::vector<int>::iterator it = _v.begin(); it != _v.end(); it++)
		std::cout << " " << *it;
}