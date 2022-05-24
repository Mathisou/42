#ifndef AForm_HPP
# define AForm_HPP

# include "Bureaucrat.hpp"
# include <stdbool.h>

class Bureaucrat;

class AForm
{

	public:

		AForm();
		AForm(const std::string name, unsigned int grade_to_sign, unsigned int grade_to_exec, std::string target);
		AForm( AForm const & src );
		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );

		const std::string getName() const;
		bool getIs_signed() const;
		unsigned int getGrade_to_sign() const;
		unsigned int getGrade_to_exec() const;
		const std::string getTarget() const;
		void beSigned(Bureaucrat const & b);
		virtual void execute(Bureaucrat const & executor) const = 0;
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

	protected:

		const std::string _name;
		bool _is_signed;
		unsigned int _grade_to_sign;
		unsigned int _grade_to_exec;
		std::string _target;

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ AForm_H */