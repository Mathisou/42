#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("Joe"), _is_signed(false), _grade_to_sign(150), _grade_to_exec(150)
{
	std::cout << "Form default constructor" << std::endl;
}

Form::Form(const std::string name, unsigned int grade_to_sign, unsigned int grade_to_exec) : _name(name), _is_signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
	std::cout << "Form fill constructor" << std::endl;
	if (_grade_to_sign < 1){
		_grade_to_sign = 150;
		throw Form::GradeTooHighException();
	}
	else if (grade_to_sign > 150){
		_grade_to_sign = 150;
		throw Form::GradeTooLowException();
	}
	if (_grade_to_exec < 1){
		_grade_to_exec = 150;
		throw Form::GradeTooHighException();
	}
	else if (grade_to_exec > 150){
		_grade_to_exec = 150;
		throw Form::GradeTooLowException();
	}
}

Form::Form( const Form & src)
{
	std::cout << "Form copy constructor" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	std::cout << "Form assignation operator called " << std::endl;
	// // _name = rhs.getName();
	// _is_signed = rhs.getIs_signed();
	// _grade_to_exec = rhs.getGrade_to_exec();
	// _grade_to_sign = rhs.getGrade_to_sign();
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	if (i.getIs_signed() == false)
		o << i.getName() << " form is not signed. We have to be grade " << i.getGrade_to_sign()
						 << " or lower to sign it, and grade " << i.getGrade_to_exec() << " or lower to execute it." << std::endl;
	else
		o << i.getName() << " form is signed. We have to be grade " << i.getGrade_to_sign()
						 << " or lower to sign it, and grade " << i.getGrade_to_exec() << " or lower to execute it." << std::endl;
	return o;
}


/*
** ----------------------------- MEMBER FUNCTIONS -----------------------------
*/

void Form::beSigned(Bureaucrat const & b){
	if (b.getGrade() > _grade_to_sign)
		throw Form::GradeTooLowException();
	_is_signed = true;
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string Form::getName() const{
	return _name;
}

bool Form::getIs_signed() const{
	return _is_signed;
}

unsigned int Form::getGrade_to_sign() const{
	return _grade_to_sign;
}

unsigned int Form::getGrade_to_exec() const{
	return _grade_to_exec;
}


/* ************************************************************************** */