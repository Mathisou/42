#include "Span.hpp"

int main(){
    {
        Span test(5);
        test.addNumber(2);
        test.addNumber(18);
        test.addNumber(-2);
        test.addNumber(0);
        test.addNumber(0);
        test.addNumber(19);
        try{
            int ret = test.longestSpan();
            std::cout << GREEN << "The longest distance in the Span is : " << ret << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << std::endl;
        }
        try{
            int ret = test.shortestSpan();
            std::cout << GREEN << "The shortest distance in the Span is : " << ret << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << std::endl;
        }
    }
    {
        Span test(5);
        std::vector<int> vec;
        for (int i = 0;i<7; i++)
            vec.push_back(i);
        test.addNumber(vec);
        try{
            int ret = test.longestSpan();
            std::cout << GREEN << "The longest distance in the Span is : " << ret << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << std::endl;
        }
        try{
            int ret = test.shortestSpan();
            std::cout << GREEN << "The shortest distance in the Span is : " << ret << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << std::endl;
        }
    }
    {
        Span test(1);
        test.addNumber(2);
        try{
            int ret = test.longestSpan();
            std::cout << GREEN << "The longest distance in the Span is : " << ret << std::endl;
        }   
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << std::endl;
        }
        try{
            int ret = test.shortestSpan();
            std::cout << GREEN << "The shortest distance in the Span is : " << ret << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << std::endl;
        }
    }
}