#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat	b1("b1", 1);
	Bureaucrat	b2("b2", 150);
	Bureaucrat	b3 = Bureaucrat("b3", 75);
	Bureaucrat	b4 = Bureaucrat(b2);
	Bureaucrat	b5(b3);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	std::cout << b4 << std::endl;
	std::cout << b5 << std::endl;

	try {
		b1.incrementGrade();
	} catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	
	try {
		b1.incrementGrade();
	} catch(std::exception &ooo) {
		std::cerr << ooo.what() << std::endl;
	}

}
