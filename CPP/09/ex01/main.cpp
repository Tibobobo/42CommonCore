#include "RPN.hpp"
#include <iostream>
#include <string>

int	main(int ac, char **av) {

	if (ac != 2)
	{
		std::cerr << "Error" << std::endl;
		return (-1);
	}
	RPN calculator(av[1]);
	calculator.calculate();
	return (0);
}