#include "easyfind.hpp"

int main(){
    {
        try{
            std::string lol("Hello bro");
            int nb = 114;
            easyfind(lol, nb);
            std::cout << GREEN << "'" << static_cast<char>(nb) << "' is in \"" << lol << "\"" << std::endl;
        }
    	catch (std::exception & e)
		{
			std::cout << RED << e.what() << std::endl;
		}
    }
    {
        try{
            std::string lol("Hello bro");
            int nb = 75;
            easyfind(lol, nb);
            std::cout << GREEN << "'" << static_cast<char>(nb) << "' is in \"" << lol << "\"" << std::endl;
        }
        catch (std::exception & e)
		{
			std::cout << RED << e.what() << std::endl;
		}
    }
    {
        try{
            std::string lol("");
            int nb = 75;
            easyfind(lol, nb);
            std::cout << GREEN << "'" << static_cast<char>(nb) << "' is in \"" << lol << "\"" << std::endl;
        }
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << std::endl;
		}
    }
	{
		std::vector<int> vect;
		vect.push_back(3);
		vect.push_back(1);
		vect.push_back(2);
		vect.push_back(0);
		vect.push_back(2);
        try{
            int nb = 2;
            easyfind(vect, nb);
            std::cout << GREEN << "'" << nb << "' found in the vector." << std::endl;
        }
        catch (std::exception & e)
		{
			std::cout << RED << e.what() << std::endl;
		}
		try{
            int nb = 22;
            easyfind(vect, nb);
            std::cout << GREEN << "'" << nb << "' found in the vector." << std::endl;
        }
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << std::endl;
		}
    }
	{
		std::set<int> cont;
		cont.insert(3);
		cont.insert(4);
		cont.insert(5);
		cont.insert(0);
		cont.insert(2);
        try{
            int nb = 0;
            easyfind(cont, nb);
            std::cout << GREEN << "'" << nb << "' found in the set." << std::endl;
        }
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << std::endl;
		}
        try{
            int nb = 22;
            easyfind(cont, nb);
            std::cout << GREEN << "'" << nb << "' found in the set." << std::endl;
        }
		catch (std::exception & e)
		{
			std::cout << RED << e.what() << std::endl;
		}
    }
}
