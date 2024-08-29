#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <cerrno>
# include <time.h>
# include <algorithm>

# define DATA_CSV "a.csv"


typedef struct	s_date {
	int	year;
	int	month;
	int	day;
}	t_date;

std::string	getDate();

class BitcoinExchange {
	private:
		std::vector<std::string>	_priceData;
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
		std::string					getDate() const;
		std::string					getLineByFind(const std::vector<std::string> &vec, const std::string &date) const;
		std::string					parseDate(const std::string &line) const;
		float						parseVal(const std::string &line) const;

		void	readData(std::string src, std::vector<std::string> &dest, char delimiter);
		void	printData(const std::vector<std::string> &data);
		
		void	calculate(const std::string &input_file);
		float	findClosestPrice(const std::string &find) const; 

};


# endif
