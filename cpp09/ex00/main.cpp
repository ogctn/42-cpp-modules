#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "usage: ./bitcoin <file_name>" << std::endl;
		return (1);
	}

	BitcoinExchange exchange;
	exchange.calculate(av[1]);
	exchange.printData(exchange.getResult());

	return (0);
}

