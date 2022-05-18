#include "Animal.hpp"

Animal::Animal(){
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal & rhs){
	std::cout << "Animal copy constructor called" << std::endl;
	*this = rhs;
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

Animal & Animal::operator=( Animal const & rhs){
	std::cout << "Animal assignation operator called" << std::endl;
	_type = rhs._type;
	return *this;
}

std::string Animal::get_type() const{
	return _type;
}

void Animal::makeSound()const {
	std::cout << "Animal make a sound." << std::endl;
	return ;
}
