#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <set>

#define RED                "\x1b[31m"
#define GREEN              "\x1b[32m"
#define YELLOW             "\x1b[33m"
#define BLUE               "\x1b[34m"
#define MAGENTA            "\x1b[35m"
#define CYAN               "\x1b[36m"
#define WHITE              "\x1b[37m"

template<typename T>
int easyfind(T &container, int nb){
    typename T::iterator it;
    int i = 0;

    for (it = container.begin(); it != container.end(); it++){
        if (*it == nb)
            return (i);
        i++;
    }
    return (-1);
}

#endif