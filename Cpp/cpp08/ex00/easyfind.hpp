#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

#define RED                "\x1b[31m"
#define GREEN              "\x1b[32m"
#define YELLOW             "\x1b[33m"
#define BLUE               "\x1b[34m"
#define MAGENTA            "\x1b[35m"
#define CYAN               "\x1b[36m"
#define WHITE              "\x1b[37m"

class NotFound : public std::exception
{
	virtual const char* what() const throw()
	{
		return ("Not found");
	}
};

template<typename T>
void easyfind(T &container, int nb){
    typename T::iterator it = std::find(container.begin(), container.end(), nb);
    if (it == container.end())
        throw NotFound();
}

#endif