#include "Zombie.hpp"

int main(int ac,char **av)
{
    (void)av;
    if (ac != 1)
        return (1);

    randomChump("coucou");

    Zombie *zb;
    zb = newZombie("yo");
    zb->announce();
    delete zb;
    zb = zombieHorde
}