#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("null"), _hp(10), _mana(10), _damage(0){
	std::cout << "Default constructor called" << std::endl;
}
ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _mana(10), _damage(0){
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & rhs){
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

ClapTrap::~ClapTrap(void){
	std::cout << "Destructor called" << std::endl;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs){
	std::cout << "Assignation operator called" << std::endl;
	_mana = rhs._mana;
	_hp = rhs._hp;
	_damage = rhs._damage;
	return *this;
}

void ClapTrap::attack(const std::string& target){
	if (this->_mana > 0 && this->_hp > 0){
		std::cout << "ClapTrap " <<  _name << " attacks " << target << ", causing " << _damage << " point(s) of damage!" << std::endl;
		this->_mana--;
	}
	else if (this->_hp == 0)
		std::cout << "ClapTrap " << _name << " can't attack, he is dead..." << std::endl;
	else
		std::cout << "Not enough mana!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_hp > 0){
		if (amount > (unsigned int)_hp){
			std::cout << "ClapTrap " <<  _name << " be attacked , losing " << _hp << " hp!" << std::endl;
			_hp = 0;
		}
		else
		{
			std::cout << "ClapTrap " <<  _name << " be attacked , losing " << amount << " hp!" << std::endl;
			_hp -= amount;
		}
		std::cout << "ClapTrap " << _name << " have now " << _hp << " hp." << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " is already dead... leave him alone" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_mana > 0 && this->_hp > 0){
		std::cout << "ClapTrap " <<  _name << " healed himself with " << amount <<  " hp" << std::endl;
		this->_mana--;
		this->_hp += amount;
	}
	else if (this->_hp == 0)
		std::cout << "ClapTrap " << _name << " can't heal himself, he is dead..." << std::endl;
	else
		std::cout << "Not enough mana!" << std::endl;
}
