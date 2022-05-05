#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;

	std::string &stringREF = str;

	std::cout	<< "Address of str:                 " << &str << std::endl
				<< "Address of str's pointer:       " << stringPTR << std::endl
				<< "Address of str's reference:     " << &stringREF << std::endl;

	std::cout	<< "Value of str:                   " << str << std::endl
				<< "Value of str's pointer:         " << *stringPTR << std::endl
				<< "Value of str's reference:       " << stringREF << std::endl;
}