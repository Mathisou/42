#include "Bureaucrat.hpp"

// int main(){

// 	Bureaucrat a;
// 	Bureaucrat b(0, "Biden");

// 	std::cout << a.getName() << " " << a.getGrade() << std::endl;
// 	a.GradeDown();
// 	std::cout << a.getName() << " " << a.getGrade() << std::endl;
// 	a.GradeUp();
// 	std::cout << a.getName() << " " << a.getGrade() << std::endl;

// 	std::cout << b.getName() << " " << b.getGrade() << std::endl;
// 	b.GradeUp();
// 	std::cout << b.getName() << " " << b.getGrade() << std::endl;
// 	b.GradeDown();
// 	std::cout << b.getName() << " " << b.getGrade() << std::endl;
// }

int	main()
{
	std::cout << std::endl;
	{
		Bureaucrat matthieu(150, "\033[33mMatthieu\033[0m");
		try
		{
			matthieu.GradeUp();
			std::cout << matthieu << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << matthieu << std::endl;
		}

		try
		{
			matthieu.GradeDown();
			std::cout << matthieu << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << matthieu << std::endl;
		}
	}

	std::cout << std::endl;
	{
		Bureaucrat mireille(1, "\033[34mMireille\033[0m");
		try
		{
			mireille.GradeUp();
			std::cout << mireille << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << mireille << std::endl;
		}

		try
		{
			mireille.GradeDown();
			std::cout << mireille << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			std::cout << mireille << std::endl;
		}
	}

	{
		std::cout << std::endl << "*" << "\033[1;31m Exceptions \033[0m--------------- *" << std::endl;
		Bureaucrat toto = Bureaucrat();
		Bureaucrat mick = Bureaucrat();
		try
		{
			toto = Bureaucrat(0, "\033[1mToto Wolf\033[0m");
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		try
		{
			mick = Bureaucrat(151, "\033[1mMichael Masi\033[0m");
		}
		catch (const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;

	return (0);
}
