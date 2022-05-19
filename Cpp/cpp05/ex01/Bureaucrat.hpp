#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{

	public:

		Bureaucrat(void);
		Bureaucrat(int grade, std::string name);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat(void);

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		std::string const getName() const;
		unsigned int getGrade() const;
		void GradeUp();
		void GradeDown();

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

		std::string const _name;
		unsigned int _grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */