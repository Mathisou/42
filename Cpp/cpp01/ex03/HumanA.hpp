#include "Weapon.hpp"

#ifndef HUMANA_HPP
# define HUMANA_HPP

class HumanA{
	
	private:

	Weapon& _weapon;
	std::string _name;
	
	public:

	void attack();
	HumanA(std::string name, Weapon& club);
	~HumanA();

};

#endif