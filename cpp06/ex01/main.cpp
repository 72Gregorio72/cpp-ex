#include "Serialize.hpp"

int main() {
	Data* originalData = new Data("Hello", 42, "World");

	std::cout << "Original Data:" << std::endl;
	std::cout << "s1: " << originalData->s1 << ", n: " << originalData->n << ", s2: " << originalData->s2 << std::endl;

	uintptr_t serializedData = Serialize::serialize(originalData);
	std::cout << "Serialized Data (uintptr_t): " << serializedData << std::endl;

	Data* deserializedData = Serialize::deserialize(serializedData);
	std::cout << "Deserialized Data:" << std::endl;
	std::cout << "s1: " << deserializedData->s1 << ", n: " << deserializedData->n << ", s2: " << deserializedData->s2 << std::endl;

	delete originalData;

	return 0;
}