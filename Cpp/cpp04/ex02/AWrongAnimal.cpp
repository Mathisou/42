#include "AWrongAnimal.hpp"

AWrongAnimal::AWrongAnimal(){
	std::cout << "AWrongAnimal default constructor called" << std::endl;
}

AWrongAnimal::AWrongAnimal(const AWrongAnimal & rhs){
	std::cout << "AWrongAnimal copy constructor called" << std::endl;
	*this = rhs;
}

AWrongAnimal::~AWrongAnimal(){
	std::cout << "AWrongAnimal destructor called" << std::endl;
}

AWrongAnimal & AWrongAnimal::operator=( AWrongAnimal const & rhs){
	std::cout << "AWrongAnimal assignation operator called" << std::endl;
	_type = rhs._type;
	return *this;
}

std::string AWrongAnimal::get_type() const{
	return _type;
}

void AWrongAnimal::makeSound()const {
	std::cout << "AWrongAnimal make a sound." << std::endl;
	return ;
}
