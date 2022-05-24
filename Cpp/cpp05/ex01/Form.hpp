#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <stdbool.h>

class Bureaucrat;

class Form
{

	public:

		Form();
		Form(const std::string name, unsigned int grade_to_sign, unsigned int grade_to_exec);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		const std::string getName() const;
		bool getIs_signed() const;
		unsigned int getGrade_to_sign() const;
		unsigned int getGrade_to_exec() const;
		void beSigned(Bureaucrat const & b);

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw(){
					return ("Grade is too low");
				}
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw(){
					return ("Grade is too high");
				}
		};

	private:

		const std::string _name;
		bool _is_signed;
		unsigned int _grade_to_sign;
		unsigned int _grade_to_exec;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */