#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("Joe"), _is_signed(false), _grade_to_sign(150), _grade_to_exec(150)
{
	std::cout << "Form default constructor" << std::endl;
}

Form::Form(const std::string name, )

Form::Form( const Form & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */