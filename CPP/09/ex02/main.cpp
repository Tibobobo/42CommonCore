# include <iostream>
# include <cstdlib>
# include <vector>
# include <deque>
# include "PmergeMe.hpp"

bool	avToVect(int ac, char **av, std::vector<int> &v) {

	int tmp;
	std::vector<int>::iterator it;
	for (int i = 1; i < ac ; i++)
	{
		tmp = std::atoi(av[i]);
		if (tmp < 1 || tmp != std::atoll(av[i]))
		{
			std::cout << "Error: Program must be given a positive int sequence" << std::endl;
			return (false);
		}
		for (it = v.begin(); it != v.end(); it++)
		{
			if (*it == tmp)
			{
				std::cout << "Error: No doubles allowed in int sequence" << std::endl;
				return (false);
			}
		}
		v.push_back(tmp);
	}
	return (true);
}

void	avToDq(int ac, char **av, std::deque<int> &l) {

	for (int i = 1; i < ac ; i++)
		l.push_back(std::atoi(av[i]));
}

int	main(int ac, char **av) {

	if (ac == 1)
	{
		std::cout << "Error: Program must be given a positive int sequence" << std::endl;
		return (-1);
	}
	std::vector<int> vect;
	std::deque<int> dq;

	if (avToVect(ac, av, vect) == false)
		return (-1);
	avToDq(ac, av, dq);
	PmergeMe test(vect, dq);
	test.sort();
	return (0);
}