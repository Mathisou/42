#ifndef DATA_HPP
# define DATA_HPP

# include <stdint.h>
# include <iostream>
# include <string>
# include <stdlib.h>
# include <iomanip>
# include <limits>
# include <string.h>

struct Data{
    std::string name;
    int age;
};

uintptr_t serialize(Data* ptr);

Data* deserialize(uintptr_t raw);

#endif