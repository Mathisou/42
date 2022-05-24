#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & rhs){
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = rhs;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & rhs){
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	_type = rhs._type;
	return *this;
}

std::string WrongAnimal::get_type() const{
	return _type;
}

void WrongAnimal::makeSound()const {
	std::cout << "WrongAnimal make a sound." << std::endl;
	return ;
}
