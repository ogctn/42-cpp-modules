#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "usage: ./bitcoin <file_name>" << std::endl;
		return (1);
	}

	BitcoinExchange ex;
	ex.calculate(av[1]);
	ex.printData(ex.getResult());

	return (0);
}
