#include "Bureaucrat.hpp"
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

	std::cout << std::endl << "Please, press ENTER" << KEY << std::endl;
	std::getline(std::cin, input);
	system ("clear");
	if (input == KEY)
	{
		std::cout << std::endl << "*" << "\033[1;34m ShrubberyCreationForm \033[0m--------------- *" << std::endl;
		AForm *form = new ShrubberyCreationForm("trees");
		std::cout << std::endl << "\033[1m" << *form << "\033[0m";
		std::cout << std::endl << "\33[4m" << LN04 << "\33[0m" << std::endl;
		LN04.signAForm(*form);
		LN04.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << DR03 << "\33[0m" << std::endl;
		DR03.signAForm(*form);
		DR03.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << KR07 << "\33[0m" << std::endl;
		KR07.signAForm(*form);
		KR07.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << GR63 << "\33[0m" << std::endl;
		GR63.signAForm(*form);
		GR63.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << PG10 << "\33[0m" << std::endl;
		PG10.signAForm(*form);
		PG10.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << JB17 << "\33[0m" << std::endl;
		JB17.signAForm(*form);
		JB17.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << CS55 << "\33[0m" << std::endl;
		CS55.signAForm(*form);
		CS55.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << CL16 << "\33[0m" << std::endl;
		CL16.signAForm(*form);
		CL16.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << LH44 << "\33[0m" << std::endl;
		LH44.signAForm(*form);
		LH44.executeAForm(*form);
		std::cout << std::endl;
		delete form;
	}

	std::cout << std::endl << "Please, press ENTER"<< std::endl;
	std::getline(std::cin, input);
	system ("clear");
	if (input == KEY)
	{
		std::cout << std::endl << "*" << "\033[1;34m RobotomyRequestForm \033[0m--------------- *" << std::endl;
		AForm *form = new RobotomyRequestForm("newTarget");
		std::cout << std::endl << "\033[1m" << *form << "\033[0m";
		std::cout << std::endl << "\33[4m" << LN04 << "\33[0m" << std::endl;
		LN04.signAForm(*form);
		LN04.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << DR03 << "\33[0m" << std::endl;
		DR03.signAForm(*form);
		DR03.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << KR07 << "\33[0m" << std::endl;
		KR07.signAForm(*form);
		KR07.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << GR63 << "\33[0m" << std::endl;
		GR63.signAForm(*form);
		GR63.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << PG10 << "\33[0m" << std::endl;
		PG10.signAForm(*form);
		PG10.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << JB17 << "\33[0m" << std::endl;
		JB17.signAForm(*form);
		JB17.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << CS55 << "\33[0m" << std::endl;
		CS55.signAForm(*form);
		CS55.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << CL16 << "\33[0m" << std::endl;
		CL16.signAForm(*form);
		CL16.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << LH44 << "\33[0m" << std::endl;
		LH44.signAForm(*form);
		LH44.executeAForm(*form);
		std::cout << std::endl;
		delete form;
	}

	std::cout << std::endl << "Please, press enter" << KEY << std::endl;
	std::getline(std::cin, input);
	system ("clear");
	if (input == KEY)
	{
		std::cout << std::endl << "*" << "\033[1;34m PresidentialPardonForm \033[0m--------------- *" << std::endl;
		AForm *form = new PresidentialPardonForm("Toto Wolf");
		std::cout << std::endl << "\033[1m" << *form << "\033[0m";
		std::cout << std::endl << "\33[4m" << LN04 << "\33[0m" << std::endl;
		LN04.signAForm(*form);
		LN04.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << DR03 << "\33[0m" << std::endl;
		DR03.signAForm(*form);
		DR03.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << KR07 << "\33[0m" << std::endl;
		KR07.signAForm(*form);
		KR07.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << GR63 << "\33[0m" << std::endl;
		GR63.signAForm(*form);
		GR63.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << PG10 << "\33[0m" << std::endl;
		PG10.signAForm(*form);
		PG10.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << JB17 << "\33[0m" << std::endl;
		JB17.signAForm(*form);
		JB17.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << CS55 << "\33[0m" << std::endl;
		CS55.signAForm(*form);
		CS55.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << CL16 << "\33[0m" << std::endl;
		CL16.signAForm(*form);
		CL16.executeAForm(*form);
		std::cout << std::endl << "\33[4m" << LH44 << "\33[0m" << std::endl;
		LH44.signAForm(*form);
		LH44.executeAForm(*form);
		std::cout << std::endl;
		delete form;
	}

	// std::cout << std::endl;
	std::cout << std::endl << "*" << "\033[1;32m Destructors \033[0m------------- *" << std::endl;
	return (0);
}
