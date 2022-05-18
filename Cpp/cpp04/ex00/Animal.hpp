#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal{

	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(const Animal & rhs);
		virtual ~Animal(void);
		Animal & operator=(const Animal & rhs);

		std::string get_type() const;
		virtual void makeSound() const;
};

#endif