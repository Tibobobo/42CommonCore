#include <string>
#include <iostream>
#include "Converter.hpp"

int	main(int ac, char **av) {

	if (ac != 2)
	{
		std::cerr << "Error. Program must be launched with 1 argument" << std::endl;
		return (-1);
	}
	try {
		Converter c(av[1]);
		if (c.getOverflow() == true)
			std::cout << "char: impossible" << std::endl;
		else if (std::isprint(c.getChar()))
			std::cout << "char: '" << c.getChar() << "'" << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		if (c.getOverflow() == true)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << c.getInt() << std::endl;
		std::cout << std::fixed << "float: ";
		if (c.getInt() == c.getFloat())
			std::cout << c.getInt() << ".0f" << std::endl;
		else
			std::cout << c.getFloat() << "f" << std::endl;
		std::cout << "double: ";
		if (c.getInt() == c.getDouble())
			std::cout << c.getInt() << ".0" << std::endl;
		else
			std::cout << c.getDouble() << std::endl;
	}
	catch(const std::exception &e) {

		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}