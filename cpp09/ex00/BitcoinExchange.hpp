#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>


# define DATA_CSV "data.csv"


class BitcoinExchange {
	private:
		std::vector<std::string>	_priceData;
		std::vector<int>			_dateInt;
		std::vector<std::string>	_input;
		std::vector<std::string>	_result;


	public:
		BitcoinExchange();
		BitcoinExchange(std::string dataset);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		std::vector<std::string>	getPriceData() const;
		std::vector<std::string>	getInput() const;
		std::vector<std::string>	getResult() const;

		void	readData(std::string src, char delimiter);
		int		fillData(std::vector<std::string> &data, char delimiter);
		void	printData(const std::vector<std::string> &vec) const;
		
		void	calculate(const std::string &input_file);
		float	findClosestPrice(const std::string &line); 
		float	findAndMultValues(std::string line);
};


# endif
