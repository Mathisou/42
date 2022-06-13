#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void){
    int random = rand() % 3;
    if (random == 0)
        return (new A);
    else if (random == 1)
        return (new B);
    else
        return (new C);
}

void identify(Base* p){
	if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;

}

void identify(Base& p){
	if (dynamic_cast<A*>(&p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p) != NULL)
        std::cout << "C" << std::endl;
}

int main(){
    srand(time(0));

    Base *ret = generate();
    identify(ret);
    identify(*ret);
    delete ret;
}
