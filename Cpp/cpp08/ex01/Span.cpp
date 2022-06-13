#include "Span.hpp"

Span::Span(){
    _N = 0;
}

Span::Span(unsigned int N){
    _N = N;
}

Span::~Span(){
    ;
}

void Span::addNumber(int nb){
    if (_span.size() >= _N)
        throw Span::SpanIsFull();
    else
        _span.insert(nb);
    // if (_span.size() < _N)
    //     _span.insert(nb);
    // else
    //     throw SpanIsFull();
}

int Span::shortestSpan(){
    if (_span.size() > 1)
    {
        std::set<int>::iterator it;
        it = _span.begin();
        return *it;
    }
    // else
    //     throw Span::NotEnoughDistances();
    return -1;
}

int Span::longestSpan(){
    if (_span.size() > 1)
    {
        std::set<int>::iterator it;
        it = _span.end();
        return *it;
    }
    // else
    //     throw Span::NotEnoughDistances();
    return -1;
}
