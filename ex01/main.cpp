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

int atoi(const char* str)
{
	int num = 0;
	int sign = 1;
	size_t i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[0] == '+')
	{
		i++;
	}

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
		num = num * 10 + (str[i] - '0');
	}

	return sign * num;
}

int str_to_int(const std::string& str)
{
	int num = 0;
	if (str.empty())
		return -1;
	size_t start = (str[0] == '+' || str[0] == '-') ? 1 : 0;
	for (size_t i = start; i < str.length(); ++i)
	{
		if (!isdigit(str[i]))
			return -1;
	}
	num = atoi(str.c_str());
	return num;
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
			std::string indexStr;
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
			std::getline(std::cin, indexStr);
			index = str_to_int(indexStr);
			if (index == -1)
			{
				std::cout << "Contatto non esistente" << std::endl;
			}
			else if (index >= 0 && index < 8)
			{
				phoneBook.search_contact(index);
			}
			else
			{
				std::cout << "Contatto non esistente" << std::endl;
			}
		}
		else if (s == "EXIT")
		{
			std::cout << "Uscita in corso..." << std::endl;
			break;
		}
	}
}