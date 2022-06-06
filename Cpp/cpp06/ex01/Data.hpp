#ifndef DATA_HPP
# define DATA_HPP

#include "Convert.hpp"

class Data{
    private:
    std::string _name;
    int _age;

    public:
    Data();
    Data(std::string name, int age);
    ~Data();
};

#endif