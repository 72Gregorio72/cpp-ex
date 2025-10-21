#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

class Iter {
	private:
		Iter();
		~Iter();
		Iter(const Iter&);
		Iter& operator=(const Iter&);
};

template <typename T> void iter(T* array, std::size_t length, void (*func)(T&)) {
	for (std::size_t i = 0; i < length; ++i) {
		func(array[i]);
	}
}

#endif