#ifndef AAnimal_HPP
# define AAnimal_HPP

#include <iostream>

class AAnimal{

	protected:
		std::string _type;
	public:
		AAnimal(void);
		AAnimal(const AAnimal & rhs);
		virtual ~AAnimal(void);
		AAnimal & operator=(const AAnimal & rhs);

		std::string get_type() const;
		virtual void makeSound() const = 0;
};

#endif