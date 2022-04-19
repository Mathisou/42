#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

void Contact::setFirstName()
{
	std::string buff;

	std::cout << "First name: ";
	std::getline(std::cin, buff, '\n');
	while (buff.length() == 0){
		std::cout << "Failed" << std::endl;
		std::cout << "First name: ";
		std::getline(std::cin, buff, '\n');
	}
	this->_FirstName = buff;
}

std::string Contact::getFirstName() const {
	return this->_FirstName;
}

void Contact::setLastName()
{
	std::string buff;

	std::cout << "Last name: ";
	std::getline(std::cin, buff, '\n');
	while (buff.length() == 0){
		std::cout << "Failed" << std::endl;
		std::cout << "Last name: ";
		std::getline(std::cin, buff, '\n');
	}
	this->_LastName = buff;
}

std::string Contact::getLastName() const{
	return this->_LastName;
}

void Contact::setNickName()
{
	std::string buff;

	std::cout << "Nickname: ";
	std::getline(std::cin, buff, '\n');
	while (buff.length() == 0){
		std::cout << "Failed" << std::endl;
		std::cout << "Nickname: ";
		std::getline(std::cin, buff, '\n');
	}
	this->_NickName = buff;
}

std::string Contact::getNickName() const {
	return this->_NickName;
}

void Contact::setPhoneNumber()
{
	std::string buff;

	std::cout << "Phone number: ";
	std::getline(std::cin, buff, '\n');
	while (buff.length() == 0 || this->isdigit(buff) == 0){
		std::cout << "Failed" << std::endl;
		std::cout << "Phone number: ";
		std::getline(std::cin, buff, '\n');
	}
	this->_PhoneNumber = buff;
}

std::string Contact::getPhoneNumber() const {
	return this->_PhoneNumber;
}

void Contact::setDarkestSecret()
{
	std::string buff;

	std::cout << "Darkest secret: ";
	std::getline(std::cin, buff, '\n');
	while (buff.length() == 0){
		std::cout << "Failed" << std::endl;
		std::cout << "Darkest secret: ";
		std::getline(std::cin, buff, '\n');
	}
	this->_DarkestSecret = buff;
}

std::string Contact::getDarkestSecret() const {
	return this->_DarkestSecret;
}

Contact::Contact()
{
	return ;
}

Contact::~Contact(void)
{
	return;
}

int Contact::isdigit(std::string str) const {
	for (int i = 0;str[i];i++)
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
	return (1);
}