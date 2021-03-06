#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap :  public FragTrap, public ScavTrap
{

	public:

		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap( DiamondTrap const & src );
		~DiamondTrap();
		void whoAmI();

	private:
		std::string _name;
};

#endif /* ***************************************************** DIAMONDTRAP_H */