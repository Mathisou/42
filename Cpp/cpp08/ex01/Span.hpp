#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <set>

class Span{
    public :
    Span();
    Span(unsigned int nb);
    ~Span();
    void addNumber(int nb);
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
                return ("The span is already full.");
            }
    };

    private:
    std::set<int> _span;
    unsigned int _N;
};

#endif