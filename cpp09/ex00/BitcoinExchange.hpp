#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <sstream>
# include <iomanip>

# define DATA_CSV "a.csv"

class BitcoinExchange {
	private:
		std::vector<std::string>	_data;
		std::vector<std::string>	_input;
		std::string					_inputFileName;

	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	loadData();
		void	printData();


};

# endif
