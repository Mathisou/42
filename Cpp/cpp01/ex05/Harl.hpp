#include <iostream>
#include <functional>

#ifndef HARL_HPP
# define HARL_HPP

class Harl{
    private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);

    public:
    void complain(std::string level);
    Harl(void);
    ~Harl(void);
};

typedef void (Harl::*MemFuncPtr)();

#endif