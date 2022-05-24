#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
#include <fstream>


class ShrubberyCreationForm : public AForm
{

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

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

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */