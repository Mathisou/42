#ifndef WrongCat_HPP
# define WrongCat_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	public:

		WrongCat();
		WrongCat( WrongCat const & src );
		virtual ~WrongCat();

		WrongCat &		operator=( WrongCat const & rhs );

		void	makeSound() const;
		Brain &get_brain(void) const;

	private:
		Brain *_brain;

};


#endif /* ************************************************************* WrongCat_H */