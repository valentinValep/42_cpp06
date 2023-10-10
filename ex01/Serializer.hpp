#pragma once

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
private:
	Serializer(); // Default constructor
	Serializer(const Serializer &src); // Copy constructor
	Serializer	&operator=(const Serializer &src); // Assignment operator
	~Serializer(); // Destructor
public:
	static uintptr_t	serialize(Data *ptr);
	static Data			*deserialize(uintptr_t raw);

	class SerializationException: public std::exception
	{
		virtual const char *what() const throw();
	};
};
