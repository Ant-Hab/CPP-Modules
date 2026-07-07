#pragma once

#include <cstdint>
#include <string>

/*
** Data: A simple non-empty structure to test serialization.
*/
struct Data {
	int id;
	std::string name;
};

class Serializer {
public:
	/*
	** Deleted Constructors: Instantiation strictly forbidden.
	*/
	Serializer() = delete;
	Serializer(const Serializer& other) = delete;
	Serializer& operator=(const Serializer& other) = delete;
	~Serializer() = delete;

	/*
	** serialize: Converts a Data pointer to an unsigned integer type.
	*/
	static uintptr_t serialize(Data* ptr);

	/*
	** deserialize: Converts an unsigned integer back to a Data pointer.
	*/
	static Data* deserialize(uintptr_t raw);
};