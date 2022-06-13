#include "HumanB.hpp"

HumanB::HumanB(std::string name): _weapon(NULL), _name(name){
	return;
}

HumanB::~HumanB(){
	return ;
}

void	HumanB::setWeapon(Weapon &club){
	_weapon = &club;
}

void	HumanB::attack(){
	if (this->_weapon)
		std::cout << this->_name << " attacks with " << _weapon->getType() << std::endl;
	else
		std::cout << this->_name << " can't attack cuz he doesnt have any weapons." << std::endl;
}