#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "usage: ./bitcoin <file_name>" << std::endl;
		return (1);
	}
(void)av;
	BitcoinExchange exchange;
	// exchange.printData(exchange.getPriceData());
	exchange.calculate(av[1]);


	return (0);
}


