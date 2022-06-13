#include "easyfind.hpp"

int main(){
    {
        std::string lol("Hello bro");
        int nb = 114;
        int ret = easyfind(lol, nb);
        if (ret != -1)
            std::cout << GREEN << "'" << static_cast<char>(nb) << "' is in \"" << lol << "\" at index " << ret << "." << std::endl;
        else
            std::cout << RED << "We cannot find '" << static_cast<char>(nb) << "' in \"" << lol << "\"." << std::endl;
    }
    {
        std::string lol("Hello bro");
        int nb = 75;
        int ret = easyfind(lol, nb);
        if (ret != -1)
            std::cout << GREEN << "'" << static_cast<char>(nb) << "' is in \"" << lol << "\" at index " << ret << "." << std::endl;
        else
            std::cout << RED << "We cannot find '" << static_cast<char>(nb) << "' in \"" << lol << "\"." << std::endl;
    }
    {
        std::string lol("");
        int nb = 75;
        int ret = easyfind(lol, nb);
        if (ret != -1)
            std::cout << GREEN << "'" << static_cast<char>(nb) << "' is in \"" << lol << "\" at index " << ret << "." << std::endl;
        else
            std::cout << RED << "We cannot find '" << static_cast<char>(nb) << "' in \"" << lol << "\"." << std::endl;
    }
	{
		std::vector<int> vect;
		vect.push_back(3);
		vect.push_back(1);
		vect.push_back(2);
		vect.push_back(0);
		vect.push_back(2);
        int nb = 2;
        int ret = easyfind(vect, nb);
        if (ret != -1)
            std::cout << GREEN << "'" << nb << "' is in the vector at index " << ret << "." << std::endl;
        else
            std::cout << RED << "We cannot find '" << nb << "' in the vector." << std::endl;
		nb = 22;
        ret = easyfind(vect, nb);
        if (ret != -1)
            std::cout << GREEN << "'" << nb << "' is in the vector at index " << ret << "." << std::endl;
        else
            std::cout << RED << "We cannot find '" << nb << "' in the vector." << std::endl;
	}
	{
		std::set<int> cont;
		cont.insert(3);
		cont.insert(4);
		cont.insert(5);
		cont.insert(0);
		cont.insert(2);
        int nb = 0;
        int ret = easyfind(cont, nb);
        if (ret != -1)
            std::cout << GREEN << "'" << nb << "' is in cont at index " << ret << "." << std::endl;
        else
            std::cout << RED << "We cannot find '" << nb << "' in cont." << std::endl;
		nb = 22;
        ret = easyfind(cont, nb);
        if (ret != -1)
            std::cout << GREEN << "'" << nb << "' is in cont at index " << ret << "." << std::endl;
        else
            std::cout << RED << "We cannot find '" << nb << "' in cont." << std::endl;
	}
}
