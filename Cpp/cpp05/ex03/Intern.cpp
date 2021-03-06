#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	std::cout << "Intern default constructor" << std::endl;
	_typeForm[0] = "shrubbery creation";
	_typeForm[1] = "robotomy request";
	_typeForm[2] = "presidential pardon";
}

Intern::Intern( const Intern & src )
{
	std::cout << "Intern copy constructor" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
	std::cout << "Intern destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** ------------------------- Member Function ----------------------------------
*/

AForm* Intern::makeForm(std::string name, std::string target){
	AForm *form;
	AForm	*(Intern::*f[3])(std::string) = {
		&Intern::_makeShrubberyCreation,
		&Intern::_makeRobotomyRequest,
		&Intern::_makePresidentialPardon
	};
	for (int i = 0;i<3;i++){
		if (_typeForm[i].compare(name) == 0)
		{
			form = (this->*(f[i]))(target);
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form); 
		}
	}
	throw Intern::BadNameException();
	return (NULL);
}

AForm		*Intern::_makeShrubberyCreation(std::string target){
	return (new ShrubberyCreationForm(target));
}

AForm		*Intern::_makeRobotomyRequest(std::string target){
	return (new RobotomyRequestForm(target));
}

AForm		*Intern::_makePresidentialPardon(std::string target){
	return (new PresidentialPardonForm(target));
}


/* ************************************************************************** */