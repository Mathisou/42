#include "AMateria.hpp"

AMateria::AMateria(){
	std::cout << "AMateria default constructor" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type){
	std::cout << "AMateria type constructor" << std::endl;
}

AMateria::AMateria(AMateria const & src){
	std::cout << "Amateria copy constructor" << std::endl;
	*this = src;
}

AMateria::~AMateria(){
	std::cout << "AMateria destructor" << std::endl;
}

AMateria & AMateria::operator=(AMateria const & rhs){
	std::cout << "AMateria assignation operator called" << std::endl;
	_type = rhs.getType();
	return (*this);
}

std::string const & AMateria::getType() const{
	return this->_type;
}

void AMateria::use(ICharacter& target){
	(void)target;
}
