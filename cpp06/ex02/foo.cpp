#include "foo.hpp"

Base	*generate(void) {
	switch (rand() % 3) {
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
		default:
			return (NULL);
	}
}

void	identify(Base *p) {
	if (!p)
		std::cout << "NULL pointer!" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "type: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "type: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "type: C" << std::endl;
	else
		std::cout << "Unknown type!" << std::endl;
}

void	identify(Base &p) {
	try {
		A &t = dynamic_cast<A&>(p);
		(void)t;
		std::cout << "type: A" << std::endl;
	} catch (std::exception &e1) {
		try {
			B &t = dynamic_cast<B&>(p);
			(void)t;
			std::cout << "type: B" << std::endl;
		} catch (std::exception &e2) {
			try {
				C &t = dynamic_cast<C&>(p);
				(void)t;
				std::cout << "type: C" << std::endl;
			} catch (std::exception &e3) {
				std::cout << "Unknown type!" << std::endl;
			}
		}
	}
}
