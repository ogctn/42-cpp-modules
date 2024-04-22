#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
	for ( int i = 0; i < 4; i++ ) {
		_materials[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource &ref ) {
	for ( int i = 0; i < 4; i++ ) {
		_materials[i] = ref._materials[i];
	}
}

MateriaSource::~MateriaSource( void ) {
	for ( int i = 0; i < 4; i++ ) {
		if ( _materials[i] != NULL ) {
			delete _materials[i];
		}
	}
}

MateriaSource &MateriaSource::operator=( const MateriaSource &src ) {
	if ( this != &src ) {
		for ( int i = 0; i < 4; i++ ) {
			_materials[i] = src._materials[i];
		}
	}
	return *this;
}

void	MateriaSource::learnMateria( AMateria *learned ) {
	for ( int i = 0; i < 4; i++ ) {
		if ( _materials[i] == NULL ) {
			_materials[i] = learned;
			break;
		}
	}
}

AMateria*	MateriaSource::createMateria( std::string const &created ) {
	for ( int i = 0; i < 4; i++ ) {
		if ( _materials[i] && created == _materials[i]->getType() ) {
			return _materials[i]->clone();
		}
	}
	return NULL;
}
