#include "Convert.hpp"

Convert::Convert(){
    std::cout << "Convert default constructor" << std::endl;
    _litteral = "";
}

Convert::Convert(std::string litteral) : _litteral(litteral){
    std::cout << "Convert default constructor" << std::endl;
}

Convert::~Convert(){
    std::cout << "Convert default destructor" << std::endl;
}

Convert &		Convert::operator=( Convert const & rhs ){
    std::cout << "Convert default assignation operator called" << std::endl;
    _litteral = rhs.getLitteral();
    return (*this);
}

std::string Convert::getLitteral() const{
    return this->_litteral;
}

void    Convert::setLitteral(std::string litteral){
    _litteral = litteral;
}

int count_point(std::string str){
    int count = 0;
    for (int i = 0;str[i];i++){
        if (str[i] == '.')
            count++;
    }
    return (count);
}

int isLitteralValid(std::string litteral){
    if (litteral.length() == 1 && !isprint(litteral[0])){
        std::cout << "Non displayable" << std::endl;
        return (0);
    }
    for (unsigned long i = 0;litteral[i];i++)
    {
        if (litteral[i] == '.' && count_point(litteral) != 1)
        {
            std::cout << "Impossible" << std::endl;
            return (0);
        }
        else if (!isdigit(litteral[i]) && litteral[i] != '.' && litteral[i] != 'f')
        {
            std::cout << "Impossible" << std::endl;
            return (0);
        }
        else if (litteral[i] == '.' && (i == litteral.length() - 1 || (i == litteral.length() - 2 && litteral[i + 1] == 'f')))
        {
            std::cout << "Impossible" << std::endl;
            return (0);
        }
        else if (count_point(litteral) == 0 && litteral[i] == 'f')
        {
            std::cout << "Impossible" << std::endl;
            return (0);
        }
}
    return (1);
}

void    Convert::toChar(){
    std::cout << "char: ";
    if (isLitteralValid(_litteral))
    {
        std::cout << (char)atoi(_litteral.c_str()) << std::endl;
    }
}
