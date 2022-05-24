#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm() : _name("Joe"), _is_signed(false), _grade_to_sign(150), _grade_to_exec(150), _target("")
{
	std::cout << "AForm default constructor" << std::endl;
}

AForm::AForm(const std::string name, unsigned int grade_to_sign, unsigned int grade_to_exec, std::string target) : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec), _target(target)
{
	std::cout << "AForm fill constructor" << std::endl;
	if (_grade_to_sign < 1){
		_grade_to_sign = 150;
		throw AForm::GradeTooHighException();
	}
	else if (grade_to_sign > 150){
		_grade_to_sign = 150;
		throw AForm::GradeTooLowException();
	}
	if (_grade_to_exec < 1){
		_grade_to_exec = 150;
		throw AForm::GradeTooHighException();
	}
	else if (grade_to_exec > 150){
		_grade_to_exec = 150;
		throw AForm::GradeTooLowException();
	}
}

AForm::AForm( const AForm & src)
{
	std::cout << "AForm copy constructor" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
	std::cout << "AForm destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	std::cout << "AForm assignation operator called " << std::endl;
	// // _name = rhs.getName();
	// _is_signed = rhs.getIs_signed();
	// _grade_to_exec = rhs.getGrade_to_exec();
	// _grade_to_sign = rhs.getGrade_to_sign();
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	if (i.getIs_signed() == false)
		o << i.getName() << " AForm is not signed. We have to be grade " << i.getGrade_to_sign()
						 << " or lower to sign it, and grade " << i.getGrade_to_exec() << " or lower to execute it." << std::endl;
	else
		o << i.getName() << " AForm is signed. We have to be grade " << i.getGrade_to_sign()
						 << " or lower to sign it, and grade " << i.getGrade_to_exec() << " or lower to execute it." << std::endl;
	return o;
}


/*
** ----------------------------- MEMBER FUNCTIONS -----------------------------
*/

void AForm::beSigned(Bureaucrat const & b){
	if (b.getGrade() > _grade_to_sign)
		throw AForm::GradeTooLowException();
	_is_signed = true;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string AForm::getName() const{
	return _name;
}

bool AForm::getIs_signed() const{
	return _is_signed;
}

unsigned int AForm::getGrade_to_sign() const{
	return _grade_to_sign;
}

unsigned int AForm::getGrade_to_exec() const{
	return _grade_to_exec;
}

const std::string AForm::getTarget() const{
	return _target;
}


/* ************************************************************************** */