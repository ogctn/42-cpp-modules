#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src) { *this = src; }

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src) {
	if ( this != &src)
		std::stack<T>::operator=(src);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() { return (this->c.begin()); }

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cbegin() const { return (this->c.cbegin()); }

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() { return (this->c.end()); }

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cend() const { return (this->c.cend()); }

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rbegin() { return (this->c.rbegin()); }

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crbegin() const { return (this->c.crbegin()); }

template <typename T>
typename MutantStack<T>::reverse_iterator	MutantStack<T>::rend() { return (this->c.rend()); }

template <typename T>
typename MutantStack<T>::const_reverse_iterator	MutantStack<T>::crend() const { return (this->c.crend()); }

template <typename T>
std::ostream &operator<<(std::ostream &os, const MutantStack<T> &src) {
	std::ostringstream ss;
	MutantStack<T> tmp(src);
	os << "[";
	if (tmp.size() > 0)
	{
		for (typename MutantStack<T>::const_iterator it = tmp.begin(); it != tmp.cend(); it++) {
			ss << " ";
			ss << *it;
		}
		os << ss.str();
	}
	os << " ]";
	return (os);
}
