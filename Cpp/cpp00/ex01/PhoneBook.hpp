#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {

	private:

		int		_i;
		int		_tour;
		void	_pre_print_contact(int index) const;
		void	_print_contact(int index) const;
		void	_check_length(std::string output) const;
		void	_print_all() const;
		int		_get_index() const;
		Contact		_contact[8];


	public:

		void	fill_rep();
		PhoneBook(void);
		~PhoneBook(void);
};

#endif