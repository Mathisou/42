#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
		return 1;
	std::ifstream in(av[1]);
	std::ofstream out((std::string)av[1] + ".replace");
	std::string line;

	if (!in.is_open())
		std::cout << "wtf" << std::endl;
	if (!out.is_open())
		std::cout << "wtf2" << std::endl;
	else
	{
		in >> line;
   		while ( in ) {
    		out << line << std::endl;
     	 	in >> line;
   }
	}
	in.close();
	out.close();
}