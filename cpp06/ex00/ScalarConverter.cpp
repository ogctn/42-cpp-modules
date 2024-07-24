#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()  {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	if (this != &other)
		*this = other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

const char*	ScalarConverter::BadInputException::what() const throw() {
	return ("Error: Bad input: ");
}

specials get_type(const std::string &input) {
	if (input == "inf" || input == "+inf" ||
			input == "inff" || input == "+inff")
		return (my_inf);
	else if (input == "-inf" || input == "-inff")
		return (my_minus_inf);
	else if (input == "nan" || input == "nanf")
		return (my_nan);
	else
		return (smt_else);
}

int countChar(const std::string &str, char c) {
	int count = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == c) {
            count++;
        }
    }
    return (count);
}

int check_valid_numbers(const std::string &str) {
	for (int i = 0; i < str.length(); ++i) {
        if (str[i] != 'f' || str[i] != '.' || str[i] != '-' || str[i] != '+' || !std::isdigit(str[i]))
			return (1);
    }
	return (0);
}

void check_format(const std::string &input) {
	if (input.length() == 1 && !std::isdigit(input[0]))
		throw ScalarConverter::BadInputException();
	if (check_valid_numbers(input))
		throw ScalarConverter::BadInputException();
	if ((countChar(input, '.') > 1 || countChar(input, 'f') > 1))
		throw ScalarConverter::BadInputException();
	if (input.find('f') != input.length() - 1)
		throw ScalarConverter::BadInputException();
	if (input.find('f') + input.find('.') == 1)
		throw ScalarConverter::BadInputException();
	if (input.find('.') == 0 && !std::isdigit(input.at(1)))
		throw ScalarConverter::BadInputException();
	if (input.find('f') != f.npos && input.find('.') == input.length() - 2 && input.length() < 3)
		throw ScalarConverter::BadInputException();
}

int check_infNan(const std::string &input) {
	switch (get_type(input)) {
		case my_inf:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: inff" << std::endl;
			std::cout << "double: inf" << std::endl;
			break;

		case my_minus_inf:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
			break;

		case my_nan:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			break;

		case smt_else:
			return (0);
	}
	return (1);
}

void print_char(std::string input, float *val) {
	if (input.length() == 1 && !std::isdigit(input))
		std::cout << "char: " << static_cast<char>(input[0]) << std::endl;
	else if (input.length() == 1 && std::isdigit(input))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
}

void print_int(std::string input) {
	try {
		int i = std::stoi(input);
	} catch (std::exception &e) {
		std::cout << "int: impossible" << std::endl;
		return;
	}
	std::cout << "int: " << static_cast<int>(i) << std::endl;
}

void print_float(std::string input) {
	
}

void print_double(std::string input) {
	
}

std::string get_modied_input(std::string &input) {
	std::string tmp = input;

	if (tmp.length == 1 && std::isdigit(tmp[0]))
		return;
	if (tmp.find('f') != tmp.npos)
		tmp.erase(tmp.find('f'));
	if (tmp.find('.') == 0)
		tmp.insert(0, "0");
	if (tmp.find('.') == tmp.length() - 1)
		tmp.erase(tmp.find('.'));
	return (tmp);
}

void ScalarConverter::convert(std::string input) {
	try {
		check_format(input) 
	} catch (ScalarConverter::BadInputException &e) {
		std::cerr << e.what() << input << std::endl;
		return;
	}
	if (check_infNan(input))
		return;

	std::string tmp = get_modied_input(input);


	
}


/*
Neler gelebilir 
- inf
- -inf
- nan
- char gelebilir
- int gelebilir
- float gelebilir
- double gelebilir

float ve doublue ayıran şey .f dir.



*/
