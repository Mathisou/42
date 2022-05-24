#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
class AForm;

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		AForm* makeForm(std::string name, std::string target);

		class BadNameException : public std::exception
		{
			public:
				virtual const char* what() const throw(){
					return ("Bad form name.");
				}
		};

	private:

		std::string _typeForm[3];
		AForm		*_makeShrubberyCreation(std::string target);
		AForm		*_makeRobotomyRequest(std::string target);
		AForm		*_makePresidentialPardon(std::string target);
};

#endif /* ********************************************************** INTERN_H */