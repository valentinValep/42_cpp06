#include "Serializer.hpp"

Serializer::Serializer()
{
	// Default constructor
}

Serializer::Serializer(const Serializer &src)
{
	// Copy constructor
	*this = src;
}

Serializer::~Serializer()
{
	// Destructor
}

Serializer	&Serializer::operator=(const Serializer &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	if (raw == 0)
		throw Serializer::SerializationException();
	return reinterpret_cast<Data *>(raw);
}

const char *Serializer::SerializationException::what() const throw()
{
	return "Invalid pointer";
}
