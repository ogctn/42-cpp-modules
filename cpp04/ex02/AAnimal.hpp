#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <sstream>

class AAnimal {
	private:
		std::string _type;

	public:
		AAnimal( void );
		AAnimal( std::string );
		AAnimal( const AAnimal & );
		virtual	~AAnimal( void );
		AAnimal &operator=( const AAnimal & );

		virtual void		makeSound( void ) const = 0;
		std::string			getType( void ) const;
		virtual std::string	get_idea( unsigned int ) const = 0;

};

#endif
