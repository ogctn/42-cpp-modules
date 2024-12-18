#include "PmergeMe.hpp"
#include "utils.hpp"

PmergeMe::PmergeMe() {}

void	PmergeMe::pushPair(int val1, int val2, bool flag) {
	if (flag == LIST) {
		_list_first.push_back(val1);
		_list_second.push_back(val2);
	}
	else {
		_deque_first.push_back(val1);
		_deque_second.push_back(val2);
	}
}

void	PmergeMe::fillData(char *av[], bool flag) {
	int first, second, i;

	for (i = 1; av[i] != NULL && av[i + 1] != NULL; i += 2) {
		first = my_stoi(av[i]);
		second = my_stoi(av[i+1]);
		if (second < first)
			std::swap(second, first);
		pushPair(first, second, flag);
	}
	if (av[i]) {
		second = my_stoi(av[i]);
		if (flag == LIST)
			_list_second.push_back(second);
		else
			_deque_second.push_back(second);
	}
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	if (this != &src) {
		_list_first = src._list_first;
		_deque_first = src._deque_first;
		_list_second = src._list_second;
		_deque_second = src._deque_second;
	}
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) {
	_list_first = src._list_first;
		_deque_first = src._deque_first;
		_list_second = src._list_second;
		_deque_second = src._deque_second;
	}
	return (*this);
}




