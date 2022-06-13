#include <iostream>
#include <fstream>
#include <string.h>

int main(int ac, char **av)
{
	size_t index = 0;
	int pos = 0;
	std::string tmp;

	if (ac != 4)
		return 1;
	std::string str(av[1]);
	std::ifstream in(str.c_str());
	str += ".replace";
	std::ofstream out(str.c_str(), std::ios::out);
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
			tmp = &line[pos];
			index = tmp.find(av[2]);
			if (index == std::string::npos)
				break;
			line.erase(pos, line.length());
			tmp.erase(index, strlen(av[2]));
			tmp.insert(index, av[3]);
			pos = index + line.length() + strlen(av[3]);
			line += tmp;
		}
   		while (!in.eof()) {
			pos = 0;
			out << line << std::endl;
			std::getline(in, line);
			while (true){
				tmp = &line[pos];
				index = tmp.find(av[2]);
				if (index == std::string::npos)
					break;
				line.erase(pos, line.length());
				tmp.erase(index, strlen(av[2]));
				tmp.insert(index, av[3]);
				pos = index + line.length() + strlen(av[3]);
				line += tmp;
			}
		}
	}
	in.close();
	out.close();
}