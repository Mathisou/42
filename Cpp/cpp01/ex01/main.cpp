#include "Zombie.hpp"

int main(int ac,char **av)
{
    (void)av;
    if (ac != 1)
        return (1);
    Zombie *zb;
    zb = zombieHorde(5, "mdr");
    for (int i = 0;i<5;i++)
        zb[i].announce();
    delete [] zb;
}