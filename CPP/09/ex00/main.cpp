#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int	main(int ac, char **av) {

	(void)av;
	if (ac == 1)
	{
		std::cout << "Error: could not open file." << std::endl;
		return (-1);
	}
	else if (ac > 2)
	{
		std::cout << "Error: too many arguments. Launch program with file path only." << std::endl;
		return (-1);
	}
	BitcoinExchange exchange(av[1]);
	exchange.convert();
	return (0);
}