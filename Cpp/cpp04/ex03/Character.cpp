#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character(std::string name)
{
	std::cout << "Character default constructor" << std::endl;
	_name = name;
	for (int i = 0; i < 4;i++)
		_inventory[i] = NULL;
}

Character::Character( const Character & src )
{
	std::cout << "Character copy constructor" << std::endl;
	_name = src.getName();
	for (int i = 0;i < 4;i++)
		if (_inventory[i])
			delete _inventory[i];
	for (int i = 0;i < 4;i++)
		_inventory[i] = src._inventory[i]->clone();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	std::cout << "Character destructor" << std::endl;
	for (int i = 0;i < 4;i++)
		if (_inventory[i])
			delete _inventory[i];
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	_name = rhs.getName();
	for (int i = 0;i < 4;i++)
		_inventory[i] = rhs._inventory[i];
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Character::equip(AMateria* m){
	for(int i = 0;i < 4;i++){
		if (_inventory[i] == NULL){
			std::cout << "Materia " << m->getType() << " added to " << _name << " inventory." << std::endl;
			_inventory[i] = m;
			return;
		}
		else if (i == 3)
			std::cout << "Inventory is full" << std::endl;
	}
}

void Character::unequip(int idx){
	if (idx >= 0 && idx < 4 && _inventory[idx]){
		std::cout << "Materia " << _inventory[idx]->getType() << " removed from " << _name << " inventory." << std::endl;
		_inventory[idx] = NULL;
	}
	else
		std::cout << "Nothing to remove here..." << std::endl;
}

void Character::use(int idx, ICharacter& target){
	if (idx >= 0 && idx < 4 && _inventory[idx]){
		_inventory[idx]->use(target);
	}
}

std::string const & Character::getName() const{
	return _name;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */