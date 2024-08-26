#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() { loadData(); }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
	_data = other._data;
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::string filename) : _inputFileName(filename) { loadData(); }

int	checkData(const std::vector<std::string> &data, int &i) {
	if (data.empty() || data.size() < 2)
		return (1);
	
	for 
	
}


void BitcoinExchange::loadData() {
	std::ifstream file(DATA_CSV);
	if (!file.is_open()) {
		std::cerr << "error: " << strerror(errno) << std::endl;
		exit (1);
	}

	std::string	line;
	while (std::getline(file, line))
		if (!line.empty() || line.find_first_not_of(" \t\n") != std::string::npos)
			_data.push_back(line);

	int i = 0;
	if (checkData(this->_data), i) {
		std::cerr << "error: invalid data in data.csv in line:" << i << std::endl;
		exit (1);
	}

	file.close();
}

void BitcoinExchange::printData() {
	if (_data.empty()) {
		std::cerr << "error: no data to print" << std::endl;
		return;
	}
	for (std::vector<std::string>::iterator it = _data.begin(); it != _data.end(); it++) {
		std::cout << *it << std::endl;
	}
}
