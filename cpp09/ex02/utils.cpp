#include "utils.hpp"

bool	isOnlyDigits(const char *str) {
	if (!str)
		return (false);
	while (*str) {
		if (!std::isdigit(*str))
			return (false);
		++str;
	}
	return (true);
}

int my_stoi(const std::string& str) {
    
	std::stringstream	ss(str);
    int					result;

    ss >> result;
    if (ss.fail() || !ss.eof()) {
        throw std::invalid_argument("Invalid format.");
    }

    if (result < std::numeric_limits<int>::min() || result > std::numeric_limits<int>::max()) {
        throw std::out_of_range("Out of int limits.");
    }

    return (result);
}

void	PmergeMe::print(bool flag) {

	if (flag == LIST) {
		std::cout << "LIST : " << std::endl;
		std::list<int>::iterator it;
		std::cout << "List First: ";
		for (it = _list_first.begin(); it != _list_first.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "List Second: ";
		for (it = _list_second.begin(); it != _list_second.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	else {
		std::cout << "DEQUE: ";
		std::deque<int>::iterator it;
		std::cout << "deque First: ";
		for (it = _deque_first.begin(); it != _deque_first.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "deque Second: ";
		for (it = _deque_second.begin(); it != _deque_second.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
}

void	PmergeMe::print() {
	print(LIST);
	print(DEQUE);
}

long jacobsthal(int n) {
    return (long(round((pow(2, n) + pow(-1, n - 1)) / 3)));
}

