#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array {
	public:
		Array();
		Array(unsigned int n);
		~Array();
		Array(const Array &other);
		Array& operator=(const Array &other);

		unsigned int size() const;

		T &operator[](int index);
		const T &operator[](int index) const;

		class OutOfBoundException : public std::exception {
		public:
			virtual const char *what() const throw();
		};

	private:
		T *data;
		unsigned int _size;
};

#include "Array.tpp"

#endif
