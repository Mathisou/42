#include <iostream>

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon{

	private:

	std::string _type;

	public:

	const std::string&  getType() const ;
	void  setType(std::string type);
	Weapon(std::string type);
	~Weapon();

};

#endif