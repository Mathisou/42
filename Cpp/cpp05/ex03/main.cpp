
#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <stdlib.h>
# define KEY ""

static std::string input;

int	main()
{
	std::cout << std::endl << "*" << "\033[1;32m Constructors \033[0m------------------------ *" << std::endl;
	Bureaucrat LH44(1, "\033[33mLewis *LH44*\033[0m");
	Bureaucrat CL16(5, "\033[33mCharles *CL16*\033[0m");
	Bureaucrat CS55(6, "\033[33mCarlos *CR55*\033[0m");
	Bureaucrat JB17(17, "\033[33mJules *JB17*\033[0m");
	Bureaucrat PG10(45, "\033[33mPierre *PG10*\033[0m");
	Bureaucrat GR63(72, "\033[33mGeorges *GR63*\033[0m");
	Bureaucrat KR07(137, "\033[33mKimi *KR07*\033[0m");
	Bureaucrat DR03(145, "\033[33mDaniel *DR03*\033[0m");
	Bureaucrat LN04(150, "\033[33mLando *LN04*\033[0m");

	Intern intern;
	AForm	*presidential = intern.makeForm("presidential pardon", "Toto Wolf");
	AForm	*robotomy = intern.makeForm("robotomy request", "Micheal Masi");
	AForm	*shrubbery = intern.makeForm("shrubbery creation", "trees");

	try
	{
		AForm	*lol = intern.makeForm("lol creation", "trees");
		(void)lol;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	// AForm	*lol = intern.makeForm("lol creation", "trees");

	// LH44.signAForm(*lol);
	// 	LH44.executeAForm(*lol);

	std::cout << std::endl << "Please, press ENTER" << KEY << std::endl;
	std::getline(std::cin, input);
	system ("clear");
	if (input == KEY)
	{
		std::cout << std::endl << "*" << "\033[1;34m ShrubberyCreationForm \033[0m--------------- *" << std::endl;

		std::cout << std::endl << "\033[1m" << *shrubbery << "\033[0m";
		std::cout << std::endl << "\33[4m" << LN04 << "\33[0m" << std::endl;
		LN04.signAForm(*shrubbery);
		LN04.executeAForm(*shrubbery);
		std::cout << std::endl << "\33[4m" << DR03 << "\33[0m" << std::endl;
		DR03.signAForm(*shrubbery);
		DR03.executeAForm(*shrubbery);
		std::cout << std::endl << "\33[4m" << KR07 << "\33[0m" << std::endl;
		KR07.signAForm(*shrubbery);
		KR07.executeAForm(*shrubbery);
		std::cout << std::endl << "\33[4m" << GR63 << "\33[0m" << std::endl;
		GR63.signAForm(*shrubbery);
		GR63.executeAForm(*shrubbery);
		std::cout << std::endl << "\33[4m" << PG10 << "\33[0m" << std::endl;
		PG10.signAForm(*shrubbery);
		PG10.executeAForm(*shrubbery);
		std::cout << std::endl << "\33[4m" << JB17 << "\33[0m" << std::endl;
		JB17.signAForm(*shrubbery);
		JB17.executeAForm(*shrubbery);
		std::cout << std::endl << "\33[4m" << CS55 << "\33[0m" << std::endl;
		CS55.signAForm(*shrubbery);
		CS55.executeAForm(*shrubbery);
		std::cout << std::endl << "\33[4m" << CL16 << "\33[0m" << std::endl;
		CL16.signAForm(*shrubbery);
		CL16.executeAForm(*shrubbery);
		std::cout << std::endl << "\33[4m" << LH44 << "\33[0m" << std::endl;
		LH44.signAForm(*shrubbery);
		LH44.executeAForm(*shrubbery);
		std::cout << std::endl;
		delete shrubbery;
	}

	std::cout << std::endl << "Please, press ENTER"<< std::endl;
	std::getline(std::cin, input);
	system ("clear");
	if (input == KEY)
	{
		std::cout << std::endl << "*" << "\033[1;34m RobotomyRequestForm \033[0m--------------- *" << std::endl;
		std::cout << std::endl << "\033[1m" << *robotomy << "\033[0m";
		std::cout << std::endl << "\33[4m" << LN04 << "\33[0m" << std::endl;
		LN04.signAForm(*robotomy);
		LN04.executeAForm(*robotomy);
		std::cout << std::endl << "\33[4m" << DR03 << "\33[0m" << std::endl;
		DR03.signAForm(*robotomy);
		DR03.executeAForm(*robotomy);
		std::cout << std::endl << "\33[4m" << KR07 << "\33[0m" << std::endl;
		KR07.signAForm(*robotomy);
		KR07.executeAForm(*robotomy);
		std::cout << std::endl << "\33[4m" << GR63 << "\33[0m" << std::endl;
		GR63.signAForm(*robotomy);
		GR63.executeAForm(*robotomy);
		std::cout << std::endl << "\33[4m" << PG10 << "\33[0m" << std::endl;
		PG10.signAForm(*robotomy);
		PG10.executeAForm(*robotomy);
		std::cout << std::endl << "\33[4m" << JB17 << "\33[0m" << std::endl;
		JB17.signAForm(*robotomy);
		JB17.executeAForm(*robotomy);
		std::cout << std::endl << "\33[4m" << CS55 << "\33[0m" << std::endl;
		CS55.signAForm(*robotomy);
		CS55.executeAForm(*robotomy);
		std::cout << std::endl << "\33[4m" << CL16 << "\33[0m" << std::endl;
		CL16.signAForm(*robotomy);
		CL16.executeAForm(*robotomy);
		std::cout << std::endl << "\33[4m" << LH44 << "\33[0m" << std::endl;
		LH44.signAForm(*robotomy);
		LH44.executeAForm(*robotomy);
		std::cout << std::endl;
		delete robotomy;
	}

	std::cout << std::endl << "Please, press enter" << KEY << std::endl;
	std::getline(std::cin, input);
	system ("clear");
	if (input == KEY)
	{
		std::cout << std::endl << "*" << "\033[1;34m PresidentialPardonForm \033[0m--------------- *" << std::endl;
		std::cout << std::endl << "\033[1m" << *presidential << "\033[0m";
		std::cout << std::endl << "\33[4m" << LN04 << "\33[0m" << std::endl;
		LN04.signAForm(*presidential);
		LN04.executeAForm(*presidential);
		std::cout << std::endl << "\33[4m" << DR03 << "\33[0m" << std::endl;
		DR03.signAForm(*presidential);
		DR03.executeAForm(*presidential);
		std::cout << std::endl << "\33[4m" << KR07 << "\33[0m" << std::endl;
		KR07.signAForm(*presidential);
		KR07.executeAForm(*presidential);
		std::cout << std::endl << "\33[4m" << GR63 << "\33[0m" << std::endl;
		GR63.signAForm(*presidential);
		GR63.executeAForm(*presidential);
		std::cout << std::endl << "\33[4m" << PG10 << "\33[0m" << std::endl;
		PG10.signAForm(*presidential);
		PG10.executeAForm(*presidential);
		std::cout << std::endl << "\33[4m" << JB17 << "\33[0m" << std::endl;
		JB17.signAForm(*presidential);
		JB17.executeAForm(*presidential);
		std::cout << std::endl << "\33[4m" << CS55 << "\33[0m" << std::endl;
		CS55.signAForm(*presidential);
		CS55.executeAForm(*presidential);
		std::cout << std::endl << "\33[4m" << CL16 << "\33[0m" << std::endl;
		CL16.signAForm(*presidential);
		CL16.executeAForm(*presidential);
		std::cout << std::endl << "\33[4m" << LH44 << "\33[0m" << std::endl;
		LH44.signAForm(*presidential);
		LH44.executeAForm(*presidential);
		std::cout << std::endl;
		delete presidential;
	}

	std::cout << std::endl << "*" << "\033[1;32m Destructors \033[0m------------- *" << std::endl;
	return (0);
}
