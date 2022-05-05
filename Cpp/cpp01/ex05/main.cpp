#include "Harl.hpp"

int main(){
    Harl yo;

    yo.complain("DEBUG");
    std::cout << std::endl;
    yo.complain("ERROR");
    std::cout << std::endl;
    yo.complain("INFO");
    std::cout << std::endl;
    yo.complain("WARNING");
    std::cout << std::endl;
    yo.complain("WARNINGE");
    return (0);
}