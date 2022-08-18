#include "stack.hpp"
#include <string>
#include <iostream>
#include <stack>
int main(){
    ft::stack<std::string> mystack;
    std::stack<std::string> stack;

    std::cout << "My stack  : " << mystack.empty() << ", size: " << mystack.size() <<  std::endl;
    std::cout << "Real stack: " << stack.empty()  << ", size: " << stack.size() << std::endl;
    
    mystack.push("Hello");
    mystack.push(", ");
    mystack.push("how");
    mystack.push(" are ");
    mystack.push("you ?");
    stack.push("Hello");
    stack.push(", ");
    stack.push("how");
    stack.push(" are ");
    stack.push("you ?");
    std::cout << "My stack  : " << mystack.empty() << ", size: " << mystack.size() << ", top: " << mystack.top() <<  std::endl;
    std::cout << "Real stack: " << stack.empty()  << ", size: " << stack.size()  << ", top: " << stack.top() << std::endl;

    mystack.pop();
    mystack.pop();
    stack.pop();
    stack.pop();
    std::cout << "My stack  : " << mystack.empty() << ", size: " << mystack.size() << ", top: " << mystack.top() <<  std::endl;
    std::cout << "Real stack: " << stack.empty()  << ", size: " << stack.size()  << ", top: " << stack.top() << std::endl;
    
    mystack.pop();
    mystack.pop();
    mystack.pop();
    // mystack.pop(); // pop 1 en trop donc segfault (undefined behaviour)
    stack.pop();
    stack.pop();
    stack.pop();
    // stack.pop(); // pop 1 en trop donc segfault (undefined behaviour)
    std::cout << "My stack  : " << mystack.empty() << ", size: " << mystack.size() <<  std::endl;
    std::cout << "Real stack: " << stack.empty()  << ", size: " << stack.size() << std::endl;

    ft::stack<std::string> compare1;
    std::stack<std::string> compare2;
    mystack.push("lol");
    stack.push("lol");
    compare1.push("lol");
    compare2.push("lol");
    std::cout << std::endl << "SAME CONTENT" << std::endl;
    std::cout << "My stack   '==' : " << (mystack == compare1) << std::endl;
    std::cout << "Real stack '==' : " << (stack == compare2) << std::endl;
    std::cout << "My stack   '!=' : " << (mystack != compare1) << std::endl;
    std::cout << "Real stack '!=' : " << (stack != compare2) << std::endl;
    std::cout << "My stack   '<' : " << (mystack < compare1) << std::endl;
    std::cout << "Real stack '<' : " << (stack < compare2) << std::endl;
    std::cout << "My stack   '<=' : " << (mystack <= compare1) << std::endl;
    std::cout << "Real stack '<=' : " << (stack <= compare2) << std::endl;
    std::cout << "My stack   '>' : " << (mystack > compare1) << std::endl;
    std::cout << "Real stack '>' : " << (stack > compare2) << std::endl;
    std::cout << "My stack   '>=' : " << (mystack >= compare1) << std::endl;
    std::cout << "Real stack '>=' : " << (stack >= compare2) << std::endl;

    compare1.push("wtf");
    compare2.push("wtf");
    std::cout << std::endl << "DIFFERENT CONTENT" << std::endl;
    std::cout << "My stack   '==' : " << (mystack == compare1) << std::endl;
    std::cout << "Real stack '==' : " << (stack == compare2) << std::endl;
    std::cout << "My stack   '!=' : " << (mystack != compare1) << std::endl;
    std::cout << "Real stack '!=' : " << (stack != compare2) << std::endl;
    std::cout << "My stack   '<' : " << (mystack < compare1) << std::endl;
    std::cout << "Real stack '<' : " << (stack < compare2) << std::endl;
    std::cout << "My stack   '<=' : " << (mystack <= compare1) << std::endl;
    std::cout << "Real stack '<=' : " << (stack <= compare2) << std::endl;
    std::cout << "My stack   '>' : " << (mystack > compare1) << std::endl;
    std::cout << "Real stack '>' : " << (stack > compare2) << std::endl;
    std::cout << "My stack   '>=' : " << (mystack >= compare1) << std::endl;
    std::cout << "Real stack '>=' : " << (stack >= compare2) << std::endl;

}