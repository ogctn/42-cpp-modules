#include "Span.hpp"

#define MAX_VAL 100

// RAND() returns a number in the range of [ -MAX_VAL MAX_VAL ]
#define RAND() ((rand() % (2 * MAX_VAL + 1)) - MAX_VAL)

Span::Span() : _capacity(0){ srand(time(NULL)); }

Span::Span(const Span &other) { *this = other; srand(time(NULL)); }

Span::~Span() {}

Span::Span(unsigned int N) : _capacity(N) { srand(time(NULL)); }

Span	&Span::operator=(const Span &other) {
	srand(time(NULL));
	if (this != &other) {
		_data = other._data;
		_capacity = other._capacity;
	}
	return (*this);
}

void	Span::addNumber() {
	try {
		if (getSize() + 1 > _capacity)
			throw(NoSpaceException());
		
		_data.push_back(RAND());

	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
}

void	Span::addNumber(int val) {
	try {
		if (getSize() + 1 > _capacity)
			throw(NoSpaceException());

		_data.push_back(val);

	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
}

void	Span::addNumber(std::deque<int>::iterator it) {
	try {
		if (getSize() + 1 > _capacity)
			throw(NoSpaceException());
		if (it < begin() || it > end())
			throw(OutOfRangeException());

		_data.insert(it, RAND());

	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
}

void	Span::addNumber(std::deque<int>::iterator it, int val) {
	try {
		if (getSize() + 1 > _capacity)
			throw(NoSpaceException());
		if (it < begin() || it > end())
			throw(OutOfRangeException());

		_data.insert(it, val);

	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
}

void	Span::addMany(unsigned int n, int val) {
	try {
		if (getSize() + n > _capacity)
            throw(NoSpaceException());
		for (unsigned int i = 0; i < n; i++)
			_data.push_back(val);
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
}

void	Span::addMany(unsigned int n) {
	try {
		if (getSize() + n > _capacity)
            throw(NoSpaceException());
		for (unsigned int i = 0; i < n; i++)
			_data.push_back(RAND());
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
}


void	Span::addMany(std::deque<int>::iterator it, unsigned int n) {
	try {
		if (getSize() + n > _capacity)
            throw(NoSpaceException());
		if (it < begin() || it > end())
			throw(OutOfRangeException());
		
		std::deque<int> tmp;
		for (unsigned int i = 0; i < n; i++)
			tmp.push_back(RAND());
		_data.insert(it, tmp.begin(), tmp.end());

	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
}

void	Span::addMany(std::deque<int>::iterator it, unsigned int n, int val) {
	try {
		if (getSize() + n > _capacity)
            throw(NoSpaceException());
		if (it < begin() || it > end())
			throw(OutOfRangeException());

		_data.insert(it, n, val);

	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
}

void	Span::addMany(std::deque<int>::iterator it, const std::deque<int> &copy) {
    try {
        if (getSize() + copy.size() > _capacity)
            throw(NoSpaceException());
        if (it < begin() || it > end())
            throw(OutOfRangeException());

        _data.insert(it, copy.begin(), copy.end());

    } catch (std::exception &e) { std::cout << e.what() << std::endl; }
}

void	Span::addMany(std::deque<int>::iterator it_this, 
			std::deque<int>::iterator begin_other, std::deque<int>::iterator end_other) {
	try {
		if (begin_other > end_other)
            throw(OutOfRangeException());
		if (getSize() + std::distance(begin_other, end_other) > _capacity)
            throw(NoSpaceException());
        if (it_this < begin() || it_this > end())
            throw(OutOfRangeException());

        _data.insert(it_this, begin_other, end_other);

    } catch (std::exception &e) { std::cout << e.what() << std::endl; }
}

void	Span::addMany(std::deque<int>::iterator it, Span &copy) {
    try {
        if (getSize() + copy.getSize() > _capacity)
            throw(NoSpaceException());
        if (it < begin() || it > end())
            throw(OutOfRangeException());

        _data.insert(it, copy.begin(), copy.end());

    } catch (std::exception &e) { std::cout << e.what() << std::endl; }
}

void	Span::addMany(std::deque<int>::iterator it, Span &copy, unsigned int idx, unsigned int len) {
	try {
		if (len > copy.getSize() - idx)
            throw(OutOfRangeException());
		if (idx > copy.getSize())
            throw(OutOfRangeException());
        if (getSize() + len > _capacity)
            throw(NoSpaceException());
        if (it < begin() || it > end())
            throw(OutOfRangeException());

		std::deque<int> tmp;
		tmp.insert(tmp.begin(), copy.at(idx), copy.at(idx + len));

		_data.insert(it, tmp.begin(), tmp.end());

    } catch (std::exception &e) { std::cout << e.what() << std::endl; }
}

int		Span::shortestSpan() const {
	if (getSize() < 2)
		throw (TooFewElementsException());
	
	int shortest = std::numeric_limits<int>::max();
	std::deque<int> tmp = _data;
	std::sort(tmp.begin(), tmp.end());

	std::deque<int>::const_iterator prev = tmp.begin();
	for (std::deque<int>::const_iterator it = tmp.begin()+1; it != tmp.end(); prev = it, ++it)
		if (*it - *prev < shortest)
			shortest = *it - *prev;
	return (shortest);
}

int		Span::longestSpan() const {
	if (getSize() < 2)
		throw (TooFewElementsException());
	
	std::deque<int> tmp = _data;
	std::sort(tmp.begin(), tmp.end());
	return (tmp.back() - tmp.front());
}


std::deque<int> &Span::getData() { return(_data); }
unsigned int	Span::getCap() const { return (_capacity); }
unsigned int	Span::getSize() const { return (_data.size()); }
std::deque<int>::iterator Span::begin() { return (_data.begin()); }


std::deque<int>::iterator Span::at(unsigned int n) {
	try{
		if (n >= _data.size())
        	throw (OutOfRangeException());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (_data.end());
	}
	return (_data.begin() + n);
}

std::deque<int>::iterator Span::at(std::deque<int> &src, unsigned int n) {
	try{
		if (n >= src.size())
        	throw (OutOfRangeException());
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return (src.end());
	}
	return (src.begin() + n);
}


std::deque<int>::iterator Span::end() { return (_data.end()); }

void Span::print() const {
    std::cout << "{ ";
	for (std::deque<int>::const_iterator it = _data.begin(); it != _data.end(); ++it) {
        std::cout << *it;
		if (it + 1 != _data.end())
			std::cout << ", ";
    }
    std::cout << " }" << std::endl;
}

void Span::print(std::string s) const {
	std::cout << s + ": ";
	print();
}

const char *Span::NoSpaceException::what() const throw() {
	return ("No space left ");
}

const char *Span::OutOfRangeException::what() const throw() {
	return ("iterator: out of range ");
}

const char *Span::TooFewElementsException::what() const throw() {
	return ("at least 2 elements required ");
}
