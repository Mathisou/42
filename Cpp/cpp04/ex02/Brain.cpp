#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	// this->_ideas = new std::string();
	for (int i = 0; i < 100; i++)
	 	this->_ideas[i] = "0";

}

Brain::Brain( const Brain & src )
{
	std::cout << "Brain name constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	std::cout << "Brain assignation operator called" << std::endl;
	for (int i = 0;i < 100;i++)
		this->_ideas[i] = rhs._ideas[i];
	return *this;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void Brain::set_idea(unsigned int index, std::string idea){
	if (index < 100)
		_ideas[index] = idea;
	else
		std::cout << "Invalid index." << std::endl;
}

std::string Brain::get_idea(unsigned int index) const{
	if (index < 100)
		return (this->_ideas[index]);
	std::cout << "Invalid index." << std::endl;
	return NULL;
}


/* ************************************************************************** */

void	Brain::print_ideas(){
	for (int i =0;i<100;i++){
		std::cout << this->_ideas[i];
		if (i != 99)
			std::cout << " ";
		else
			std::cout << std::endl;
	}
}
