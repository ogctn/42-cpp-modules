#ifndef FLAGTRAP_HPP
# define FLAGTRAP_HPP

# include "ScavTrap.hpp"

class FlagTrap : public ClapTrap {
	public:
		FlagTrap();
		FlagTrap( std::string );
		FlagTrap( const FlagTrap & );
		~FlagTrap();

		FlagTrap	&operator=( const FlagTrap & );

		void	 highFivesGuys();

};

#endif
