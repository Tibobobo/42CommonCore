#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string path) :_path(path) {
	
}

BitcoinExchange::~BitcoinExchange(void) {

}

bool	BitcoinExchange::loadDb(void) {

	std::ifstream stream;
	stream.open("data.csv");
	if (stream.is_open() == false)
	{
		std::cerr << "Error: could not open database." << std::endl;
		return (false);
	}
	_db.clear();
	std::string line;
	std::string left;
	std::string right;
	std::string delimiter = ",";
	pair p;
	size_t pos;
	float	value = 0.0f;

	while (std::getline(stream, line))
	{
		pos = line.find(delimiter);
		if (pos == std::string::npos)
			continue;
		left = line.substr(0, pos);
		right = line.substr(pos + delimiter.length(), line.length());
		value = std::atof(right.c_str());
		if (value == 0 && isActually0(right) == false)
			continue;
		p.first = left;
		p.second = value;
		_db.insert(p);
	}
	stream.close();
	if (_db.find("2009-01-02") == _db.end())
	{
		std::cerr << "Please use this program with original unmodified data.csv database" << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::convert(void) {

	std::ifstream filestream;
	std::string line;
	std::string date;
	std::string value;
	float	fValue;
	std::string delimiter = " | ";
	size_t pos;

	if (loadDb() == false)
		return (false);
	filestream.open(_path.c_str());
	if (filestream.is_open() == false)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (false);
	}
	while (std::getline(filestream, line))
	{
		if (line.compare("date | value") == 0)
			continue;
		pos = line.find(delimiter);
		if (pos == std::string::npos)
		{
			line.insert(0, "Error: bad input => ");
			std::cerr << line << std::endl;
			continue;
		}
		date = line.substr(0, pos);
		value = line.substr(pos + delimiter.length(), line.length());
		fValue = std::atof(value.c_str());
		if (fValue == 0 && isActually0(value) == false)
		{
			line.insert(0, "Error: bad input => ");
			std::cerr << line << std::endl;
			continue;
		}
		else if (fValue < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		else if (fValue > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		else if (checkDateFormat(date) == false)
		{
			line.insert(0, "Error: bad input => ");
			std::cerr << line << std::endl;
			continue;
		}
		else
			std::cout << date << " => " << value << " = " << getTotalFromDb(date, fValue) << std::endl;
	}
	filestream.close();
	return (true);
}

bool	BitcoinExchange::isActually0(std::string str) const {

	std::string::iterator i = str.begin();
	bool point = false;
	while(i != str.end() && std::isspace(*i))
		i++;
	if (i != str.end() && (*i == '+' || *i == '-'))
		i++;
	if (*i != '0')
		return (false);
	while (i != str.end())
	{
		if (*i == '.' && point == false)
			point = true;
		if (*i == '.' && point == true)
			return (false);
		if (*i != '.' && *i != '0')
			return (false);
		i++;
	}
	return (true);
}

bool BitcoinExchange::checkDateFormat(std::string str) const {

	int year;
	int month;
	int day;

	if (str.length() != 10)
		return (false);
	if (str[4] != '-' || str[7] != '-' || !std::isdigit(str[0]) || !std::isdigit(str[1]) || !std::isdigit(str[2]) || !std::isdigit(str[3])
		|| !std::isdigit(str[5]) || !std::isdigit(str[6]) || !std::isdigit(str[8]) || !std::isdigit(str[9]))
		return (false);
	year = std::atoi(str.substr(0, 4).c_str());
	month = std::atoi(str.substr(5, 2).c_str());
	day = std::atoi(str.substr(8, 2).c_str());
	if (year < 2009 || year > 2023)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	if (day == 31 && (month == 4 || month == 6 || month == 9 || month == 11))
		return (false);
	if (month == 2 && day > 28)
	{
		if (day == 29 && (year == 2012 || year == 2016 || year == 2020))
			return (true);
		return (false);
	}
	if (year == 2009 && month == 1 && day == 1)
		return (false);
	return (true);
	
}

float BitcoinExchange::getTotalFromDb(std::string date, float n) const {

	std::map<std::string, float>::const_iterator it = _db.find(date);
	if (it != _db.end())
		return (n * it->second);
	else
	{
		it = _db.lower_bound(date);
		it--;
		return (n * it->second);
	}
}