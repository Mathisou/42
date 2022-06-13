#include "Span.hpp"

int main(){
    {
        Span test(5);
        test.addNumber(2);
        test.addNumber(18);
        test.addNumber(-2);
        test.addNumber(0);
        test.addNumber(12);
        test.addNumber(1);
        std::cout << test.longestSpan() << std::endl;
        std::cout << test.shortestSpan() << std::endl;
    }
    {
        Span test(1);
        test.addNumber(2);
        std::cout << test.longestSpan() << std::endl;
        std::cout << test.shortestSpan() << std::endl;
    }
}