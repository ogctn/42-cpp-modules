#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <sstream>

// https://cplusplus.com/reference/deque/deque/
// https://en.cppreference.com/w/cpp/container/deque/begin

// template <typename _Tp> stack; 	with defaul deque container type
// template <typename _Tp, typename _Container = deque< _Tp> > stack;
template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack();
		MutantStack(const MutantStack &);
		MutantStack &operator=(const MutantStack &);
		virtual	~MutantStack();

		typedef typename std::deque<T>							container_type;
		typedef typename container_type::iterator				iterator;
		typedef typename container_type::const_iterator			const_iterator;
		typedef typename container_type::reverse_iterator		reverse_iterator;
		typedef typename container_type::const_reverse_iterator	const_reverse_iterator;

		iterator 		begin();
		const_iterator	cbegin() const;
		iterator 		end();
		const_iterator	cend() const;

		reverse_iterator		rbegin();
		const_reverse_iterator	crbegin() const;
		reverse_iterator 		rend();
		const_reverse_iterator	crend() const;

};

template <typename T>
std::ostream &operator<<(std::ostream &os, const MutantStack<T> &);


# include "MutantStack.tpp"

#endif
