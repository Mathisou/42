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
    for (std::vector<int>::const_iterator it = rhs._span.begin(); it != rhs._span.end(); it++)
        _span.push_back(*it);
    return *this;
}

void Span::addNumber(int nb){
    try
    {
        if (_span.size() < _N){
            _span.push_back(nb);  
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
void Span::addNumber(std::vector<int> span){
    try{
        for (std::vector<int>::iterator it = span.begin(); it != span.end(); it++){
            if (_span.size() < _N){
                _span.push_back(*it);
                std::cout << BLUE << "'" << *it << "' added to the Span." << std::endl; 
            }
            else
                throw SpanIsFull();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << std::endl;
    }
}


int Span::shortestSpan(){
    if (_span.size() > 1){
        std::sort(_span.begin(), _span.end());
        int min = *std::max_element(_span.begin(), _span.end()) - *std::min_element(_span.begin(), _span.end());
        int last;
        for (std::vector<int>::iterator it = _span.begin(); it != _span.end(); it++){
            if (it != _span.begin() && abs(*it - last) < min)
                min = abs(*it - last);
            last = *it;
        }
        return (min);
    }
    else
        throw Span::NotEnoughDistances();
}

int Span::longestSpan(){
    if (_span.size() > 1)
        return (*std::max_element(_span.begin(), _span.end()) - *std::min_element(_span.begin(), _span.end()));
    else
        throw Span::NotEnoughDistances();
}
