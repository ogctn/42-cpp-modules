#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "usage: ./bitcoin <file_name>" << std::endl;
		return (1);
	}


	BitcoinExchange exchange;

	exchange.printData(exchange.getPriceData());
	std::cout << "--------PRICE ENDS--------" << std::endl;
	exchange.calculate(av[1]);
	exchange.printData(exchange.getInput());
	std::cout << "--------INPUT ENDS--------" << std::endl;
	exchange.getResult();
	std::cout << "--------RESULT ENDS--------" << std::endl;

	return (0);
}


