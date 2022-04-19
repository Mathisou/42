#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	this->_i = 0;
	this->_tour = 0;
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

int		PhoneBook::_get_index() const
{
	std::string buff;

	std::cout << "Enter an index: ";
	std::getline(std::cin, buff, '\n');
	while (buff.length() == 0 || PhoneBook::_contact[_i].isdigit(buff) == 0){
		std::cout << "Failed" << std::endl;
		std::cout << "Enter an index: ";
		std::getline(std::cin, buff, '\n');;
	}
	return (std::stoi(buff));
}

void	PhoneBook::_print_contact(int index) const{
		std::cout << "First name: " << this->_contact[index].getFirstName() << std::endl;
		std::cout << "Last name: " << this->_contact[index].getLastName() << std::endl;
		std::cout << "Nick name: " << this->_contact[index].getNickName() << std::endl;
		std::cout << "Phone number: " << this->_contact[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << this->_contact[index].getDarkestSecret() << std::endl;
}

void	PhoneBook::_pre_print_contact(int index) const
{
	if (index <= 0 || index > 8 || (this->_tour == 0 && (this->_i == 0 || index > this->_i)))
		std::cout << "No contact with that index..." << std::endl;
	else
		_print_contact(index - 1);
}

void	PhoneBook::_check_length(std::string output) const{
	
	if (output.length() >= 10)
		std::cout << output.substr(0, 9) << ".";
	else
		std::cout << output;
}

void	PhoneBook::_print_all() const{

		for(int j = 0;j < 8;j++)
		{
			std::cout << j + 1;
			std::cout << "|";
			_check_length(this->_contact[j].getFirstName());
			std::cout << "|";
			_check_length(this->_contact[j].getLastName());
			std::cout << "|";
			_check_length(this->_contact[j].getNickName());
			std::cout << std::endl;
			std::cout << std::endl;
			if (this->_tour == 0 && j == this->_i - 1)
				break;
		}

}

void	PhoneBook::fill_rep()
{
	std::string buff;

	while (1){
	std::cout	<< std::endl << "\033[1;35mPlease choose an option:\033[0m" << std::endl
				<< "1. ADD " << "2. SEARCH " << "3. EXIT" << std::endl << std::endl;
		std::getline(std::cin, buff, '\n');
		if (buff.compare("ADD") == 0)
		{
			this->_contact[this->_i].setFirstName();
			this->_contact[this->_i].setLastName();
			this->_contact[this->_i].setNickName();
			this->_contact[this->_i].setPhoneNumber();
			this->_contact[this->_i].setDarkestSecret();
			this->_i++;
		}
		else if (buff.compare("SEARCH") == 0)
		{
			this->_print_all();
			this->_pre_print_contact(this->_get_index());
		}
		else if (buff.compare("EXIT") == 0)
			break ;
		else
			std::cout << "Not a valid option." << std::endl;
		if (this->_i == 8)
		{
			this->_tour++;
			this->_i = 0;
		}
	}
}