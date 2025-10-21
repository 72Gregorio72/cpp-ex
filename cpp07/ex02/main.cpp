#include "Array.hpp"
#include <string>
#include <iostream>

int main() {
    Array<int> a;
    std::cout << "Array<int> size = " << a.size() << std::endl;

	try {
        std::cout << a[5] << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Eccezione: " << e.what() << std::endl;
    }

    Array<std::string> s(3);
    s[0] = "Ciao";
    s[1] = "dal";
    s[2] = "template!";

    for (unsigned int i = 0; i < s.size(); ++i)
        std::cout << s[i] << " ";
    std::cout << std::endl;

    try {
        std::cout << s[5] << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Eccezione: " << e.what() << std::endl;
    }

	try {
        std::cout << s[-1] << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Eccezione: " << e.what() << std::endl;
    }

    return 0;
}
