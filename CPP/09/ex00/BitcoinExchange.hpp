#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>
# include <fstream>
#include <cstdlib>

typedef std::pair<std::string, float> pair;

class BitcoinExchange {

	public:

		BitcoinExchange(std::string path);

		~BitcoinExchange(void);

		bool convert(void);
		bool loadDb(void);
		bool checkDateFormat(std::string str) const;
		float getTotalFromDb(std::string date, float n) const;
		bool isActually0(std::string str) const;

	private:

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &rhs);
		std::map<std::string, float> _db;
		std::string const _path;
};

#endif