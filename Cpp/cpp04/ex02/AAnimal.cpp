#include "AAnimal.hpp"

AAnimal::AAnimal(){
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal & rhs){
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = rhs;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal & AAnimal::operator=( AAnimal const & rhs){
	std::cout << "AAnimal assignation operator called" << std::endl;
	_type = rhs._type;
	return *this;
}

std::string AAnimal::get_type() const{
	return _type;
}
