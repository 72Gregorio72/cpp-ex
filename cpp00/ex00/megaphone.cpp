#include <iostream>
#include <string>

char to_upper_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return c - ('a' - 'A');
	return c;
}
std::string toupper(std::string s)
{
	std::string newString = s;

	for (size_t i = 0; i < newString.length(); i++)
		newString[i] = to_upper_char(newString[i]);
	std::cout << newString;
	return newString;
}
int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 1;
	}
	for(int i = 1; i < ac; i++)
		toupper(av[i]);
	std::cout << std::endl;
}