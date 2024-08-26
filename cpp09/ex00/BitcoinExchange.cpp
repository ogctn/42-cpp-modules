#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { loadPriceData(); }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	_priceData = other._priceData;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string filename) : _inputFileName(filename) { loadPriceData(); }

void	clear_space_tab_nl(std::string &s) {
	size_t i = 0;
	while (i != std::string::npos) {
		i = s.find_first_of(" \t\n", i);
		if (i != std::string::npos)
			s.erase(i, 1);
	}
}

int is_valid_dash_comma (std::string &s) {

	if (s.find_first_of("-", 0) != 4 || s.find_first_of("-", 5) != 7)
		return (0);
	if (s.find_first_of("-", 8) != std::string::npos)
		return (0);

	if (s.find_first_of(",", 0) != 10)
		return (0);
	if (s.find_first_of(",", 11) != std::string::npos)
		return (0);

	return (1);
}

bool checkFloat(std::string str) {
	size_t pos;

	if (str.find_first_not_of("0123456789+-.") != std::string::npos)
		return (true);

	if (str.find_first_not_of("+-.") == std::string::npos)
		return (true);
	
	pos = str.find_first_of("+-", 0);
	if ((pos != std::string::npos && pos > 0) || str.find_first_of("+-", pos + 1) != std::string::npos)
		return (true);

	pos = str.find_first_of(".", 0);
	if (str.find_first_of(".", pos + 1) != std::string::npos)
		return (true);

	if ((str[0] == '+' || str[0] == '-')) {
		if (str[1] == '.' && str.find_first_of("0123456789", 2) == std::string::npos) {
			return (true);
		}
		else if (str.find_first_of("0123456789", 1) == std::string::npos)
			return (true);
	}
	else {
		if (str[0] == '.' && str.find_first_of("0123456789", 1) == std::string::npos)
			return (true);
	}

	return (false);
}

int	is_invalid_data(std::vector<std::string> &data) {
	
	if (data.empty() || data.size() < 2)
		return (2);
	if (data[0] != "date,exchange_rate")
		return (std::cout << "First line should be \"date,exchange_rate\"\n", 1);

	std::string	sub;
	for (size_t i = 1; i < data.size(); ++i) {
		clear_space_tab_nl(data[i]);

		if (data[i].empty())
			continue;
		else if (data[i].size() < 12)
			return (i + 1);

		sub = data[i].substr(0, 11);
		if (!is_valid_dash_comma(sub))
			return (i + 1);

		sub = data[i].substr(0, 4);
		if (sub.find_first_not_of("0123456789") != std::string::npos)
			return (i + 1);

		if (data[i][4] != '-')
			return (i + 1);

		sub = data[i].substr(5, 2);
		if (sub.find_first_not_of("0123456789") != std::string::npos)
			return (i + 1);

		if (data[i][7] != '-')
			return (i + 1);

		sub = data[i].substr(8, 2);
		if (sub.find_first_not_of("0123456789") != std::string::npos)
			return (i + 1);

		if (data[i][10] != ',')
			return (i + 1);

		sub = data[i].substr(11, data[i].size() - 11);
		if (checkFloat(sub))
			return (i + 1);

		try {
			std::stof(sub);
		} catch (std::exception &e) {
			std::cout << "Bad data, please check \"exchange_rate\"" << std::endl;
			return (i + 1);
		}
	}
	return (0);
}

void BitcoinExchange::loadPriceData() {
	std::ifstream file(DATA_CSV);
	if (!file.is_open()) {
		std::cerr << "error: " << strerror(errno) << std::endl;
		exit (1);
	}

	std::string	line;
	while (std::getline(file, line))
		_priceData.push_back(line);

	int error_at = is_invalid_data(_priceData);
	if (error_at) {
		std::cerr << "error: invalid data in " << DATA_CSV << " file. Check line \"" << error_at << "\"" << std::endl;
		exit (1);
	}
	file.close();

	std::vector<std::string>::iterator it = _priceData.begin();
	while (it != _priceData.end()) {
		if (it->empty())
			it = _priceData.erase(it);
		else
			++it;
	}	
}

void BitcoinExchange::printPriceData() {
	if (this->_priceData.empty()) {
		std::cerr << "error: no data to print" << std::endl;
		return;
	}
	for (std::vector<std::string>::iterator it = _priceData.begin(); it != _priceData.end(); it++) {
		std::cout << *it << std::endl;
	}
}
