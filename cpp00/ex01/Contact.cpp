#include <iostream>
#include <string>
#include "Contact.hpp"

std::string Contact::getName()
{
	return name;
}

std::string Contact::getLastName()
{
	return lastName;
}

std::string Contact::getNickName()
{
	return nickName;
}

std::string Contact::getSecret()
{
	return darkWebSecret;
}

std::string Contact::getNumber()
{
	return phoneNumber;
}

Contact::Contact(std::string name, std::string lastName, std::string nickName, std::string secret, std::string phoneNumber) :
	name(name), lastName(lastName), nickName(nickName), darkWebSecret(secret), phoneNumber(phoneNumber)
{
}

Contact::~Contact()
{
}

void Contact::ToString()
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nick Name: " << nickName << std::endl;
	std::cout << "Secret: " << darkWebSecret << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
}

Contact::Contact()
{
	name = "";
	lastName = "";
	nickName = "";
	darkWebSecret = "";
	phoneNumber = "";
}