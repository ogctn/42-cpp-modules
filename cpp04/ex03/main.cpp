#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria( new Ice() );
	src->learnMateria( new Cure() );

	ICharacter* me = new Character( "me" );
	AMateria* tmp;
	tmp = src->createMateria( "ice" );
	me->equip( tmp );
	
	tmp = src->createMateria( "cure" );
	me->equip( tmp );

	tmp = src->createMateria( "ice" );
 	me->equip( tmp );

	tmp = src->createMateria( "ice" );
	me->equip( tmp );

	me->show_inventory();

	ICharacter* bob = new Character( "bob" );
	me->use( 0, *bob );
	me->use( 1, *bob );
	me->use( 0, *bob );
	me->use( 1, *bob );

	delete bob;
	delete me;
	delete src;

	return 0;
}

// void __attribute__((destructor)) a() {
// 	system("leaks ex03");
// }
