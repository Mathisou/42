#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
		std::cout << "WrongCat constructor called" << std::endl;
		_brain = new(Brain);
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
	delete _brain;
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

Brain &WrongCat::get_brain() const{
	return *this->_brain;
}
