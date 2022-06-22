#include "MutantStack.hpp"
#include <list>

int main()
{
    {
        std::cout << std::endl <<  "-----------------MUTANTSTACK-------------------" << std::endl << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        while (it != mstack.end())
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
    {
        std::cout << std::endl <<  "-----------------LIST-------------------" << std::endl << std::endl;
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        mstack.push_back(0);
        std::list<int>::iterator it = mstack.begin();
        while (it != mstack.end())
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }
}