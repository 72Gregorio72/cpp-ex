#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		Contact phoneBook[8];
		void add_contact(Contact c);
		void search_contact(int index);
		Contact getContact(int index);
};

#endif