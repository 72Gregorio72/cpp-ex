#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <exception>
#include <stdexcept>

class Easyfind{
	private:
		Easyfind();
		~Easyfind();
		Easyfind(const Easyfind &other);
		Easyfind &operator=(const Easyfind &other);
	public:
		class IntegerNotFoundException : public std::exception {
			public:
				const char* what() const throw() {
					return "Integer not found";
				}
		};
};

template<typename T>
typename T::iterator easyfind(T &t, int n){
	typename T::iterator it = std::find(t.begin(), t.end(), n);
	if (it == t.end())
		throw Easyfind::IntegerNotFoundException();
	return it;
}

#endif