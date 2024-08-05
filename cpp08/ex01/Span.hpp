#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
# include <deque>
# include <algorithm>
# include <exception>
# include <cstdlib>	// srand()
# include <time.h>	// time()

class Span {
	private:
		Span();
		Span(const Span &);

	public:
		Span(unsigned int);
		Span	&operator=(const Span &);
		~Span();

	private:
		std::deque<int>	_data;
		unsigned int	_capacity;

	public:
		void	addNumber();
		void	addNumber(int val);
		void	addNumber(std::deque<int>::iterator it);
		void	addNumber(std::deque<int>::iterator it, int val);
	
		int		shortestSpan() const;
		int		longestSpan() const;
		
		void	addMany(unsigned int n);
		void	addMany(unsigned int n, int val);
		void	addMany(std::deque<int>::iterator it, unsigned int n);
		void	addMany(std::deque<int>::iterator it, unsigned int n, int val);
		void	addMany(std::deque<int>::iterator it, const std::deque<int> &copy);
		void	addMany(std::deque<int>::iterator it,
					std::deque<int>::iterator begin, std::deque<int>::iterator end);
		void	addMany(std::deque<int>::iterator it, Span &copy);
		void	addMany(std::deque<int>::iterator it, Span &copy, unsigned int pos, unsigned int len);

		std::deque<int> &getData();
		unsigned int getCap() const;
		unsigned int getSize() const;

		std::deque<int>::iterator begin();
		std::deque<int>::iterator at(unsigned int n);
		std::deque<int>::iterator at(std::deque<int> &src, unsigned int n);
		std::deque<int>::iterator end();
		
		void print() const;
		void print(std::string s) const;

		class NoSpaceException : public std::exception {
			virtual const char* what() const _NOEXCEPT;
		};
		class OutOfRangeException : public std::exception {
			virtual const char* what() const _NOEXCEPT;
		};
		class TooFewElementsException : public std::exception {
			virtual const char* what() const _NOEXCEPT;
		};

};

#endif
