#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137, "")
{
	std::cout << "ShrubberyCreationForm default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137, target)
{
	std::cout << "ShrubberyCreationForm target constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )
{
	std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	std::cout << "ShrubberyCreationForm assignation operator" << std::endl;
	_target = rhs._target;
	return *this;
}


/*
** -------------------------- MEMBER FUNCTION ---------------------------------
*/
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{

	if (_is_signed == false)
		throw ShrubberyCreationForm::FormNotSignedException();
	else if (_grade_to_exec < executor.getGrade())
		throw ShrubberyCreationForm::GradeTooLowException();
	std::ofstream new_file(_target + "_shrubbery");
	if (!new_file.is_open())
		std::cerr << "Failed to open Shrubbery file" << std::endl;

	new_file << "                      ,@@@@@🍒@,    🦋                      " << std::endl
			 << "             🦉,,,.   ,@🍒@@@@/@@,  .oo🍋888o.🦜       🦋     " << std::endl
			 << "           ,&%%&%🍑&🐒,@🍒@@🍒/@@@🍒@,8888\\🍋8/8o,           " << std::endl
			 << "          ,🍑&\\%&&%🍑&%,@@@\\🍒@@/@@@🍋\\88888/8🍋|         " << std::endl
			 << "         %🍑&&🍑&%&/%&&🍑@@\\🐿@/ /@@@🍋8888\\88🍋88        " << std::endl
			 << "          %&🍑%/ %🍑%%&&@@\\ V /@@  `88\\🐿 `/88           " << std::endl
			 << "          `&%\\ . /%&'    |.|        \\  |🍋'               " << std::endl
			 << "             '|o|        | |         | |          🦋         " << std::endl
			 << "              |.|        | |         | |                    " << std::endl
			 << "      🌱  🌷 \\/ _\\🌷🌱_🌱_/  ,\\_🌱🌷__ /  .\\_🌱🐢__🌱_     " << std::endl;
	new_file.close();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */