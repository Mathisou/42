#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
		std::cout << "Dog default constructor called " << std::endl;
		_type  = "Dog";
		_brain = new Brain();
}

Dog::Dog( const Dog & src )
{
		std::cout << "Dog copy constructor called " << std::endl;
		*this = src;		
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
		delete _brain;
		std::cout << "Dog destructor called " << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	std::cout << "Dog assignation operator called" << std::endl;
	_type = rhs._type;
	return *this;
}


/* ************************************************************************** */

void Dog::makeSound() const{
	std::cout << "WOUF" << std::endl;
	return ;
}

Brain &Dog::get_brain() const{
	return *this->_brain;
}
