#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook creato" << std::endl;
}

void	PhoneBook::add_contact(Contact c)
{
	int i;
	for(i = 0; i < 8; i++)
	{
		if (phoneBook[i].getName() == "")
			break;
	}
	if (i == 8)
		i = 0;
	std::cout << "Aggiunto contatto in posizione " << i << std::endl;
	phoneBook[i] = c;
}

void	PhoneBook::search_contact(int index)
{
	if (index < 0 || index > 7 || phoneBook[index].getName() == "")
		std::cout << "Contatto non esistente" << std::endl;
	else
		phoneBook[index].ToString();
}