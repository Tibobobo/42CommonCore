#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

void	storeInMap(std::map<std::string,float> map, std::ifstream &stream, int type) {

	map.clear();
	std::string line;
	std::string left;
	std::string right;
	std::string delimiter;
	float	value = 0.0f;
	if (type == 1)
		delimiter = ",";
	else
		delimiter = " | ";
	while (getline(stream, line))
	{
		pair p;
		size_t pos = line.find(delimiter);
		if (pos == std::string::npos)
		{
			line.insert(0, "Error: bad input => ");
			p.first = line;
			p.second = -42.0f;
			map.insert(p);
			continue;
		}
		left = line.substr(0, pos);
		right = line.substr(pos + delimiter.length(), line.length());
		try {
			value = std::atof(right.c_str());
		}
		catch (std::exception &e) {
			line.insert(0, "Error: bad input => ");
			p.first = line;
			p.second = -42.0f;
			map.insert(p);
			continue;
		}
		p.first = left;
		p.second = value;
		map.insert(p);
	}
	std::map<std::string, float>::iterator it = map.begin();
	for (; it != map.end(); it++)
	{
		std::cout << it->first << " | " << it->second << std::endl;
	}
}

int	main(int ac, char **av) {

	(void)av;
	if (ac != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (-1);
	}
	std::map<std::string, float> db;
	std::map<std::string, float> file;
	std::ifstream dbstream;
	std::ifstream filestream;

	dbstream.open("data.csv");
	if (dbstream.is_open() == false)
	{
		std::cerr << "Error: could not open database." << std::endl;
		return (-1);
	}
	storeInMap(db, dbstream, 1);
	dbstream.close();

	// filestream.open(av[1]);
	// if (filestream.is_open() == false)
	// {
	// 	std::cerr << "Error: could not open file." << std::endl;
	// 	return (-1);
	// }
	// storeInMap(file, filestream, 2);
	// filestream.close();
}