#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{

	public:

		Cat();
		Cat( Cat const & src );
		virtual ~Cat();

		Cat &		operator=( Cat const & rhs );

		void	makeSound() const;
		Brain &get_brain(void) const;

	private:

		Brain *_brain;

};


#endif /* ************************************************************* CAT_H */