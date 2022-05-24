#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		virtual void execute(Bureaucrat const & executor) const;

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw(){
					return ("Grade is too low");
				}
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw(){
					return ("The form is not signed");
				}
		};

};

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */