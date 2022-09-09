#include "../stack.hpp"
#include <string>
#include <iostream>
#include <stack>
#include <fstream>
int main(){
    std::ofstream mystack_outfile("outfiles/mystack.txt");
    std::ofstream stack_outfile("outfiles/stack.txt");
    {
        ft::stack<std::string> mystack;
        std::stack<std::string> stack;

        mystack_outfile << std::endl << "TEST WITH STRINGS" << std::endl  << std::endl;
        stack_outfile << std::endl << "TEST WITH STRINGS" << std::endl  << std::endl;

        mystack_outfile << mystack.empty() << ", size: " << mystack.size() <<  std::endl;
        stack_outfile << stack.empty()  << ", size: " << stack.size() << std::endl;
        
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
        mystack_outfile << mystack.empty() << ", size: " << mystack.size() << ", top: " << mystack.top() <<  std::endl;
        stack_outfile << stack.empty()  << ", size: " << stack.size()  << ", top: " << stack.top() << std::endl;

        mystack.pop();
        mystack.pop();
        stack.pop();
        stack.pop();
        mystack_outfile << mystack.empty() << ", size: " << mystack.size() << ", top: " << mystack.top() <<  std::endl;
        stack_outfile << stack.empty()  << ", size: " << stack.size()  << ", top: " << stack.top() << std::endl;
        
        mystack.pop();
        mystack.pop();
        mystack.pop();
        // mystack.pop(); // pop 1 en trop donc segfault (undefined behaviour)
        stack.pop();
        stack.pop();
        stack.pop();
        // stack.pop(); // pop 1 en trop donc segfault (undefined behaviour)
        mystack_outfile << mystack.empty() << ", size: " << mystack.size() <<  std::endl;
        stack_outfile << stack.empty()  << ", size: " << stack.size() << std::endl;

        ft::stack<std::string> compare1;
        std::stack<std::string> compare2;
        mystack.push("lol");
        stack.push("lol");
        compare1.push("lol");
        compare2.push("lol");
        mystack_outfile << std::endl << "SAME CONTENT" << std::endl;
        stack_outfile << std::endl << "SAME CONTENT" << std::endl;
        mystack_outfile << "'==' : " << (mystack == compare1) << std::endl;
        stack_outfile << "'==' : " << (stack == compare2) << std::endl;
        mystack_outfile << "'!=' : " << (mystack != compare1) << std::endl;
        stack_outfile << "'!=' : " << (stack != compare2) << std::endl;
        mystack_outfile << "'<' : " << (mystack < compare1) << std::endl;
        stack_outfile << "'<' : " << (stack < compare2) << std::endl;
        mystack_outfile << "'<=' : " << (mystack <= compare1) << std::endl;
        stack_outfile << "'<=' : " << (stack <= compare2) << std::endl;
        mystack_outfile << "'>' : " << (mystack > compare1) << std::endl;
        stack_outfile << "'>' : " << (stack > compare2) << std::endl;
        mystack_outfile << "'>=' : " << (mystack >= compare1) << std::endl;
        stack_outfile << "'>=' : " << (stack >= compare2) << std::endl;

        compare1.push("wtf");
        compare2.push("wtf");
        mystack_outfile << std::endl << "DIFFERENT CONTENT" << std::endl;
        stack_outfile << std::endl << "DIFFERENT CONTENT" << std::endl;
        mystack_outfile << "'==' : " << (mystack == compare1) << std::endl;
        stack_outfile << "'==' : " << (stack == compare2) << std::endl;
        mystack_outfile << "'!=' : " << (mystack != compare1) << std::endl;
        stack_outfile << "'!=' : " << (stack != compare2) << std::endl;
        mystack_outfile << "'<' : " << (mystack < compare1) << std::endl;
        stack_outfile << "'<' : " << (stack < compare2) << std::endl;
        mystack_outfile << "'<=' : " << (mystack <= compare1) << std::endl;
        stack_outfile << "'<=' : " << (stack <= compare2) << std::endl;
        mystack_outfile << "'>' : " << (mystack > compare1) << std::endl;
        stack_outfile << "'>' : " << (stack > compare2) << std::endl;
        mystack_outfile << "'>=' : " << (mystack >= compare1) << std::endl;
        stack_outfile << "'>=' : " << (stack >= compare2) << std::endl;
    }

    {
        ft::stack<int> mystack;
        std::stack<int> stack;
        mystack_outfile << std::endl << std::endl << "TEST WITH INTS" << std::endl << std::endl;
        stack_outfile << std::endl << std::endl << "TEST WITH INTS" << std::endl << std::endl;

        mystack_outfile << mystack.empty() << ", size: " << mystack.size() <<  std::endl;
        stack_outfile << stack.empty()  << ", size: " << stack.size() << std::endl;
        
        mystack.push(1);
        mystack.push(2);
        mystack.push(3);
        mystack.push(4);
        mystack.push(5);
        stack.push(1);
        stack.push(2);
        stack.push(3);
        stack.push(4);
        stack.push(5);
        mystack_outfile << mystack.empty() << ", size: " << mystack.size() << ", top: " << mystack.top() <<  std::endl;
        stack_outfile << stack.empty()  << ", size: " << stack.size()  << ", top: " << stack.top() << std::endl;

        mystack.pop();
        mystack.pop();
        stack.pop();
        stack.pop();
        mystack_outfile << mystack.empty() << ", size: " << mystack.size() << ", top: " << mystack.top() <<  std::endl;
        stack_outfile << stack.empty()  << ", size: " << stack.size()  << ", top: " << stack.top() << std::endl;
        
        mystack.pop();
        mystack.pop();
        mystack.pop();
        // mystack.pop(); // pop 1 en trop donc segfault (undefined behaviour)
        stack.pop();
        stack.pop();
        stack.pop();
        // stack.pop(); // pop 1 en trop donc segfault (undefined behaviour)
        mystack_outfile << mystack.empty() << ", size: " << mystack.size() <<  std::endl;
        stack_outfile << stack.empty()  << ", size: " << stack.size() << std::endl;

        ft::stack<int> compare1;
        std::stack<int> compare2;
        mystack.push(1);
        stack.push(1);
        compare1.push(1);
        compare2.push(1);
        mystack_outfile << std::endl << "SAME CONTENT" << std::endl;
        stack_outfile << std::endl << "SAME CONTENT" << std::endl;
        mystack_outfile << "'==' : " << (mystack == compare1) << std::endl;
        stack_outfile << "'==' : " << (stack == compare2) << std::endl;
        mystack_outfile << "'!=' : " << (mystack != compare1) << std::endl;
        stack_outfile << "'!=' : " << (stack != compare2) << std::endl;
        mystack_outfile << "'<' : " << (mystack < compare1) << std::endl;
        stack_outfile << "'<' : " << (stack < compare2) << std::endl;
        mystack_outfile << "'<=' : " << (mystack <= compare1) << std::endl;
        stack_outfile << "'<=' : " << (stack <= compare2) << std::endl;
        mystack_outfile << "'>' : " << (mystack > compare1) << std::endl;
        stack_outfile << "'>' : " << (stack > compare2) << std::endl;
        mystack_outfile << "'>=' : " << (mystack >= compare1) << std::endl;
        stack_outfile << "'>=' : " << (stack >= compare2) << std::endl;

        compare1.push(2);
        compare2.push(2);
        mystack_outfile << std::endl << "DIFFERENT CONTENT" << std::endl;
        stack_outfile << std::endl << "DIFFERENT CONTENT" << std::endl;
        mystack_outfile << "'==' : " << (mystack == compare1) << std::endl;
        stack_outfile << "'==' : " << (stack == compare2) << std::endl;
        mystack_outfile << "'!=' : " << (mystack != compare1) << std::endl;
        stack_outfile << "'!=' : " << (stack != compare2) << std::endl;
        mystack_outfile << "'<' : " << (mystack < compare1) << std::endl;
        stack_outfile << "'<' : " << (stack < compare2) << std::endl;
        mystack_outfile << "'<=' : " << (mystack <= compare1) << std::endl;
        stack_outfile << "'<=' : " << (stack <= compare2) << std::endl;
        mystack_outfile << "'>' : " << (mystack > compare1) << std::endl;
        stack_outfile << "'>' : " << (stack > compare2) << std::endl;
        mystack_outfile << "'>=' : " << (mystack >= compare1) << std::endl;
        stack_outfile << "'>=' : " << (stack >= compare2) << std::endl;
    }

}