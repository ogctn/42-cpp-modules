#include "PmergeMe.hpp"

void prinBefore(char **av);
void printAfter(std::list<int> &list);


int	main(int ac, char **av)
{
	if (ac < 2) {
		std::cout << "Usage: ./PmergeMe <int> <int> ... <int>" << std::endl;
		return (1);
	}

	try {
		PmergeMe	m(av);
		prinBefore(av);
		m.runList();
		printAfter(m.getListA());
		std::cout << "Time to sort elements using  std::list : " << measureTime(&PmergeMe::runList, m)  << " us." << std::endl;
		std::cout << "Time to sort elements using std::deque : " << measureTime(&PmergeMe::runDeque, m) << " us." << std::endl;

	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}


void prinBefore(char **av) {
	
	std::cout << "Before: ";
	for (int i = 1; av[i] && i < 5; i++) {
		std::cout << av[i] << " ";
	}
	if (av[5])
		std::cout << " [...]";
	std::cout << std::endl;
}

void printAfter(std::list<int> &list) {

	std::cout << "After : ";
	std::list<int>::iterator it = list.begin();
	for (int i = 0; i < 5 && it != list.end(); i++, it++) {
		std::cout << *it << " ";
	}
	if (it != list.end())
		std::cout << " [...]";
	std::cout << std::endl;
}
