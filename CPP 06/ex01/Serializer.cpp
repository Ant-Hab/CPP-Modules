#include "Serializer.hpp"

/*
** serialize: Reinterprets the pointer as an integer.
*/
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

/*
** deserialize: Reinterprets the integer back into a pointer.
*/
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}