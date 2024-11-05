#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _size(0) {}

void	PmergeMe::pushPair(int val1, int val2) {
	_list.push_back(std::make_pair(val1, val2));
	_deque.push_back(std::make_pair(val1, val2));
}

void	PmergeMe::fillData(char *av[]) {
	int	left, right;

	++av;
	while(av && *av) {
		if (!isOnlyDigits(*av))
			throw std::invalid_argument("Invalid argument: \'" + std::string(*av) + "\' not a valid number");
		try {
			std::stoi(*av);
		} catch (std::exception &e) {
			throw std::invalid_argument("Invalid argument: \'NULL\' not a valid number");
		}

		if (_size % 2 == 0)
			left = std::stoi(*av);
		else {
			right = std::stoi(*av);
			pushPair(left, right);
		}
		++_size;
		++av;
	}
	if (_size % 2 == 1)
		pushPair(left, -1);
}

PmergeMe::PmergeMe(char *av[]) : _size(0) { fillData(av); }

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {
	if (this != &src) {
		_list = src._list;
		_deque = src._deque;
		_size = src._size;
	}
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	if (this != &src) {
		_list = src._list;
		_deque = src._deque;
		_size = src._size;
	}
	return *this;
}

std::list< std::pair<int,int> >	&PmergeMe::getList() { return _list; }
std::deque< std::pair<int,int> >	&PmergeMe::getDeque() { return _deque; }
size_t			PmergeMe::getSize() { return _size; }


