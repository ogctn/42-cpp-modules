#include "BitcoinExchange.hpp"
template <typename T>
T	_stoval(const std::string &from) {
	std::stringstream ss(from);
	
	T converted;
	ss >> converted;
	return (converted);
}
template <typename T>
std::string _to_str(const T &n) {
	std::stringstream ss;

	ss << n;
	return (ss.str().c_str());
}
int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "usage: ./bitcoin <file_name>" << std::endl;
		return (1);
	}

	BitcoinExchange exchange;
	exchange.calculate(av[1]);
	// exchange.printData(exchange.getResult());

	return (0);
}

