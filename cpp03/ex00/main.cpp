#include "ClapTrap.hpp"

int main(){
	ClapTrap c1( "elma" ), c2( "armut" ), c3( "rep" );

	c1.attack( "kayseri" );
	c2.takeDamage( 2 );
	c1.takeDamage( 12 );
	c1.attack( "araba" );
	c1.takeDamage( 3 );
	c1.takeDamage( 0 );
	c2.takeDamage( 0 );
	c3.takeDamage( 5 );
	c3.beRepaired( 16 );
	c1.beRepaired( 0 );
	c3.beRepaired( 0 );
}
