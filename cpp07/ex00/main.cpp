#include <iostream>
#include "whatever.hpp"

int	main( void ) {

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << "--------------------------" << std::endl;
	a = 3;
	b = 3;
	if (&(::min( a, b )) == &b)
		std::cout << "min<int> returns the second one." << std::endl;
	if (&(::max( a, b )) == &b)
		std::cout << "max<int> returns the second one." << std::endl;

	std::cout << "--------------------------" << std::endl;
	c = "chaine1";
	d = "chaine1";
	if (&(::min( c, d )) == &d)
		std::cout << "min<std::string> returns the second one." << std::endl;
	if (&(::max( c, d )) == &d)
		std::cout << "max<std::string> returns the second one." << std::endl;
	
	return (0);
}
