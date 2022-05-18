#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource default construtor" << std::endl;
	for (int i = 0;i<4;i++)
		_learn[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	std::cout << "MateriaSource copy construtor" << std::endl;
	for (int i = 0; i<4; i++)
		if (src._learn[i])
			_learn[i] = src._learn[i];
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	std::cout << "MateriaSource assignation operator called" << std::endl;
	for (int i = 0; i<4; i++)
		if (rhs._learn[i])
			_learn[i] = rhs._learn[i];
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void MateriaSource::learnMateria(AMateria* m){
	for (int i = 0;i<4;i++){
		if (_learn[i] == NULL){
			_learn[i] = m;
			std::cout << "Materia " << m->getType() << " learned" << std::endl;
			return;
		}
		else if (i == 3)
			std::cout << "Can't learn more than 4 Materia" << std::endl;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type){
	for (int i = 0;i<4;i++){
		if (_learn[i] != NULL && _learn[i]->getType() == type){
			std::cout << "Materia " << _learn[i]->getType() << " created." << std::endl;
			return _learn[i];
		}
	}
	std::cout << "No such materia known" << std::endl;
	return (0);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */