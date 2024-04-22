#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal( "WrongCat" ) {
	std::cout << "WrongCat Default constructor is called" << std::endl;
}

WrongCat::WrongCat( const WrongCat &ref ) : WrongAnimal( ref ) {
	std::cout << "WrongCat Copy constructor is called" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor is called" << std::endl;
}

WrongCat	&WrongCat::operator=( const WrongCat &src ) {
	std::cout << "WrongCat Assignmet Operator is called" << std::endl;
	WrongAnimal::operator=( src );
	return *this;
}

void	WrongCat::makeSound() {
	std::cout << "WrongCats bark..." << std::endl;
}
