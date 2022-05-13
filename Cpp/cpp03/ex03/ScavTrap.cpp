#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void){
	std::cout << "ScavTrap default constructor called" << std::endl;
	_hp = 100;
	_mana = 50;
	_damage = 20;
}
ScavTrap::ScavTrap(std::string name){
	std::cout << "ScavTrap name constructor called" << std::endl;
	_name = name;
	_hp = 100;
	_mana = 50;
	_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap & rhs){
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = rhs;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs){
	std::cout << "Assignation operator called" << std::endl;
	_mana = rhs._mana;
	_hp = rhs._hp;
	_damage = rhs._damage;
	return *this;
}

ScavTrap::~ScavTrap(void){
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (this->_mana > 0 && this->_hp > 0){
		std::cout << "ScavTrap " <<  _name << " attacks " << target << ", causing " << _damage << " point(s) of damage!" << std::endl;
		this->_mana--;
	}
	else if (this->_hp == 0)
		std::cout << "ScavTrap " << _name << " can't attack, he is dead..." << std::endl;
	else
		std::cout << "Not enough mana!" << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "Be careful, ScavTrap " << _name << " entered in Gate keeper mode!" << std::endl;
}
