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

int count_after_comma(std::string str, std::string type){
    int count = 0;
    int j = 0;
    while (str[j] && str[j] != '.')
        j++;
    if (!str[j])
        return (1);
    int k = j + 1;
    while (str[k] && str[k] == '0')
        k++;
    if (!str[k] || str[k] == 'f')
        return (1);
    for (int i = j + 1;str[i];i++){
        if (isdigit(str[i]))
            count++;
    }
    if (type == "float" && count > std::numeric_limits<float>::digits10 + 1)
        return (std::numeric_limits<float>::digits10 + 1);
    else if (type == "double" && count > std::numeric_limits<double>::digits10 + 1)
        return (std::numeric_limits<double>::digits10 + 1);
    return (count);
}

int	ft_atoi(const char *nptr)
{
	size_t		i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - 48;
		if (result * sign > 2147483647)
			return (-1);
		else if (result * sign < -2147483648)
			return (0);
		i++;
	}
	return (result * sign);
}

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int isLitteralValid(std::string litteral, std::string type){
    if (litteral.length() == 0)
    {
        std::cout << "Impossible" << std::endl;
        return (0);
    }
    for (unsigned long i = 0;litteral[i];i++)
    {
        if (litteral[i] == '.' && count_point(litteral) != 1)
        {
            std::cout << "Impossible" << std::endl;
            return (0);
        }
        else if (litteral.length() > 1 && litteral[0] == '-' && !isdigit(litteral[1]))
        {
            std::cout << "Impossible" << std::endl;
            return (0);
        }
        else if (litteral.length() > 1 && !isdigit(litteral[i]) && litteral[i] != '.' && litteral[i] != 'f' && (i == 0 && litteral[i] != '-'))
        {
            std::cout << "Impossible" << std::endl;
            return (0);
        }
        else if (litteral[i] == '.' && (i == litteral.length() - 1 || (i == litteral.length() - 2 && litteral[i + 1] == 'f')))
        {
            std::cout << "Impossible" << std::endl;
            return (0);
        }
        else if (litteral.length() > 1 && count_point(litteral) == 0 && litteral[i] == 'f')
        {
            std::cout << "Impossible" << std::endl;
            return (0);
        }
    }
    if (type == "char" && litteral.length() == 1 && isalpha(litteral[0]))
        return (1);
    if (type == "char" && !ft_isprint(ft_atoi(litteral.c_str()))){
        std::cout << "Non displayable" << std::endl;
        return (0);
    }
    return (1);
}

void    Convert::toChar(){
    std::cout << "Char   :    ";
    if (isLitteralValid(_litteral, "char"))
    {
        if (_litteral.length() == 1 && isalpha(_litteral[0]))
            std::cout << _litteral << std::endl;
        else
            std::cout << static_cast<char>(ft_atoi(_litteral.c_str())) << std::endl;
    }
}

void    Convert::toInt(){
    std::cout << "Int    :    ";
    if (isLitteralValid(_litteral, "int"))
    {
        if (_litteral.length() == 1 && isalpha(_litteral[0]))
            std::cout << static_cast<int>(_litteral[0]) << std::endl;
        else
            std::cout << ft_atoi(_litteral.c_str()) << std::endl;
    }
}

void    Convert::toFloat(){
    std::cout << "Float  :    ";
    if (_litteral == "nanf" || _litteral == "-inff" || _litteral == "+inff"){
        std::cout << _litteral << std::endl;
    }
    else if (_litteral == "nan" || _litteral == "-inf" || _litteral == "+inf"){
        std::cout << _litteral << "f" << std::endl;
    }
    else if (isLitteralValid(_litteral, "float"))
    {
        if (_litteral.length() == 1 && isalpha(_litteral[0]))
            std::cout << std::fixed << std::setprecision(1) << static_cast<float>(_litteral[0]);
        else
            std::cout << std::fixed << std::setprecision(count_after_comma(_litteral, "float")) << atof(_litteral.c_str());
        std::cout << "f" << std::endl;
    }
}

void    Convert::toDouble(){
    std::cout << "Double :    ";
    if (_litteral == "nanf" || _litteral == "nan"){
        std::cout << "nan" << std::endl;
    }
    else if (_litteral == "-inff" || _litteral == "-inf"){
        std::cout << "-inf" << std::endl;
    }
    else if (_litteral == "+inff" || _litteral == "+inf"){
        std::cout << "+inf" << std::endl;
    }
    else if (isLitteralValid(_litteral, "double"))
    {
        if (_litteral.length() == 1 && isalpha(_litteral[0]))
            std::cout << std::fixed << std::setprecision(1) << static_cast<double>(_litteral[0]) << std::endl;
        else
            std::cout << std::fixed << std::setprecision(count_after_comma(_litteral, "double")) << atof(_litteral.c_str()) << std::endl;
    }
}

uintptr_t Convert::serialize(Data* ptr){
    return (static_cast<uintptr_t>(ptr));
}

Data* Convert::deserialize(uintptr_t raw){
    return (static_cast<Data*>(raw));
}

