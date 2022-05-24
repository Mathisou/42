#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	_hp = FragTrap::_hp;
	_mana = ScavTrap::_mana;
	_damage = FragTrap::_damage;
	std::cout << _hp << " " << _mana << " " << _damage << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name +  "_clap_name"){
	std::cout << "DiamondTrap name constructor called" << std::endl;
	 _name = name;
	_hp = FragTrap::_hp;
	_mana = ScavTrap::_mana;
	_damage = FragTrap::_damage;
	std::cout << _hp << " " << _mana << " " << _damage << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src )
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap destructor called" << std::endl;
}


/* ************************************************************************** */

void DiamondTrap::whoAmI(){
	std::cout << "My name is " << _name << " and ClapTrap's name is " << ClapTrap::_name << std::endl;
}
