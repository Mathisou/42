#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
		std::cout << "Cat constructor called" << std::endl;
		_type = "Cat";
}

Cat::Cat( const Cat & src )
{
		std::cout << "Cat copy constructor called" << std::endl;
		_type = src._type;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	std::cout << "Cat assignation operator called" << std::endl;
	_type = rhs._type;
	return *this;
}

/* ************************************************************************** */

void	Cat::makeSound() const{
	std::cout << "Meowww 😸" << std::endl;
	return ;
}
