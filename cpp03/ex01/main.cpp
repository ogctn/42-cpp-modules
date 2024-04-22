#include "ScavTrap.hpp"

int main(){
	// when we use heap, if we dont set claptrap destructor to virtual, it wont work
		ClapTrap *t1 = new ScavTrap();
		delete t1;
		ScavTrap t2;

	ScavTrap a( "elma" ), b( "armut" ), c, d( "araba" );
	a.attack( "portakal" );
	b.attack( "kivi" );
	a.takeDamage( 56 );
	a.beRepaired( 12 );
	b.takeDamage( 125 );
	b.beRepaired( 15 );

	a.guardGate();
	a.guardGate();
	c = a;
	a.beRepaired(0);
	c.beRepaired(0);
	d = a;
	a.beRepaired(0);
	d.beRepaired(0);

}
