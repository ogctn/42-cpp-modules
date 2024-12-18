#include "RPN.hpp"

#include <iostream>

int main (int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: ./rpn \"RPN expression\"" << std::endl;
		return 1;
	}

	std::string str;
	for (int i = 1; av[i]; i++)
	{
		str += av[i];
		if (av[i+1])
			str += " ";
	}

	if (str.empty())
	{
		std::cerr << "Usage: ./rpn \"RPN expression\"" << std::endl;
		return 1;
	}

	try {
		RPN rpn(str);
		rpn.calculate();
		rpn.printResult();
	} catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
