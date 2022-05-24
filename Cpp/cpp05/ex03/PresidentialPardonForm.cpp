#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5, "")
{
	std::cout << "PresidentialPardonForm default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5, target)
{
	std::cout << "PresidentialPardonForm target constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src )
{
	std::cout << "PresidentialPardonForm copy constructor" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	std::cout << "PresidentialPardonForm assignation operator" << std::endl;
	_target = rhs._target;
	return *this;
}


/*
** -------------------------- MEMBER FUNCTION ---------------------------------
*/

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (_is_signed == false)
		throw PresidentialPardonForm::FormNotSignedException();
	else if (_grade_to_exec < executor.getGrade())
		throw PresidentialPardonForm::GradeTooLowException();
	std::cout << _target << " has been forgiven by Zaphod Beeblebrox." << std::endl;
}


/* ************************************************************************** */