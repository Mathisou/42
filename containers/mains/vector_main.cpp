#include <string>
#include <iostream>
#include "../vector.hpp"
#include <vector>
#include <fstream>
int main()
{
    std::ofstream myvector_outfile("outfiles/myvector.txt");
    std::ofstream vector_outfile("outfiles/vector.txt");
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
        

        myvector_outfile << std::endl << "TEST WITH STRINGS" << std::endl << std::endl;
        vector_outfile << std::endl << "TEST WITH STRINGS" << std::endl << std::endl;
        for (ft::vector<std::string>::iterator it = myvec1.begin(); it != myvec1.end(); it++){
            if (it < myvec1.end() - 1)
                myvector_outfile << *it <<  " | ";
            else
                myvector_outfile << *it << std::endl;
        }
        for (std::vector<std::string>::iterator it = vec1.begin(); it != vec1.end(); it++){
            if (it < vec1.end() - 1)
                vector_outfile << *it <<  " | ";
            else
                vector_outfile << *it << std::endl;
        }
    
        
        myvector_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;
        vector_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;
        
        
        myvec1.erase(myvec1.begin() + 1, myvec1.end() - 1);
        for (ft::vector<std::string>::iterator it = myvec1.begin(); it != myvec1.end(); it++){
            if (it < myvec1.end() - 1)
                myvector_outfile << *it <<  " | ";
            else
                myvector_outfile << *it << std::endl;
        }
        vec1.erase(vec1.begin() + 1, vec1.end() - 1);
        for (std::vector<std::string>::iterator it = vec1.begin(); it != vec1.end(); it++){
            if (it < vec1.end() - 1)
                vector_outfile << *it <<  " | ";
            else
                vector_outfile << *it << std::endl;
        }


        myvector_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;
        vector_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;
        
        
        myvector_outfile << "size : " << myvec1.size() << ", max_size : " << myvec1.max_size() << ", at : ";
        try
        {
          myvector_outfile << myvec1.at(1);  
        }
        catch (std::exception e)
        {
            myvector_outfile << e.what();
        }
        myvector_outfile << ", back : " << myvec1.back() << ", empty : " << myvec1.empty() << ", front : " << myvec1.front() << std::endl;
        
        vector_outfile << "size : " << vec1.size() << ", max_size : " << vec1.max_size() << ", at : ";
        try
        {
            vector_outfile << vec1.at(1);  
        }
        catch (std::exception e)
        {
            vector_outfile << e.what();
        }
        vector_outfile << ", back : " << vec1.back() << ", empty : " << vec1.empty() << ", front : " << vec1.front() << std::endl;


        myvector_outfile << std::endl << std::endl << "TEST REVERSE ITERATORS" << std::endl;
        vector_outfile << std::endl << std::endl << "TEST REVERSE ITERATORS" << std::endl;
        
        
        for (ft::vector<std::string>::reverse_iterator it = myvec1.rbegin(); it != myvec1.rend(); it++){
            if (it < myvec1.rend() - 1)
                myvector_outfile << *it <<  " | ";
            else
                myvector_outfile << *it << std::endl;
        }
        for (std::vector<std::string>::reverse_iterator it = vec1.rbegin(); it != vec1.rend(); it++){
            if (it < vec1.rend() - 1)
                vector_outfile << *it <<  " | ";
            else
                vector_outfile << *it << std::endl;
        }

        myvec1.pop_back();
        myvec1.pop_back();
        vec1.pop_back();
        vec1.pop_back();
        ft::vector<std::string> compare1;
        std::vector<std::string> compare2;
        myvec1.push_back("lol");
        vec1.push_back("lol");
        compare1.push_back("lol");
        compare2.push_back("lol");
        myvector_outfile << std::endl << "SAME CONTENT" << std::endl;
        vector_outfile << std::endl << "SAME CONTENT" << std::endl;
        myvector_outfile << "'==' : " << (myvec1 == compare1) << std::endl;
        vector_outfile << "'==' : " << (vec1 == compare2) << std::endl;
        myvector_outfile << "'!=' : " << (myvec1 != compare1) << std::endl;
        vector_outfile << "'!=' : " << (vec1 != compare2) << std::endl;
        myvector_outfile << "'<' : " << (myvec1 < compare1) << std::endl;
        vector_outfile << "'<' : " << (vec1 < compare2) << std::endl;
        myvector_outfile << "'<=' : " << (myvec1 <= compare1) << std::endl;
        vector_outfile << "'<=' : " << (vec1 <= compare2) << std::endl;
        myvector_outfile << "'>' : " << (myvec1 > compare1) << std::endl;
        vector_outfile << "'>' : " << (vec1 > compare2) << std::endl;
        myvector_outfile << "'>=' : " << (myvec1 >= compare1) << std::endl;
        vector_outfile << "'>=' : " << (vec1 >= compare2) << std::endl;

        compare1.push_back("wtf");
        compare2.push_back("wtf");
        myvector_outfile << std::endl << "DIFFERENT CONTENT" << std::endl;
        vector_outfile << std::endl << "DIFFERENT CONTENT" << std::endl;
        myvector_outfile << "'==' : " << (myvec1 == compare1) << std::endl;
        vector_outfile << "'==' : " << (vec1 == compare2) << std::endl;
        myvector_outfile << "'!=' : " << (myvec1 != compare1) << std::endl;
        vector_outfile << "'!=' : " << (vec1 != compare2) << std::endl;
        myvector_outfile << "'<' : " << (myvec1 < compare1) << std::endl;
        vector_outfile << "'<' : " << (vec1 < compare2) << std::endl;
        myvector_outfile << "'<=' : " << (myvec1 <= compare1) << std::endl;
        vector_outfile << "'<=' : " << (vec1 <= compare2) << std::endl;
        myvector_outfile << "'>' : " << (myvec1 > compare1) << std::endl;
        vector_outfile << "'>' : " << (vec1 > compare2) << std::endl;
        myvector_outfile << "'>=' : " << (myvec1 >= compare1) << std::endl;
        vector_outfile << "'>=' : " << (vec1 >= compare2) << std::endl;
    }

    
    {
        ft::vector<int> myvec1;
        ft::vector<int> myvec2;
        std::vector<int> vec1;
        std::vector<int> vec2;
        myvec2.push_back(1);
        myvec2.push_back(2);
        myvec2.push_back(3);
        myvec2.push_back(4);
        myvec1.push_back(5);
        myvec1.pop_back();
        myvec1.push_back(6);
        myvec1.insert(myvec1.begin(), myvec2.begin(), myvec2.end());
        vec2.push_back(1);
        vec2.push_back(2);
        vec2.push_back(3);
        vec2.push_back(4);
        vec1.push_back(5);
        vec1.pop_back();
        vec1.push_back(6);
        vec1.insert(vec1.begin(), vec2.begin(), vec2.end());
        

        myvector_outfile << std::endl << std::endl << "TEST WITH INTS" << std::endl  << std::endl;
        vector_outfile << std::endl << std::endl << "TEST WITH INTS" << std::endl  << std::endl;
        for (ft::vector<int>::iterator it = myvec1.begin(); it != myvec1.end(); it++){
            if (it < myvec1.end() - 1)
                myvector_outfile << *it <<  " | ";
            else
                myvector_outfile << *it << std::endl;
        }
        for (std::vector<int>::iterator it = vec1.begin(); it != vec1.end(); it++){
            if (it < vec1.end() - 1)
                vector_outfile << *it <<  " | ";
            else
                vector_outfile << *it << std::endl;
        }
    
        
        myvector_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;
        vector_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;

        
        myvec1.erase(myvec1.begin() + 1, myvec1.end() - 1);
        for (ft::vector<int>::iterator it = myvec1.begin(); it != myvec1.end(); it++){
            if (it < myvec1.end() - 1)
                myvector_outfile << *it <<  " | ";
            else
                myvector_outfile << *it << std::endl;
        }
        vec1.erase(vec1.begin() + 1, vec1.end() - 1);
        for (std::vector<int>::iterator it = vec1.begin(); it != vec1.end(); it++){
            if (it < vec1.end() - 1)
                vector_outfile << *it <<  " | ";
            else
                vector_outfile << *it << std::endl;
        }


        myvector_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;
        vector_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;
        
        myvector_outfile << "size : " << myvec1.size() << ", max_size : " << myvec1.max_size() << ", at : ";
        try
        {
          myvector_outfile << myvec1.at(20);  
        }
        catch (std::exception e)
        {
            myvector_outfile << e.what();
        }
        myvector_outfile << ", back : " << myvec1.back() << ", empty : " << myvec1.empty() << ", front : " << myvec1.front() << std::endl;
        
        vector_outfile << "size : " << vec1.size() << ", max_size : " << vec1.max_size() << ", at : ";
        try
        {
          vector_outfile << vec1.at(20);  
        }
        catch (std::exception e)
        {
            vector_outfile << e.what();
        }
        vector_outfile << ", back : " << vec1.back() << ", empty : " << vec1.empty() << ", front : " << vec1.front() << std::endl;


        myvector_outfile << std::endl << std::endl << "TEST REVERSE ITERATORS" << std::endl;
        vector_outfile << std::endl << std::endl << "TEST REVERSE ITERATORS" << std::endl;
        
        for (ft::vector<int>::reverse_iterator it = myvec1.rbegin(); it != myvec1.rend(); it++){
            if (it < myvec1.rend() - 1)
                myvector_outfile << *it <<  " | ";
            else
                myvector_outfile << *it << std::endl;
        }
        for (std::vector<int>::reverse_iterator it = vec1.rbegin(); it != vec1.rend(); it++){
            if (it < vec1.rend() - 1)
                vector_outfile << *it <<  " | ";
            else
                vector_outfile << *it << std::endl;
        }

        myvec1.pop_back();
        myvec1.pop_back();
        vec1.pop_back();
        vec1.pop_back();
        ft::vector<int> compare1;
        std::vector<int> compare2;
        myvec1.push_back(12);
        vec1.push_back(12);
        compare1.push_back(12);
        compare2.push_back(12);
        myvector_outfile << std::endl << "SAME CONTENT" << std::endl;
        vector_outfile << std::endl << "SAME CONTENT" << std::endl;
        myvector_outfile << "'==' : " << (myvec1 == compare1) << std::endl;
        vector_outfile << "'==' : " << (vec1 == compare2) << std::endl;
        myvector_outfile << "'!=' : " << (myvec1 != compare1) << std::endl;
        vector_outfile << "'!=' : " << (vec1 != compare2) << std::endl;
        myvector_outfile << "'<' : " << (myvec1 < compare1) << std::endl;
        vector_outfile << "'<' : " << (vec1 < compare2) << std::endl;
        myvector_outfile << "'<=' : " << (myvec1 <= compare1) << std::endl;
        vector_outfile << "'<=' : " << (vec1 <= compare2) << std::endl;
        myvector_outfile << "'>' : " << (myvec1 > compare1) << std::endl;
        vector_outfile << "'>' : " << (vec1 > compare2) << std::endl;
        myvector_outfile << "'>=' : " << (myvec1 >= compare1) << std::endl;
        vector_outfile << "'>=' : " << (vec1 >= compare2) << std::endl;

        compare1.push_back(14);
        compare2.push_back(14);
        myvector_outfile << std::endl << "DIFFERENT CONTENT" << std::endl;
        vector_outfile << std::endl << "DIFFERENT CONTENT" << std::endl;
        myvector_outfile << "'==' : " << (myvec1 == compare1) << std::endl;
        vector_outfile << "'==' : " << (vec1 == compare2) << std::endl;
        myvector_outfile << "'!=' : " << (myvec1 != compare1) << std::endl;
        vector_outfile << "'!=' : " << (vec1 != compare2) << std::endl;
        myvector_outfile << "'<' : " << (myvec1 < compare1) << std::endl;
        vector_outfile << "'<' : " << (vec1 < compare2) << std::endl;
        myvector_outfile << "'<=' : " << (myvec1 <= compare1) << std::endl;
        vector_outfile << "'<=' : " << (vec1 <= compare2) << std::endl;
        myvector_outfile << "'>' : " << (myvec1 > compare1) << std::endl;
        vector_outfile << "'>' : " << (vec1 > compare2) << std::endl;
        myvector_outfile << "'>=' : " << (myvec1 >= compare1) << std::endl;
        vector_outfile << "'>=' : " << (vec1 >= compare2) << std::endl;
    }
}