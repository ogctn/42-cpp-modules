#ifndef CURE_HPP
# define CURE_HPP

# include "Character.hpp"

class Cure : public AMateria {
	public:
		Cure( void );
		Cure( const Cure & );
		~Cure( void );
		Cure &operator=( const Cure & );

		virtual AMateria* clone( void ) const;
		virtual void use( ICharacter& target );
};

#endif
