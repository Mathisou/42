#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45, "")
{
	std::cout << "RobotomyRequestForm default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45, target)
{
	std::cout << "RobotomyRequestForm target constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
{
	std::cout << "RobotomyRequestForm copy constructor" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	std::cout << "RobotomyRequestForm assignation operator" << std::endl;
	_target = rhs._target;
	return *this;
}


/*
** -------------------------- MEMBER FUNCTION ---------------------------------
*/

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (_is_signed == false)
		throw RobotomyRequestForm::FormNotSignedException();
	else if (_grade_to_exec < executor.getGrade())
		throw RobotomyRequestForm::GradeTooLowException();
	std::cout << "brbrbrbr la perceuse" << std::endl;
	std::srand(std::time(0));
	int alea = std::rand() % 2;
	if (alea)
		std::cout << _target << " got robotomized." << std::endl;
	else
		std::cerr << "Robotomized failed on " << _target << "..." << std::endl;
}

/* ************************************************************************** */