#include <Array.hpp>

template <typename T>
Array<T>::Array() : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _arr(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(unsigned int n, T val) : _arr(new T[n]), _size(n) {
	for (size_t i = 0; i < _size; i++)
		_arr[i] = val;
}

template <typename T>
Array<T>::Array(const Array & src) : _arr(src._arr), _size(src._size) {
	if (this != &src) {
		_arr = new T[_size];
	for (size_t i = 0; i < _size; i++)
		_arr[i] = src._arr[i];
	}
}

template <typename T>
Array<T>::~Array() {
	if (_arr)
		delete []_arr;
	_arr = NULL;	
}

template <typename T>
Array<T>	&Array<T>::operator=(const Array &src) {
	if (this == &src)
		return (*this);
	if (_arr)
		delete []_arr;
	_size = src._size;
	_arr = new T[_size];
	for (size_t i = 0; i < _size; i++)
		_arr[i] = src._arr[i];
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int idx) {
	if (idx >= _size)
		throw (std::exception());
	return (_arr[idx]);
}

template <typename T>
const T	&Array<T>::operator[](unsigned int idx) const {
	if (idx >= _size)
		throw (std::exception());
	return (_arr[idx]);
}

template <typename T>
size_t	Array<T>::size() const {
	return (_size);
}

template <typename T>
std::ostream	&operator<<(std::ostream &os, const Array<T> &src) {
	std::ostringstream ss;
	os << "[";
	if (src.size() > 0)
	{
		for (size_t i = 0; i < src.size(); i++) {
			ss << src[i];
			if (i < src.size() - 1)
				ss << ", ";
		}
		os << ss.str();
	}
	os << "]";
	return (os);
} 
