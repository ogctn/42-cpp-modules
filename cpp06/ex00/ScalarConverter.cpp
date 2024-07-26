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

const char*	BadInputException::what() const throw() {
	return ("Error: Bad input: ");
}

specials get_type(const std::string &input) {
	if (input == "inf" || input == "+inf" ||
			input == "inff" || input == "+inff")
		return (my_inf);
	else if (input == "-inf" || input == "-inff")
		return (my_minus_inf);
	else if (input == "nan" || input == "nanf")
		return (my_nan);
	else
		return (smt_else);
}

void check_format(const std::string &input) {
	short int dot = 0;

	if (input.find_first_not_of("0123456789.f+-") == input.npos)
		if (input.length() == 1 && std::isalpha(input[0]))
			throw BadInputException();
	if (input.find_first_not_of(".f+-") == input.npos)
		throw BadInputException();

	for (size_t i = 0; i < input.length(); ++i) {
		if (input[i] == '+' || input[i] == '-'){
			if (input.length() == 1)
				throw BadInputException();
			if (i != 0)
				throw BadInputException();
			continue;
		}
		if (input[i] == '.') {
			if (input.length() == 1)
				throw BadInputException();
			if (++dot > 1)
				throw BadInputException();
			if (input[i + 1] == 'f' && i != 0 && !std::isdigit(input[i - 1]))
				throw BadInputException();
			continue;
		}
		if (input[i] == 'f') {
			if (input.length() == 1)
				throw BadInputException();
			if (input.length() - 1 != i)
				throw BadInputException();
			if (input.length() == 2 && !std::isdigit(input[0]))
				throw BadInputException();
			continue;
		}
		continue;
	}
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

void print_all(std::string s_val) {
	double d_val = strtod(s_val.c_str(), NULL);

	std::cout << "char: ";
	std::cout << "######" << s_val << d_val <<  "######" << std::endl;
	if (!std::isprint(static_cast<unsigned char>(d_val)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(static_cast<int>(d_val)) << "'" << std::endl;

	std::cout << "int: ";
	if (d_val > std::numeric_limits<int>::max() || d_val < std::numeric_limits<double>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d_val) << std::endl;

	std::cout << "float: ";
	if (d_val > std::numeric_limits<float>::max() || d_val < std::numeric_limits<float>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(d_val) << "f" << std::endl;
	
	std::cout << "double: ";
	if (d_val > std::numeric_limits<double>::max() || d_val < std::numeric_limits<double>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<float>(d_val) << std::endl;
}

#include <string>
std::string get_modied_input(std::string &input) {
	std::string tmp = input;

	if (tmp.length() == 1 && std::isdigit(tmp[0])) {
		std::stringstream ss(tmp);
		return (ss.str());
	}
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
		check_format(input);
	} catch (std::exception &e) {
		std::cout << e.what() << input << std::endl;
		return;
	}
	if (check_infNan(input))
		return;
	
	std::string s_val = get_modied_input(input);
	print_all(s_val);
}
