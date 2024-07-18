#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main() {
	Bureaucrat b1("ogcetin", 1);
	Bureaucrat b2("taybakan", 75);
	Bureaucrat b3("tnoyan", 150);

	PresidentialPardonForm pf1("target1");
	RobotomyRequestForm rf1("target2");
	ShrubberyCreationForm sf1("target1");
	ShrubberyCreationForm sf2("target2");

	std::cout << b1 << "  |  " << b2 << "  |  " << b3 << std::endl << std::endl;
	std::cout << pf1 << std::endl;
	std::cout << rf1 << std::endl;
	std::cout << sf1 << std::endl << std::endl;

	std::cout << "----  1  ----" << std::endl;
	try {
		b3.signForm(pf1);
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "----  2  ----" << std::endl;
	try {
		pf1.execute(b3);
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "----  3  ----" << std::endl;
	try {
		sf1.execute(b2);
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "----  4  ----" << std::endl;
		b2.signForm(sf1);
		sf1.execute(b2);
	std::cout << "----  5  ----" << std::endl;
		b1.executeForm(sf2);
		b1.signForm(sf2);
	std::cout << "----  6  ----" << std::endl;
		b1.executeForm(sf2);
	std::cout << "----  7  ----" << std::endl;
		b1.executeForm(pf1);
		b1.signForm(pf1);
		b1.executeForm(pf1);
	std::cout << "----  8  ----" << std::endl;
		b1.executeForm(rf1);
		b1.signForm(rf1);
		std::cout << std::endl;
		b1.executeForm(rf1);
		std::cout << std::endl;
		b1.executeForm(rf1);
		std::cout << std::endl;
		b1.executeForm(rf1);

}
