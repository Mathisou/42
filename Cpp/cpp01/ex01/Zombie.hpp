#include <iostream>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP


class Zombie {

    private:

    std::string _name;

    public:

    void announce(void);
    void setname(std::string name);
    Zombie(void);
    ~Zombie(void);

};

Zombie* zombieHorde( int N, std::string name );

#endif