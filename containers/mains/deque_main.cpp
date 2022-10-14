#include <string>
#include <iostream>
#include "../deque.hpp"
#include <deque>
#include <fstream>
int main()
{
    std::ofstream mydeque_outfile("outfiles/mydeque.txt");
    std::ofstream deque_outfile("outfiles/deque.txt");
    {
        ft::deque<std::string> mydeq1;
        ft::deque<std::string> mydeq2;
        std::deque<std::string> deq1;
        std::deque<std::string> deq2;
        mydeq2.push_back("je");
        mydeq2.push_back("t'");
        mydeq2.push_back("aime");
        mydeq2.pop_front();
        mydeq2.push_back(".");
        mydeq1.push_back("lol");
        mydeq1.pop_back();
        mydeq1.push_back("jtm");
        mydeq1.push_back("jtm");
        mydeq1.push_back("jtm");
        mydeq1.push_front("front");
        mydeq1.insert(mydeq1.begin(), mydeq2.begin(), mydeq2.end());
        deq2.push_back("je");
        deq2.push_back("t'");
        deq2.push_back("aime");
        deq2.pop_front();
        deq2.push_back(".");
        deq1.push_back("lol");
        deq1.pop_back();
        deq1.push_back("jtm");
        deq1.push_back("jtm");
        deq1.push_back("jtm");
        deq1.push_front("front");
        deq1.insert(deq1.begin(), deq2.begin(), deq2.end());
        

        mydeque_outfile << std::endl << "TEST WITH STRINGS" << std::endl << std::endl;
        deque_outfile << std::endl << "TEST WITH STRINGS" << std::endl << std::endl;
        for (ft::deque<std::string>::iterator it = mydeq1.begin(); it != mydeq1.end(); it++){
            if (it < mydeq1.end() - 1)
                mydeque_outfile << *it <<  " | ";
            else
                mydeque_outfile << *it << std::endl;
        }
        for (std::deque<std::string>::iterator it = deq1.begin(); it != deq1.end(); it++){
            if (it < deq1.end() - 1)
                deque_outfile << *it <<  " | ";
            else
                deque_outfile << *it << std::endl;
        }
    
        
        mydeque_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;
        deque_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;
        
        
        mydeq1.erase(mydeq1.begin() + 1, mydeq1.end() - 1);
        for (ft::deque<std::string>::iterator it = mydeq1.begin(); it != mydeq1.end(); it++){
            if (it < mydeq1.end() - 1)
                mydeque_outfile << *it <<  " | ";
            else
                mydeque_outfile << *it << std::endl;
        }
        deq1.erase(deq1.begin() + 1, deq1.end() - 1);
        for (std::deque<std::string>::iterator it = deq1.begin(); it != deq1.end(); it++){
            if (it < deq1.end() - 1)
                deque_outfile << *it <<  " | ";
            else
                deque_outfile << *it << std::endl;
        }


        mydeque_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;
        deque_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;
        
        
        mydeque_outfile << "size : " << mydeq1.size() << ", max_size : " << mydeq1.max_size() << ", at : ";
        try
        {
          mydeque_outfile << mydeq1.at(1);  
        }
        catch (std::exception e)
        {
            mydeque_outfile << e.what();
        }
        mydeque_outfile << ", back : " << mydeq1.back() << ", empty : " << mydeq1.empty() << ", front : " << mydeq1.front() << std::endl;
        
        deque_outfile << "size : " << deq1.size() << ", max_size : " << deq1.max_size() << ", at : ";
        try
        {
            deque_outfile << deq1.at(1);  
        }
        catch (std::exception e)
        {
            deque_outfile << e.what();
        }
        deque_outfile << ", back : " << deq1.back() << ", empty : " << deq1.empty() << ", front : " << deq1.front() << std::endl;


        mydeque_outfile << std::endl << std::endl << "TEST REVERSE ITERATORS" << std::endl;
        deque_outfile << std::endl << std::endl << "TEST REVERSE ITERATORS" << std::endl;
        
        
        for (ft::deque<std::string>::reverse_iterator it = mydeq1.rbegin(); it != mydeq1.rend(); it++){
            if (it < mydeq1.rend() - 1)
                mydeque_outfile << *it <<  " | ";
            else
                mydeque_outfile << *it << std::endl;
        }
        for (std::deque<std::string>::reverse_iterator it = deq1.rbegin(); it != deq1.rend(); it++){
            if (it < deq1.rend() - 1)
                deque_outfile << *it <<  " | ";
            else
                deque_outfile << *it << std::endl;
        }

        mydeq1.pop_back();
        mydeq1.pop_back();
        deq1.pop_back();
        deq1.pop_back();
        ft::deque<std::string> compare1;
        std::deque<std::string> compare2;
        mydeq1.push_back("lol");
        deq1.push_back("lol");
        compare1.push_back("lol");
        compare2.push_back("lol");
        mydeque_outfile << std::endl << "SAME CONTENT" << std::endl;
        deque_outfile << std::endl << "SAME CONTENT" << std::endl;
        mydeque_outfile << "'==' : " << (mydeq1 == compare1) << std::endl;
        deque_outfile << "'==' : " << (deq1 == compare2) << std::endl;
        mydeque_outfile << "'!=' : " << (mydeq1 != compare1) << std::endl;
        deque_outfile << "'!=' : " << (deq1 != compare2) << std::endl;
        mydeque_outfile << "'<' : " << (mydeq1 < compare1) << std::endl;
        deque_outfile << "'<' : " << (deq1 < compare2) << std::endl;
        mydeque_outfile << "'<=' : " << (mydeq1 <= compare1) << std::endl;
        deque_outfile << "'<=' : " << (deq1 <= compare2) << std::endl;
        mydeque_outfile << "'>' : " << (mydeq1 > compare1) << std::endl;
        deque_outfile << "'>' : " << (deq1 > compare2) << std::endl;
        mydeque_outfile << "'>=' : " << (mydeq1 >= compare1) << std::endl;
        deque_outfile << "'>=' : " << (deq1 >= compare2) << std::endl;

        compare1.push_back("wtf");
        compare2.push_back("wtf");
        mydeque_outfile << std::endl << "DIFFERENT CONTENT" << std::endl;
        deque_outfile << std::endl << "DIFFERENT CONTENT" << std::endl;
        mydeque_outfile << "'==' : " << (mydeq1 == compare1) << std::endl;
        deque_outfile << "'==' : " << (deq1 == compare2) << std::endl;
        mydeque_outfile << "'!=' : " << (mydeq1 != compare1) << std::endl;
        deque_outfile << "'!=' : " << (deq1 != compare2) << std::endl;
        mydeque_outfile << "'<' : " << (mydeq1 < compare1) << std::endl;
        deque_outfile << "'<' : " << (deq1 < compare2) << std::endl;
        mydeque_outfile << "'<=' : " << (mydeq1 <= compare1) << std::endl;
        deque_outfile << "'<=' : " << (deq1 <= compare2) << std::endl;
        mydeque_outfile << "'>' : " << (mydeq1 > compare1) << std::endl;
        deque_outfile << "'>' : " << (deq1 > compare2) << std::endl;
        mydeque_outfile << "'>=' : " << (mydeq1 >= compare1) << std::endl;
        deque_outfile << "'>=' : " << (deq1 >= compare2) << std::endl;
    }

    
    {
        ft::deque<int> mydeq1;
        ft::deque<int> mydeq2;
        std::deque<int> deq1;
        std::deque<int> deq2;
        mydeq2.push_back(1);
        mydeq2.push_back(2);
        mydeq2.push_back(3);
        mydeq2.push_back(4);
        mydeq1.push_back(5);
        mydeq1.pop_back();
        mydeq1.push_back(6);
        mydeq1.insert(mydeq1.begin(), mydeq2.begin(), mydeq2.end());
        deq2.push_back(1);
        deq2.push_back(2);
        deq2.push_back(3);
        deq2.push_back(4);
        deq1.push_back(5);
        deq1.pop_back();
        deq1.push_back(6);
        deq1.insert(deq1.begin(), deq2.begin(), deq2.end());
        

        mydeque_outfile << std::endl << std::endl << "TEST WITH INTS" << std::endl  << std::endl;
        deque_outfile << std::endl << std::endl << "TEST WITH INTS" << std::endl  << std::endl;
        for (ft::deque<int>::iterator it = mydeq1.begin(); it != mydeq1.end(); it++){
            if (it < mydeq1.end() - 1)
                mydeque_outfile << *it <<  " | ";
            else
                mydeque_outfile << *it << std::endl;
        }
        for (std::deque<int>::iterator it = deq1.begin(); it != deq1.end(); it++){
            if (it < deq1.end() - 1)
                deque_outfile << *it <<  " | ";
            else
                deque_outfile << *it << std::endl;
        }
    
        
        mydeque_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;
        deque_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;

        
        mydeq1.erase(mydeq1.begin() + 1, mydeq1.end() - 1);
        for (ft::deque<int>::iterator it = mydeq1.begin(); it != mydeq1.end(); it++){
            if (it < mydeq1.end() - 1)
                mydeque_outfile << *it <<  " | ";
            else
                mydeque_outfile << *it << std::endl;
        }
        deq1.erase(deq1.begin() + 1, deq1.end() - 1);
        for (std::deque<int>::iterator it = deq1.begin(); it != deq1.end(); it++){
            if (it < deq1.end() - 1)
                deque_outfile << *it <<  " | ";
            else
                deque_outfile << *it << std::endl;
        }


        mydeque_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;
        deque_outfile << std::endl << "|||||||||||||||||" << std::endl << std::endl;
        
        mydeque_outfile << "size : " << mydeq1.size() << ", max_size : " << mydeq1.max_size() << ", at : ";
        try
        {
          mydeque_outfile << mydeq1.at(20);  
        }
        catch (std::exception e)
        {
            mydeque_outfile << e.what();
        }
        mydeque_outfile << ", back : " << mydeq1.back() << ", empty : " << mydeq1.empty() << ", front : " << mydeq1.front() << std::endl;
        
        deque_outfile << "size : " << deq1.size() << ", max_size : " << deq1.max_size() << ", at : ";
        try
        {
          deque_outfile << deq1.at(20);  
        }
        catch (std::exception e)
        {
            deque_outfile << e.what();
        }
        deque_outfile << ", back : " << deq1.back() << ", empty : " << deq1.empty() << ", front : " << deq1.front() << std::endl;


        mydeque_outfile << std::endl << std::endl << "TEST REVERSE ITERATORS" << std::endl;
        deque_outfile << std::endl << std::endl << "TEST REVERSE ITERATORS" << std::endl;
        
        for (ft::deque<int>::reverse_iterator it = mydeq1.rbegin(); it != mydeq1.rend(); it++){
            if (it < mydeq1.rend() - 1)
                mydeque_outfile << *it <<  " | ";
            else
                mydeque_outfile << *it << std::endl;
        }
        for (std::deque<int>::reverse_iterator it = deq1.rbegin(); it != deq1.rend(); it++){
            if (it < deq1.rend() - 1)
                deque_outfile << *it <<  " | ";
            else
                deque_outfile << *it << std::endl;
        }

        mydeq1.pop_back();
        mydeq1.pop_back();
        deq1.pop_back();
        deq1.pop_back();
        ft::deque<int> compare1;
        std::deque<int> compare2;
        mydeq1.push_back(12);
        deq1.push_back(12);
        compare1.push_back(12);
        compare2.push_back(12);
        mydeque_outfile << std::endl << "SAME CONTENT" << std::endl;
        deque_outfile << std::endl << "SAME CONTENT" << std::endl;
        mydeque_outfile << "'==' : " << (mydeq1 == compare1) << std::endl;
        deque_outfile << "'==' : " << (deq1 == compare2) << std::endl;
        mydeque_outfile << "'!=' : " << (mydeq1 != compare1) << std::endl;
        deque_outfile << "'!=' : " << (deq1 != compare2) << std::endl;
        mydeque_outfile << "'<' : " << (mydeq1 < compare1) << std::endl;
        deque_outfile << "'<' : " << (deq1 < compare2) << std::endl;
        mydeque_outfile << "'<=' : " << (mydeq1 <= compare1) << std::endl;
        deque_outfile << "'<=' : " << (deq1 <= compare2) << std::endl;
        mydeque_outfile << "'>' : " << (mydeq1 > compare1) << std::endl;
        deque_outfile << "'>' : " << (deq1 > compare2) << std::endl;
        mydeque_outfile << "'>=' : " << (mydeq1 >= compare1) << std::endl;
        deque_outfile << "'>=' : " << (deq1 >= compare2) << std::endl;

        compare1.push_back(14);
        compare2.push_back(14);
        mydeque_outfile << std::endl << "DIFFERENT CONTENT" << std::endl;
        deque_outfile << std::endl << "DIFFERENT CONTENT" << std::endl;
        mydeque_outfile << "'==' : " << (mydeq1 == compare1) << std::endl;
        deque_outfile << "'==' : " << (deq1 == compare2) << std::endl;
        mydeque_outfile << "'!=' : " << (mydeq1 != compare1) << std::endl;
        deque_outfile << "'!=' : " << (deq1 != compare2) << std::endl;
        mydeque_outfile << "'<' : " << (mydeq1 < compare1) << std::endl;
        deque_outfile << "'<' : " << (deq1 < compare2) << std::endl;
        mydeque_outfile << "'<=' : " << (mydeq1 <= compare1) << std::endl;
        deque_outfile << "'<=' : " << (deq1 <= compare2) << std::endl;
        mydeque_outfile << "'>' : " << (mydeq1 > compare1) << std::endl;
        deque_outfile << "'>' : " << (deq1 > compare2) << std::endl;
        mydeque_outfile << "'>=' : " << (mydeq1 >= compare1) << std::endl;
        deque_outfile << "'>=' : " << (deq1 >= compare2) << std::endl;
    }
}