#include <iostream>
#include "iter.hpp"

class Awesome {
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }


void my_toupper(std::string &s);
void stringLower(std::string &s);


int	main() {

	int i_arr[5] = {1,2,3,4,5};
	const int arr_size = sizeof(i_arr) / sizeof(i_arr[0]);

	const unsigned int increment = 10;

	std::cout << "--------------------> 0" << std::endl;
	void (*f_null)(int &e) = NULL;
	iter(i_arr, arr_size, f_null);
	print_arr(i_arr, arr_size);
	std::cout << "--------------------> 1" << std::endl;
	s_fun<int, increment> f_i;
	iter(i_arr, arr_size, f_i);	// iter<s_fun, int, 10>(i_arr, size, f_i);
	print_arr(i_arr, arr_size);
	
	std::cout << "--------------------> 2" << std::endl;
	iter(i_arr, arr_size, s_fun<int, increment>());	// iter<s_fun, int, 10>(i_arr, size, s_fun<int, increment>())
	print_arr(i_arr, arr_size);

	std::cout << "--------------------> 3" << std::endl;
	std::string s_arr[5] = {"Lorem Ipsum", "is", "simply", "dummy", "text"};
	const int s_size = sizeof(s_arr)/sizeof(s_arr[0]);
	iter(s_arr, s_size, my_toupper);
	print_arr(s_arr, s_size);

	std::cout << "--------------------> 4" << std::endl;
	print_arr(s_arr, s_size);
	for (size_t i = 0; i < s_size; i++)
		iter(s_arr, 2, stringLower);
	print_arr(s_arr, s_size);
	
	std::cout << "--------------------> 5" << std::endl;
	iter(&s_arr[2], 2, print);

	std::cout << "--------------------> EVO TEST" << std::endl;
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];

	iter( tab, 5, print );
	iter( tab2, 5, print );
	std::cout << "------------------" << std::endl;

	return (0);
}
