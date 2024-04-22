#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain Default constructor is called" << std::endl;
	std::ostringstream ss;

	for ( int i = 0; i < 100; i++ ) {
		ss.str( "" );
		ss << "idea number: " << i;
		set_idea( i , ss.str() );
	}
}

Brain::~Brain( void ) {
	std::cout << "Brain destructor is called" << std::endl;
}

Brain::Brain( const Brain &ref ) {
	std::cout << "Brain copy constructor is called" << std::endl;
	for ( int i = 0; i < 100; i++) {
		_ideas[i] = ref._ideas[i];
	}
}

Brain	&Brain::operator=( const Brain &src ) {
	std::cout << "Brain assignmet operator is called" << std::endl;
	for ( int i = 0; i < 100; i++) {
		_ideas[i] = src._ideas[i];
	}
	return *this;
}

void	Brain::set_idea( unsigned int idx, std::string idea ) {
	_ideas[idx] = idea;
}

std::string	Brain::get_idea( unsigned int idx ) const {
	return _ideas[idx];
}
