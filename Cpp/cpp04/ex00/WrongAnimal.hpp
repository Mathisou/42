#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal{

	protected:
		std::string _type;
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal & rhs);
		virtual ~WrongAnimal(void);
		WrongAnimal & operator=(const WrongAnimal & rhs);

		std::string get_type() const;
		virtual void makeSound() const;
};

#endif