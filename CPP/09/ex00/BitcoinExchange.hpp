#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>
# include <iostream>

typedef std::pair<std::string, float> pair;

class BitcoinExchange {

	public:

		BitcoinExchange(std::string dbPath, std::string filePath);
		BitcoinExchange(BitcoinExchange const &src);

		~BitcoinExchange(void);

		BitcoinExchange &operator=(BitcoinExchange const &rhs);

		std::map<std::string, float> getDb(void);
		std::map<std::string, float> getFile(void);
		void	setDb(std::string path);
		void	setFile(std::string path);

	private:

		BitcoinExchange(void);
		std::map<std::string, float> _db;
		std::map<std::string, float> _file;

};

#endif