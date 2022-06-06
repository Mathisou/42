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

int isLitteralValid(std::string litteral, std::string type){
    if (litteral.length() == 0)
    {
        std::cout << "Impossible" << std::endl;
        return (0);
    }
    else if (type.compare("char") == 0 && !isprint(atoi(litteral.c_str()))){
        std::cout << "Non displayable" << std::endl;
        return (0);
    }
    else if (litteral.length() == 1 && isprint(litteral[0]))
        return (1);
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
    std::cout << "Char: ";
    if (isLitteralValid(_litteral, "char"))
    {
        if (_litteral.length() == 1 && isalpha(_litteral[0]))
            std::cout << _litteral << std::endl;
        else
            std::cout << (char)atoi(_litteral.c_str()) << std::endl;
    }
}

void    Convert::toInt(){
    std::cout << "Int: ";
    if (isLitteralValid(_litteral, "int"))
    {
        if (_litteral.length() == 1 && isalpha(_litteral[0]))
            std::cout << (int)_litteral[0] << std::endl;
        else
            std::cout << atoi(_litteral.c_str()) << std::endl;
    }
}

void    Convert::toFloat(){
    // double d = strtod(_litteral.c_str(), NULL);
    double d = atoi(_litteral.c_str());
    std::cout << "Float: ";
    if (isLitteralValid(_litteral, "float"))
    {
        if (_litteral.length() == 1 && isalpha(_litteral[0]))
            std::cout << (float)_litteral[0] << std::endl;
        else
            std::cout << d << std::endl;
    }
}

void    Convert::toDouble(){
    std::cout << "Double: ";
    if (isLitteralValid(_litteral, "double"))
    {
        if (_litteral.length() == 1 && isalpha(_litteral[0]))
            std::cout << (int)_litteral[0] << std::endl;
        else
            std::cout << atoi(_litteral.c_str()) << std::endl;
    }
}
