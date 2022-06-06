#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <stdlib.h>
# include <iomanip>
# include <limits>
# include <string.h>

class Data;

class Convert
{
    private:
    std::string _litteral;

    public:
    Convert();
    Convert(std::string litteral);
    Convert( Convert const & src );
	~Convert(void);

	Convert &		operator=( Convert const & rhs );

    std::string getLitteral() const;
    void setLitteral(std::string litteral);
    void toChar();
    void toInt();
    void toFloat();
    void toDouble();
    uintptr_t serialize(Data* ptr);
    Data* deserialize(uintptr_t raw);
};

#endif