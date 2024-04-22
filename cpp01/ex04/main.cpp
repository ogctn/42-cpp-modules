#include <iostream>
#include <fstream>
#include <string>

#include "Sed.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	std::string in(argv[1]);
	std::string from(argv[2]);
	std::string to(argv[3]);

	Sed s = Sed(in, from, to);

	return(s.operate());
}
