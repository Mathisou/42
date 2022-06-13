#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& club): _weapon(club), _name(name){
	return;
}

HumanA::~HumanA(){
	return ;
}

void	HumanA::attack(){
	std::cout << this->_name << " attacks with " << this->_weapon.getType() << std::endl;
}