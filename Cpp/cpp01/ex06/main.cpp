#include "Harl.hpp"

int main(int ac, char **av){
    Harl yo;

    if (ac != 2)
    {
        std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
        return 1;
    }
    yo.complain(av[1]);
    return (0);
}