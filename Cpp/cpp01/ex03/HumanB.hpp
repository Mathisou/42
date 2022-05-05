#include "Weapon.hpp"

#ifndef HUMANB_HPP
# define HUMANB_HPP

class HumanB{
	
	private:

	Weapon* _weapon;
	std::string _name;

	public:

	void attack();
	void setWeapon(Weapon&);
	HumanB(std::string name);
	~HumanB();

};

#endif