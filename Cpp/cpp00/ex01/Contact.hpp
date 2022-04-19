#ifndef	CONTACT_HPP
# define CONTACT_HPP

 class Contact {

	 private:

		std::string _FirstName;
		std::string _LastName;
		std::string _NickName;
		std::string _PhoneNumber;
		std::string _DarkestSecret;
		std::string *_find_contact();


	 public:

		void setFirstName();
		void setLastName();
		void setNickName();
		void setPhoneNumber();
		void setDarkestSecret();
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;
		int isdigit(std::string str) const;
	 	Contact(void);
		~Contact(void);
 };

#endif