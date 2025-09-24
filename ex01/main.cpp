#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

std::string formatField(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str + std::string(10 - str.length(), ' ') + "|";
}

int main()
{
	PhoneBook phoneBook = PhoneBook();
	std::string s;

	while (true)
	{
		std::cout << "Inserisci uno fra i 3 comandi disponibili:" << std::endl
					<< "ADD: aggiungi un contatto" << std::endl
					<< "SEARCH: cerca un contatto" << std::endl
					<< "EXIT" << std::endl;
		std::getline(std::cin, s);

		if (s == "ADD")
		{
			Contact c;
			std::string name;
			std::string lastName;
			std::string nickName;
			std::string secret;
			std::string phoneNumber;

			std::cout << "Name:" << std::endl;
			std::getline(std::cin, name);
			
			std::cout << "Last Name:" << std::endl;
			std::getline(std::cin, lastName);

			std::cout << "nickname:" << std::endl;
			std::getline(std::cin, nickName);

			std::cout << "secret:" << std::endl;
			std::getline(std::cin, secret);

			std::cout << "Phone Book:" << std::endl;
			std::getline(std::cin, phoneNumber);

			c = Contact(name, lastName, nickName, secret, phoneNumber);
			phoneBook.add_contact(c);
		}
		else if (s == "SEARCH")
		{
			int index;
			std::cout << "INDEX     |FIRST NAME|LAST NAME |NICKNAME  |" << std::endl;
			for (int i = 0; i < 8; i++)
			{
				if (phoneBook.phoneBook[i].getName() != "")
					std::cout 
							<< i << "         |"
							<< formatField(phoneBook.phoneBook[i].getName())
							<< formatField(phoneBook.phoneBook[i].getLastName())
							<< formatField(phoneBook.phoneBook[i].getNickName()) << std::endl;
			}
			std::cout << "Inserisci l'indice del contatto che vuoi cercare (0-7):" << std::endl;
			std::cin >> index;
			std::cin.ignore();
			phoneBook.search_contact(index);
		}
		else if (s == "EXIT")
		{
			std::cout << "Uscita in corso..." << std::endl;
			break;
		}
	}
}