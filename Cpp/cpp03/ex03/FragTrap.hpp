#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

	public:

		FragTrap(void);
		FragTrap(std::string name);
		FragTrap( FragTrap const & src );
		~FragTrap(void);
		FragTrap & operator=( FragTrap const & rhs);
		void highFivesGuys(void);

};

#endif /* ********************************************* CPP03/EX02/FRAGTRAP_H */