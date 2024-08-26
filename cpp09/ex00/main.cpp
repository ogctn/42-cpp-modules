#include "BitcoinExchange.hpp"
#include <iostream>

#include <cerrno>
#include <cstring>


int check_filename(std::string name) {
	size_t pos = name.find(".csv");
	return (pos != std::string::npos &&
			pos == name.size() - 4 &&
			pos != 0);
}


int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "usage: ./bitcoin <file_name>" << std::endl;
		return (1);
	}

	BitcoinExchange exchange(av[1]);
	exchange.printPriceData();

	// exchange.readCSV(av[1]);
	

	return (0);
}


