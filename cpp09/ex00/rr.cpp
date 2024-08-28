#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>


template <typename From, typename To>
To	_converter(const From &from) {
	std::stringstream ss(from);
	
	To converted;
	ss >> converted;
	if (ss.fail())
		throw std::invalid_argument("Invalid argument");
	return (converted);
}


int main() {

	std::string str = "-12.4f";
	float f;
	try {
		f = _converter<std::string, float>(str);
		std::cout << f << std::endl;
	} catch (std::invalid_argument &e) {
		std::cerr << e.what() << std::endl;
	}


	return 0;
}
