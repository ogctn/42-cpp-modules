#include "Span.hpp"
#include <iostream>
#include <deque>

int	main() {
	Span t(20000), s(999), a(999), b(150), c(6), d(0);

	std::cout << "###---- addNumber Function -----####" << std::endl;
	c.addNumber();
	c.addNumber(17);
	c.addNumber(3);
	c.addNumber(24);			c.print("c before                          ");
	c.addNumber(c.at(2));		c.print("c after addNumber( c.at(2) )      ");
	c.addNumber(c.begin(), 99);	c.print("c after addNumber( c.begin(), 99 )");
	std::cout << "*(c.begin()): " << *(c.begin()) << std::endl;
	std::cout << "*(c.end()  ): " << *(c.end()) << std::endl;
	
	std::cout << "-----                            ---" << std::endl;
	std::cout << "\nAdd too many numbers:\n[6/6] c: "; c.addNumber();
	std::cout << "[0/0] d: "; d.addNumber(); std::cout << std::endl;

	std::cout << "###-----  addMany Function  -----###" << std::endl;
	b.addMany(5);				b.print("b: ");
	b.addMany(3, 7);			b.print("b: ");
	b.addMany(b.begin(), 2);	b.print("b: ");
	b.addMany(b.at(3), 2, 8);	b.print("b: ");

	std::cout << "-----                            ---" << std::endl;
	c.print("c: ");
	a.addMany(a.begin(), c.getData());	a.print("a: ");
	a.addMany(a.at(4), c);				a.print("a: ");

	std::cout << "-----                            ---" << std::endl;
	a.print("a: ");
	s.addMany(5);							s.print("s: ");
	s.addMany(s.at(2), a, 2, 4);			s.print("s: ");
	s.addMany(s.begin(), b.at(5), b.at(9));	s.print("s: ");

	std::cout << "\n##---- shortest/longest Span Functions ----##" << std::endl;
	t.addMany(20000);
	std::cout << "\nShortest Span of t: ";
	try {
		std::cout << t.shortestSpan() << std::endl;
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	std::cout << "Longest  Span of t: ";
	try {
		std::cout << t.longestSpan() << std::endl;
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

	std::cout << "-----                            ---" << std::endl;
	std::cout << "[0/0] empty d -> Shortest Span: ";
	try {
		std::cout << d.shortestSpan() << std::endl;
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }
	std::cout << "[0/0] empty d -> Longest Span : ";
	try {
		std::cout << d.longestSpan() << std::endl;
	} catch (std::exception &e) { std::cout << e.what() << std::endl; }

}
