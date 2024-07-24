#include <iostream>
// #include <<string>>


int main(){
	std::string f = "3f.4f";

	double i = std::stod("53.6");
	std::cout << i << std::endl;
	std::cout << static_cast<int>(i) << std::endl;
	std::cout << static_cast<double>(i) << std::endl;
	std::cout << static_cast<float>(i) << std::endl;

}
