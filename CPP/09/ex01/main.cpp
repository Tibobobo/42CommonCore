#include "RPN.hpp"
#include <iostream>
#include <string>

bool	isSign(char c) {

	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (true);
	return (false);
}

bool	checkFormat(std::string str) {

	int num = 0;
	int signs = 0;
	if (!std::isdigit(str[0]) || !isSign(str[str.length() - 1]))
		return (false);
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (*it == ' ' && ((it + 1) != str.end() && *(it + 1) != ' '))
			;
		else if (std::isdigit(*it) && *(it + 1) == ' ')
			num++;
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			signs++;
			if (it + 1 != str.end() && *(it + 1) != ' ')
				return (false);
		}
		else
			return (false);
	}
	if (num - signs != 1)
		return (false);
	return (true);
}

int	main(int ac, char **av) {

	if (ac != 2 || checkFormat(av[1]) == false)
	{
		std::cerr << "Error" << std::endl;
		return (-1);
	}
	return (0);
}