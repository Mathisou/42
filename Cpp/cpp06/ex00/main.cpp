#include "Convert.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    Convert test(av[1]);
    test.toChar();
}
