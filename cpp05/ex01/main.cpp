#include "Bureaucrat.hpp"
#include "Form.hpp"


int	main() {
	Bureaucrat	b1("b1", 1);
	Bureaucrat	b2("b2", 150);
	Bureaucrat	b3 = Bureaucrat("b3", 20);
	Form 		f1("f1", 1, 1);
	Form 		f2("f2", 100, 100);
	
	try{
		Form 		f3("f3", 0, 100);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;

	std::cout << f1 << std::endl;

	try {
		b1.incrementGrade();
	} catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	try {
		b1.incrementGrade();
	} catch(std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
	std::cout << f1 << std::endl;
	f1.setSigned(true);
	std::cout << f1 << std::endl;
	
	try {
		f1.beSigned(b2);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		f1.beSigned(b1);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
