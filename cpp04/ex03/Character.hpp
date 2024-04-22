#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <iostream>

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria	*_inventory[4];

	public:
		Character( void );
		Character ( std::string );
		Character( const Character & );
		~Character( void );

		Character &operator=( const Character & );

		std::string const 	&getName( void ) const;
		void				equip( AMateria* m );
		void				unequip( int idx );
		void				use( int idx, ICharacter& target );
		void				show_inventory( void ) const;
};

#endif
