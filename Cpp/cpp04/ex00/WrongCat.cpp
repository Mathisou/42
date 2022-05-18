#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
		std::cout << "WrongCat constructor called" << std::endl;
		_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat & src )
{
		std::cout << "WrongCat copy constructor called" << std::endl;
		_type = src._type;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	_type = rhs._type;
	return *this;
}

/* ************************************************************************** */

void	WrongCat::makeSound() const{
	std::cout << "MEOW 👹" << std::endl;
	return ;
}
