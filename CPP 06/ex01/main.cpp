#include "Serializer.hpp"
#include <iostream>

/*
** main: Tests serialization and deserialization of a Data object.
*/
int main()
{
	Data myData;
	myData.id = 42;
	myData.name = "Hive Helsinki";

	std::cout << "--- Original ---\n";
	std::cout << "Address: " << &myData << "\n";
	std::cout << "Content: " << myData.id << ", " << myData.name << "\n\n";

	uintptr_t raw = Serializer::serialize(&myData);
	std::cout << "--- Serialized ---\n";
	std::cout << "Raw integer: " << raw << "\n\n";

	Data* deserializedData = Serializer::deserialize(raw);
	std::cout << "--- Deserialized ---\n";
	std::cout << "Address: " << deserializedData << "\n";
	std::cout << "Content: " << deserializedData->id << ", " << deserializedData->name << "\n\n";

	if (deserializedData == &myData)
		std::cout << "\033[0;32mSuccess: Addresses match perfectly!\033[0m\n";
	else
		std::cout << "\033[0;31mError: Addresses do not match!\033[0m\n";

	return 0;
}