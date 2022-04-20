#include "Zombie.hpp"

Zombie::Zombie(std::string const name) : _name(name){
    std::cout << "Constructer called." << std::endl;
}

Zombie::~Zombie(void){
    std::cout << this->_name << ": Destructor called." << std::endl;
    return;
}

void Zombie::announce(void){
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
