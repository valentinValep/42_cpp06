#include "ScalarConverter.hpp"
#include <iostream>
//#include <iomanip>

int	main(int argc, char **argv)
{
	// print all the float part of a double
	// std::cout << std::setprecision(100);
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [input]" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
