#include "PmergeMe.hpp"

int	main(int ac, char *av[])
{
	if (ac < 2) {
		std::cout << "Usage: ./PmergeMe <int> <int> ... <int>" << std::endl;
		return (1);
	}

	try {
		PmergeMe	m(av);
		m.print(m.getList());
		std::cout << "Size: " << m.getSize() << std::endl;
		m.FJA(m.getList());

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
