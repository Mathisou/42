#include "Data.hpp"

int main()
{
    Data lol;
    lol.name = "Mathis";
    lol.age = 20;
    Data *ret;
    std::cout << lol.age << " " << lol.name << std::endl;
    ret = deserialize(serialize(&lol));
    std::cout << ret->age << " " << ret->name << std::endl;
}
