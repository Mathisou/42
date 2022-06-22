#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#define RED                "\x1b[31m"
#define GREEN              "\x1b[32m"
#define YELLOW             "\x1b[33m"
#define BLUE               "\x1b[34m"
#define MAGENTA            "\x1b[35m"
#define CYAN               "\x1b[36m"
#define WHITE              "\x1b[37m"

class Span{
    public :
    Span();
    Span(unsigned int nb);
	Span( Span const & src );
    ~Span();
    Span & operator=( Span const & rhs );
    void addNumber(int nb);
    void addNumber(std::vector<int> span);
    int shortestSpan();
    int longestSpan();

    class NotEnoughDistances : public std::exception
    {
        public:
            virtual const char* what() const throw(){
                return ("Not enough distances in the Span.");
            }
    };
    class SpanIsFull : public std::exception
    {
        public:
            virtual const char* what() const throw(){
                return ("The span is full.");
            }
    };

    private:
    std::vector<int> _span;
    unsigned int _N;
};

#endif