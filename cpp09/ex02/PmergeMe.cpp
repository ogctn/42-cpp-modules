#include "PmergeMe.hpp"
#include "utils.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **av) : _av(av) {
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	if (this != &src) {
		_listA = src._listA;
		_dequeA = src._dequeA;
		_listB = src._listB;
		_dequeB = src._dequeB;
	}
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) {
		_listA = src._listA;
		_dequeA = src._dequeA;
		_listB = src._listB;
		_dequeB = src._dequeB;
	}
	return (*this);
}

void	PmergeMe::print(bool c_type) {

	std::cout << "After: ";
	if (c_type == LIST) {
		for (std::list<int>::iterator it = _listA.begin(); it != _listA.end(); it++)
			std::cout << *it << " ";
	}
	else {
		for (std::deque<int>::iterator it = _dequeA.begin(); it != _dequeA.end(); it++)
			std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::runList() {
	
	size_t n;

	fillContainer(_listA, _listB, _av);
	n = _listB.size();
	if (n == 0)
		return;
	_listA.sort();
	_listB.sort();
	insertionSort(_listA, _listB);	
}

void PmergeMe::runDeque() {
	
	size_t n;
	
	fillContainer(_dequeA, _dequeB, _av);
	n = _dequeB.size();
	if (n == 0)
		return;
	std::sort(_dequeA.begin(), _dequeA.end());
	std::sort(_dequeB.begin(), _dequeB.end());
	insertionSort(_dequeA, _dequeB);	
}
