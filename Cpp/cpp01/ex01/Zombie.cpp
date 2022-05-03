#include "Zombie.hpp"

Zombie::Zombie(void){
    std::cout << "Constructer called." << std::endl;
}

Zombie::~Zombie(void){
    std::cout << "Destructor called." << std::endl;
}

void Zombie::announce(void){
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setname(std::string name){
    this->_name = name;
}
