#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_idx = 0;
}

PhoneBook::~PhoneBook()
{
}

static bool	is_all_space(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!isspace(str[i]))
			return (0);
	}
	return (1);
}

void	PhoneBook::add()
{
	std::string	buff;

	buff = "";
	while (!std::cin.eof())
	{
		std::cout << "[+] Enter first name: ";
		if (std::getline(std::cin, buff) && buff != "" && !is_all_space(buff))
		{
			this->_contacts[this->_idx].set_first_name(buff);
			break;
		}
	}

	while (!std::cin.eof())
	{
		std::cout << "[+] Enter last name: ";
		if (std::getline(std::cin, buff) && buff != "" && !is_all_space(buff))
		{
			this->_contacts[this->_idx].set_last_name(buff);
			break;
		}
	}

	while (!std::cin.eof())
	{
		std::cout << "[+] Enter nick name: ";
		if (std::getline(std::cin, buff) && buff != "" && !is_all_space(buff))
		{
			this->_contacts[this->_idx].set_nick_name(buff);
			break;
		}
	}

	while (!std::cin.eof())
	{
		std::cout << "[+] Enter phone number: ";
		if (std::getline(std::cin, buff) && buff != "" && !is_all_space(buff))
		{
			this->_contacts[this->_idx].set_phone_number(buff);
			break;
		}
	}

	while (!std::cin.eof())
	{
		std::cout << "[+] Enter darkest secret ^-^ : ";
		if (std::getline(std::cin, buff) && buff != "" && !is_all_space(buff))
		{
			this->_contacts[this->_idx].set_darkest_secret(buff);
			break;
		}
	}
	if (!std::cin.eof())
	{
		std::cout << "-> Contact " << this->_contacts[this->_idx].get_first_name() << " added succesfully!" << std::endl << std::endl;
		this->_idx = (this->_idx + 1) % 8;
	}
	else
		std::cout << std::endl << "The world is very quiet without you around." << std::endl;
}

static std::string	do_trim(std::string raw)
{
	size_t	startPos = 0;

    while (startPos < raw.length() && std::isspace(raw[startPos]))
		startPos++;
	if (startPos > 0)
		raw.erase(0, startPos);

	if (raw.length() > 10)
	{
		raw.resize(9);
		raw.resize(10, '.');
	}
	return (raw);
}

void	print_search_line(Contact contact)
{
	std::cout << std::setw(10) << do_trim(contact.get_first_name()) << "|" << std::setw(10) << do_trim(contact.get_last_name())
				<< "|" << std::setw(10) << do_trim(contact.get_nick_name()) << "|" << std::endl;
}

static void	display_contact(Contact c)
{
	if (!c.get_first_name().length())
	{
		std::cout << "[X] Empty Contact." << std::endl;
		return;
	}
	std::cout << std::endl << "Calling Contact -> " << c.get_first_name() << "..." << std::endl << std::endl;
	std::cout << "First Name: " << c.get_first_name() << std::endl;
	std::cout << "Last Name: " << c.get_last_name() << std::endl;
	std::cout << "Nick Name: " << c.get_nick_name() << std::endl;
	std::cout << "Phone Number: " << c.get_phone_number() << std::endl;
	std::cout << "Darkest Secret: " << c.get_darkest_secret() << std::endl << std::endl;
}

void	PhoneBook::search() const
{

	if (this->_contacts[0].get_first_name().empty())
	{	
		std::cout << "Phone book is empty" << std::endl;
		return;
	}
	std::cout << std::endl;
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (this->_contacts[i].get_first_name().empty())
				break;
		std::cout << std::setw(10) << i << "|";
		print_search_line(this->_contacts[i]);
	}

	std::string	buff;

	while (!std::cin.eof())
	{
		std::cout << std::endl << "[?] Enter index [0 - 7] to see details : ";
		if (std::getline(std::cin, buff) && buff != "" && !is_all_space(buff) && buff[0] >= '0' && buff[0] <= '7')
		{
			display_contact(this->_contacts[atoi(buff.c_str())]);
			break;
		}
		else if (!(buff[0] >= '0' && buff[0] <= '7'))
		{
			std::cout << "[X] Enter index in range of [0 - 7]" << std::endl;
			continue;
		}
	}
	if (std::cin.eof())
		std::cout << std::endl << "You don’t cross my mind, you live in it." << std::endl;
}
