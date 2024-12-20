#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << "Usage: ./PmergeMe <int> <int> ... <int>" << std::endl;
		return (1);
	}

	try {
		PmergeMe	m(av);
		std::cout << "Time to sort elements using  std::list : " << measureTime(&PmergeMe::runList, m)  << " us." << std::endl;
		std::cout << "Time to sort elements using std::deque : " << measureTime(&PmergeMe::runDeque, m) << " us." << std::endl;
		m.print(LIST);

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
