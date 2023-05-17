#include "RPN.hpp"
#include <iostream>
#include <string>

int	main(int ac, char **av) {

	if (ac != 2)
	{
		std::cout << "Error" << std::endl;
		return (-1);
	}
	RPN calculator(av[1]);
	if (calculator.calculate() == false)
		return (-1);
	return (0);
}