#include <iostream>
// #include <<string>>
#include <cstdlib>


#include <sstream>
int main(){
	std::string s = "f.f";
	std::string s1 = "B";

	std::stringstream ss(s1);

	std::cout << std::string(ss.str())  << std::endl;
	
	std::cout << "--------" + (s.find_first_not_of(".f+-")==s.npos) << std::endl;

	std::string in = "A";
	std::cout << std::to_string(static_cast<int>(in[0])) << std::endl;
	std::cout << std::to_string(in[0]) << std::endl;

double a = strtod("a", NULL);
	std::cout << a << std::endl;
	 a = strtod("--42.0f", NULL);
	std::cout << a << std::endl;
	
	double b = -65.4;
	
	std::cout << static_cast<char>( static_cast<unsigned int>(b) ) << std::endl;
	// double i = std::stod("++6.f");
//std::cout << static_cast<char>(strtod("-42.0f", NULL)) << std::endl;
	// std::cout << static_cast<int>(i) << std::endl;
	// std::cout << static_cast<double>(i) << std::endl;
	// std::cout << static_cast<float>(i) << std::endl;

}
