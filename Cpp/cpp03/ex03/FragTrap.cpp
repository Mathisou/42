#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	_hp = 100;
	_mana = 100;
	_damage = 30;
}

FragTrap::FragTrap(std::string name){
	std::cout << "FragTrap name constructor called" << std::endl;
	_name = name;
	_hp = 100;
	_mana = 100;
	_damage = 30;
}

FragTrap::FragTrap( const FragTrap & src )
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = src;
}

FragTrap & FragTrap::operator=( FragTrap const & rhs){
	std::cout << "Assignation operator called" << std::endl;
	_mana = rhs._mana;
	_hp = rhs._hp;
	_damage = rhs._damage;
	return *this;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}

/* ************************************************************************** */

void FragTrap::highFivesGuys(void){
	if (_hp > 0)
		std::cout << "FragTrap " << _name << " ask to the opponent for an high five." << std::endl;
	else
		std::cout << "Erf.. FragTrap can't ask to the opponent for an high five anymore..." << std::endl;
}
