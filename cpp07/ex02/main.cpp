#include <Array.hpp>
#include <iostream>

int	main() {
	Array<int> i1(4), i2(2, 15);
	
	std::string str("ogcetin");
	Array<std::string> s1(3), s2(3, str);

	std::cout << i1 << std::endl;
	std::cout << i2 << std::endl;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << "---------------------------" << std::endl;
	i1 = i2;
	std::cout << i1 << std::endl;

}
