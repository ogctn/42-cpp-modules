#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <sstream>

class Animal {
	private:
		std::string _type;

	public:
		Animal( void );
		Animal( std::string );
		Animal( const Animal & );
		virtual	~Animal( void );
		Animal &operator=( const Animal & );

		virtual void		makeSound( void ) const;
		std::string			getType( void ) const;
		virtual std::string	get_idea( unsigned int ) const = 0;

};

#endif
