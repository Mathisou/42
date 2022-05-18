#ifndef BRAIN_HPP
# define BRAIN_HPP

#include "Animal.hpp"

class Brain
{

	public:

		Brain();
		Brain( Brain const & src );
		~Brain();
		void set_idea(unsigned int index, std::string idea);
		std::string get_idea(unsigned int index) const;
		void print_ideas();

		Brain &		operator=( Brain const & rhs );

	private:

		std::string _ideas[100];

};

#endif /* *********************************************************** BRAIN_H */