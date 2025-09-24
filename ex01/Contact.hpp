#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
	private:
		std::string name, lastName, nickName, darkWebSecret, phoneNumber;

	public:
		std::string getName();
		std::string getLastName();
		std::string getNickName();
		std::string getSecret();
		std::string getNumber();
		void ToString();
		Contact();
		Contact(std::string name, std::string lastName, std::string nickName, std::string secret, std::string phoneNumber);
		~Contact( void );
};

#endif