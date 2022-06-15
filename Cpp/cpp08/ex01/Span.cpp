#include "Span.hpp"

Span::Span(){
    _N = 0;
}

Span::Span(unsigned int N){
    _N = N;
}

Span::Span( Span const & src ){
    *this = src;
}

Span::~Span(){
    ;
}

Span & Span::operator=( Span const & rhs ){
    _N = rhs._N;
    _span.clear();
    for (std::set<int>::iterator it = rhs._span.begin(); it != rhs._span.end(); it++)
        _span.insert(*it);
    return *this;
}

void Span::addNumber(int nb){
    try
    {
        if (_span.size() < _N){
            _span.insert(nb);  
            std::cout << BLUE << "'" << nb << "' added to the Span." << std::endl; 
        }
        else
            throw SpanIsFull();
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << std::endl;
    }
}

int Span::shortestSpan(){
    if (_span.size() > 1)
    {
        std::set<int>::iterator it;
        it = _span.begin();
        return *it;
    }
    else
        throw Span::NotEnoughDistances();
}

int Span::longestSpan(){
    if (_span.size() > 1)
    {
        std::set<int>::iterator it;
        it = _span.end();
        return *--it;
    }
    else
        throw Span::NotEnoughDistances();
}
