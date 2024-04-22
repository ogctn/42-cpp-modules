#include "FlagTrap.hpp"

int main(){
	FlagTrap a;
	a.takeDamage( 15 );

	FlagTrap b( "flag" );
	b.takeDamage( 150 );

	FlagTrap *p = new FlagTrap( "neww" );
	p->attack( "oldii" );
	p->takeDamage( 45 );

	FlagTrap c( *p );
	c.beRepaired( 0 );

	p->beRepaired( 0 );

	delete p;
	c.takeDamage( 5 );
	c.beRepaired( 0 );
	
	return 0;
}
