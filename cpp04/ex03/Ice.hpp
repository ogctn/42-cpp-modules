#ifndef ICE_HPP
# define ICE_HPP

# include "Character.hpp"

class Ice : public AMateria {
	public:
		Ice( void );
		Ice( const Ice & );
		~Ice( void );
		Ice &operator=( const Ice & );

		virtual AMateria* clone( void ) const;
		virtual void use( ICharacter& target );
};

#endif
