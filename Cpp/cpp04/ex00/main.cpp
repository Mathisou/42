#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(){
	Animal *a = new Dog();
	Animal *b = new Cat();
	WrongAnimal *c = new WrongCat();
	std::cout << a->get_type() << " ";
	a->makeSound();
	std::cout << b->get_type() << " ";
	b->makeSound();
	std::cout << c->get_type() << " ";
	c->makeSound();
	delete a;
	delete b;
	delete c;
}
