#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main() {

	Bureaucrat b1("ogcetin", 1), b2("taybakan", 45), b3("tnoyan", 150);
	Intern intern;

	AForm *form1 = intern.makeForm("PresidentialPardonForm", "target1");
	AForm *form2 = intern.makeForm("RobotomyRequestForm", "target2");
	AForm *form3 = intern.makeForm("ShrubberyCreationForm", "target3");

	std::cout << b1 << "  |  " << b2 << "  |  " << b3 << std::endl << std::endl;

	std::cout << "----  Forms:  ----" << std::endl;
	std::cout << *form1 << std::endl << *form2 << std::endl << *form3 << std::endl;
	
	std::cout << "----  1  ----" << std::endl;
	b1.executeForm(*form1);
	b1.signForm(*form1);
	std::cout << *form1 << std::endl;
	b1.executeForm(*form1);

	std::cout << "----  2  ----" << std::endl;
	std::cout << *form2 << std::endl;
	form2->beSigned(b2);
	try {
		form2->execute(b2);
		form2->execute(b2);
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "----  3  ----" << std::endl;
	b3.executeForm(*form3);
	try {
		b3.signForm(*form3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		b3.executeForm(*form3);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "----  4  ----" << std::endl;
	b1.signForm(*form3);
	b1.executeForm(*form3);
	std::cout << *form1 << std::endl;
}
