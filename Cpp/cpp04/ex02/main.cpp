#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

#include <stdio.h>
#include <stdlib.h>

int main(){
	// AAnimal *animal = new AAnimal();
	AAnimal *a = new Dog();
	AAnimal *b = new Cat();
	AWrongAnimal *c = new WrongCat();
	
	std::cout << a->get_type() << " ";
	a->makeSound();
	std::cout << b->get_type() << " ";
	b->makeSound();
	std::cout << c->get_type() << " ";
	c->makeSound();

	std::cout << std::endl << "          DOG BRAIN" << std::endl;
	static_cast<Dog *>(a)->get_brain().set_idea(0, "Hello");
	static_cast<Dog *>(a)->get_brain().set_idea(10, "World");
	static_cast<Dog *>(a)->get_brain().set_idea(99, "!");
	std::cout << static_cast<Dog *>(a)->get_brain().get_idea(10) << std::endl;
	std::cout << static_cast<Dog *>(a)->get_brain().get_idea(11) << std::endl;
	static_cast<Dog *>(a)->get_brain().print_ideas();

	std::cout << std::endl << "          CAT BRAIN" << std::endl;
	static_cast<Cat *>(b)->get_brain().set_idea(5, "How");
	static_cast<Cat *>(b)->get_brain().set_idea(31, "Are");
	static_cast<Cat *>(b)->get_brain().set_idea(88, "You");
	std::cout << static_cast<Cat *>(b)->get_brain().get_idea(5) << std::endl;
	std::cout << static_cast<Cat *>(b)->get_brain().get_idea(11) << std::endl;
	static_cast<Cat *>(b)->get_brain().print_ideas();

	std::cout << std::endl << "          WRONGCAT BRAIN" << std::endl;
	static_cast<WrongCat *>(c)->get_brain().set_idea(8, "ptdr");
	static_cast<WrongCat *>(c)->get_brain().set_idea(9, "mdr");
	static_cast<WrongCat *>(c)->get_brain().set_idea(10, "lol");
	std::cout << static_cast<WrongCat *>(c)->get_brain().get_idea(8) << std::endl;
	std::cout << static_cast<WrongCat *>(c)->get_brain().get_idea(11) << std::endl;
	static_cast<WrongCat *>(c)->get_brain().print_ideas();
	
	std::cout << std::endl;
	
	delete a;
	delete b;
	delete c;
}
