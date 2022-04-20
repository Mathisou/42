#include <iostream>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP


class Zombie {

    private:

    std::string _name;

    public:

    void announce(void);
    Zombie(std::string const name);
    ~Zombie(void);

};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif