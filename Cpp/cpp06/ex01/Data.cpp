#include "Data.hpp"

Data::Data(){
    std::cout << "Data default constructor called" << std::endl;
    _name = "null";
    _age = 0;
}

Data::Data(std::string name, int age) : _name(name), _age(age){
    std::cout << "Data default constructor called" << std::endl;

}

Data::Data(){
    std::cout << "Data destructor called" << std::endl;

}
