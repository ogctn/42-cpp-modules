#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2 || (argv[1][0] == '\0')) {
		std::cout << "Usage: ./convert [value]" << std::endl;
		return (1);
	}
	else {
		ScalarConverter::convert(argv[1]);
		return (0);
	}
}
