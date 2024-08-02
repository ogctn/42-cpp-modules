#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <sstream>

template <typename T>
class Array {
	private:
		T 		*_arr;
		size_t	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(unsigned int n, T val);
		Array(const Array &);
		~Array();
		Array &operator=(const Array &);

		T &operator[](unsigned int);

		size_t	size() const;
		void	setElement(unsigned int, T);
		T		getElement(unsigned int) const ;
		
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Array<T> &src);

# include <Array.tpp>

#endif
