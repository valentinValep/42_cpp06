#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main(void)
{
	Data	*data = new Data("Hello world!");
	uintptr_t	serialized = Serializer::serialize(data);

	std::cout << "Data: " << *data << std::endl;

	Data	*deserialized = Serializer::deserialize(serialized);

	std::cout << "Deserialized data: " << *deserialized << std::endl;

	delete data;

	// NULL pointer
	Data	*data2 = NULL;
	uintptr_t	serialized2 = Serializer::serialize(data2);

	std::cout << "Data: " << data2 << std::endl;

	try
	{
		Data	*deserialized2 = Serializer::deserialize(serialized2);

		std::cout << "Deserialized data: " << deserialized2 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
