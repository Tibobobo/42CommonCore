# include <iostream>
# include "PmergeMe.hpp"

int	main(int ac, char **av) {

	if (ac == 1)
	{
		std::cout << "Error: Program must be given a positive int sequence" << std::endl;
		return (-1);
	}
	int tmp;
	for (int i = 1; i < ac ; i++)
	{
		tmp = std::atoi(av[i]);
		if (tmp < 1 || tmp != std::atoll(av[i]))
		{
			std::cout << "Error: Program must be given a positive int sequence" << std::endl;
			return (-1);
		}
	}
	PmergeMe test;
	test.sort(ac, av);
	return (0);
}