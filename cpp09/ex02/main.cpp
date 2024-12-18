#include "PmergeMe.hpp"
#include "utils.hpp"

int	main(int ac, char *av[])
{
	if (ac < 2) {
		std::cout << "Usage: ./PmergeMe <int> <int> ... <int>" << std::endl;
		return (1);
	}

	try {
		PmergeMe	m;
		m.fillData(av, LIST);
		m.print(LIST);



	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
