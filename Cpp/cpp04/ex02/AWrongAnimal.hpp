#ifndef AWRONGANIMAL_HPP
# define AWRONGANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AWrongAnimal{

	protected:
		std::string _type;
	public:
		AWrongAnimal(void);
		AWrongAnimal(const AWrongAnimal & rhs);
		virtual ~AWrongAnimal(void);
		AWrongAnimal & operator=(const AWrongAnimal & rhs);

		std::string get_type() const;
		virtual void makeSound() const = 0;
};

#endif