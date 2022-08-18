#include <string>
#include <iostream>
#include "vector.hpp"
#include <vector>
int main()
{
	ft::vector<std::string> myvec1;
    ft::vector<std::string> myvec2;
    std::vector<std::string> vec1;
    std::vector<std::string> vec2;
    myvec2.push_back("je");
    myvec2.push_back("t'");
    myvec2.push_back("aime");
    myvec2.push_back(".");
    myvec1.push_back("lol");
    myvec1.pop_back();
    myvec1.push_back("jtm");
    myvec1.insert(myvec1.begin(), myvec2.begin(), myvec2.end());
    vec2.push_back("je");
    vec2.push_back("t'");
    vec2.push_back("aime");
    vec2.push_back(".");
    vec1.push_back("lol");
    vec1.pop_back();
    vec1.push_back("jtm");
    vec1.insert(vec1.begin(), vec2.begin(), vec2.end());
    
    
    std::cout << std::endl << "\\\\\\\\\\\\\\\\ MY VECTOR //////////////////" << std::endl << std::endl;
    for (ft::vector<std::string>::iterator it = myvec1.begin(); it != myvec1.end(); it++){
        if (it < myvec1.end() - 1)
            std::cout << *it <<  " | ";
        else
            std::cout << *it << std::endl;
    }
    std::cout << std::endl << "\\\\\\\\\\\\\\\\ REAL VECTOR //////////////////" << std::endl << std::endl;
    for (std::vector<std::string>::iterator it = vec1.begin(); it != vec1.end(); it++){
        if (it < vec1.end() - 1)
            std::cout << *it <<  " | ";
        else
            std::cout << *it << std::endl;
    }
   
    
    std::cout << std::endl << "|||||||||||||||||" << std::endl << std::endl;
    
    
    myvec1.erase(myvec1.begin() + 1, myvec1.end() - 1); // si begin - 1 comportement etrange a verif
    std::cout << std::endl << "\\\\\\\\\\\\\\\\ MY VECTOR //////////////////" << std::endl << std::endl;
    for (ft::vector<std::string>::iterator it = myvec1.begin(); it != myvec1.end(); it++){
        if (it < myvec1.end() - 1)
            std::cout << *it <<  " | ";
        else
            std::cout << *it << std::endl;
    }
    std::cout << std::endl << "\\\\\\\\\\\\\\\\ REAL VECTOR //////////////////" << std::endl << std::endl;
    vec1.erase(vec1.begin() + 1, vec1.end() - 1); // si begin - 1 comportement etrange a verif
    for (std::vector<std::string>::iterator it = vec1.begin(); it != vec1.end(); it++){
        if (it < vec1.end() - 1)
            std::cout << *it <<  " | ";
        else
            std::cout << *it << std::endl;
    }


    std::cout << std::endl << "|||||||||||||||||" << std::endl << std::endl;
    
    
    std::cout << std::endl << "\\\\\\\\\\\\\\\\ MY VECTOR //////////////////" << std::endl << std::endl;
    std::cout << "size : " << myvec1.size() << ", max_size : " << myvec1.max_size() << ", at : " << myvec1.at(1) << ", back : " << myvec1.back() << ", empty : " << myvec1.empty() << ", front : " << myvec1.front() << std::endl;
    std::cout << std::endl << "\\\\\\\\\\\\\\\\ REAL VECTOR //////////////////" << std::endl << std::endl;
    std::cout << "size : " << vec1.size() << ", max_size : " << vec1.max_size() << ", at : " << vec1.at(1) << ", back : " << vec1.back() << ", empty : " << vec1.empty() << ", front : " << vec1.front() << std::endl;


    std::cout << std::endl << "TEST REVERSE ITERATORS" << std::endl << std::endl;
    
    
    std::cout << std::endl << "\\\\\\\\\\\\\\\\ MY VECTOR //////////////////" << std::endl << std::endl;
    for (ft::vector<std::string>::reverse_iterator it = myvec1.rbegin(); it != myvec1.rend(); it++){
        if (it < myvec1.rend() - 1)
            std::cout << *it <<  " | ";
        else
            std::cout << *it << std::endl;
    }
    std::cout << std::endl << "\\\\\\\\\\\\\\\\ REAL VECTOR //////////////////" << std::endl << std::endl;
    for (std::vector<std::string>::reverse_iterator it = vec1.rbegin(); it != vec1.rend(); it++){
        if (it < vec1.rend() - 1)
            std::cout << *it <<  " | ";
        else
            std::cout << *it << std::endl;
    }
}