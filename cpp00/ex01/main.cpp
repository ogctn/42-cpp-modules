#include "PhoneBook.hpp"

int main()
{
	PhoneBook	pb;
	std::string	buff;

	std::cout << std::endl << "------------------------------" << std::endl;
	std::cout << "Hi there, I'm using WhatsApp !" << std::endl;
	std::cout << "------------------------------" << std::endl << std::endl;

	buff = "";
	while (!std::cin.eof())
	{
		std::cout << "[ ADD - SEARCH - EXIT ] Please enter a command : ";
		std::getline(std::cin, buff);
		if (buff == "EXIT")
			return (0);
		else if (buff == "ADD")
			pb.add();
		else if (buff == "SEARCH")
			pb.search();
		else if (!std::cin.eof())
			std::cout << "[X] Bad input, available options: ADD, SEARCH, EXIT " << std::endl;
		else
			std::cout << std::endl << "As long as we share the same sky and breathe the same air, we’re still together." << std::endl;
	}
}
