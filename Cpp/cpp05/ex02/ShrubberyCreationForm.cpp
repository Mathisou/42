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
	std::string newstr(_target + "_shrubbery");
	if (_is_signed == false)
		throw ShrubberyCreationForm::FormNotSignedException();
	else if (_grade_to_exec < executor.getGrade())
		throw ShrubberyCreationForm::GradeTooLowException();
	std::ofstream new_file;
	new_file.open(newstr.c_str());
	if (!new_file.is_open())
		std::cerr << "Failed to open Shrubbery file" << std::endl;

	new_file << "                      ,@@@@@ð@,    ð¦                      " << std::endl
			 << "             ð¦,,,.   ,@ð@@@@/@@,  .ooð888o.ð¦       ð¦     " << std::endl
			 << "           ,&%%&%ð&ð,@ð@@ð/@@@ð@,8888\\ð8/8o,           " << std::endl
			 << "          ,ð&\\%&&%ð&%,@@@\\ð@@/@@@ð\\88888/8ð|         " << std::endl
			 << "         %ð&&ð&%&/%&&ð@@\\ð¿@/ /@@@ð8888\\88ð88        " << std::endl
			 << "          %&ð%/ %ð%%&&@@\\ V /@@  `88\\ð¿ `/88           " << std::endl
			 << "          `&%\\ . /%&'    |.|        \\  |ð'               " << std::endl
			 << "             '|o|        | |         | |          ð¦         " << std::endl
			 << "              |.|        | |         | |                    " << std::endl
			 << "      ð±  ð· \\/ _\\ð·ð±_ð±_/  ,\\_ð±ð·__ /  .\\_ð±ð¢__ð±_     " << std::endl;
	new_file.close();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */