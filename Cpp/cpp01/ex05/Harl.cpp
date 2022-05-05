#include "Harl.hpp"

Harl::Harl(void){
    return ;
}

Harl::~Harl(void){
    return ;
}

int find_index(std::string level){
    std::string tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0;i<4;i++)
        if (level.compare(tab[i]) == 0)
            return (i);
    return (-1);
}

void Harl::debug(){
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(){
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(){
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(){
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level){
    MemFuncPtr mfs[] = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int ret = find_index(level);
    if (ret == -1)
        std::cerr << "Level not found" << std::endl;
    else
        (this->*(mfs[ret]))();
}