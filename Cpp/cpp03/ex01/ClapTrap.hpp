#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

	protected:
	std::string _name;
	int _hp;
	int _mana;
	int _damage;

	public:
	ClapTrap(void);
	ClapTrap(std::string);
	ClapTrap(const ClapTrap & rhs);
	~ClapTrap(void);
	ClapTrap & operator=( ClapTrap const & rhs);
	void attack(const std::string& target);
 	void takeDamage(unsigned int amount);
 	void beRepaired(unsigned int amount);

};

#endif