#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <stdint.h>
#include <iostream>
#include "Data.hpp"
#include <string>

class Serialize {
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:
		Serialize();
		~Serialize();
		Serialize(const Serialize&);
		Serialize& operator=(const Serialize&);
};

#endif