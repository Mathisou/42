#include <iostream>
#include <fstream>
#include <string.h>

int main(int ac, char **av)
{
	size_t index = 0;
	std::string ntm(av[1]);

	if (ac != 4)
		return 1;
	std::ifstream in(ntm.c_str());
	ntm += ".replace";
	std::ofstream out(ntm.c_str(), std::ios::out);
	std::string line;

	if (!in.is_open()){
		std::cout << "Cannot open: " << av[1] << std::endl;
		return (1);
	}
	if (!out.is_open()){
		in.close();
		std::cout << "Cannot open: " << std::endl;
		return (2);
	}
	else
	{
		std::getline(in, line);
		while (true){
			index = line.find(av[2]);
			if (index == std::string::npos)
				break;
			line.erase(index, strlen(av[2]));
			line.insert(index, av[3]);
		}
   		while (!in.eof()) {
			out << line << std::endl;
			std::getline(in, line);
			while (true){
				index = line.find(av[2]);
				if (index == std::string::npos)
					break;
				line.erase(index, strlen(av[2]));
				line.insert(index, av[3]);
			}
		}
	}
	in.close();
	out.close();
}