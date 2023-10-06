#include "ScalarConverter.hpp"
#include <iostream>
#include <cstring>

ScalarConverter::ScalarConverter()
{
	// Default constructor
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	// Copy constructor
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
	// Destructor
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

static e_type	get_type(const char *input)
{
	int	dot = 0, sign = 0, digit = 0;

	if (!input || !*input)
		return (UNKNOWN);
	if (strlen(input) == 1 && (input[0] < '0' || input[0] > '9') && isprint(input[0]))
		return (CHAR);
	for (int i = 0; input[i]; i++)
	{
		if (input[i] == '.')
			dot++;
		else if (input[i] == '+' || input[i] == '-')
			sign++;
		else if (input[i] >= '0' && input[i] <= '9')
			digit++;
		else if (!((input[i] == 'f' && input[i + 1] == '\0') && dot == 1))
			return (UNKNOWN);
	}
	if (sign > 1 || (sign == 1 && input[0] != '+' && input[0] != '-'))
		return (UNKNOWN);
	if (dot > 1 || !digit)
		return (UNKNOWN);
	if (dot == 1)
		return (input[strlen(input) - 1] == 'f' ? FLOAT : DOUBLE);
	return (INT);
}

int	test_get_type(const char *input, e_type expected)
{
	e_type	type = get_type(input);
	if (type != expected)
	{
		std::cerr << "get_type(\"" << input << "\") != " << expected << " (" << type << ")" << std::endl;
		return (1);
	}
	return (0);
}

void ScalarConverter::convert(const char *input)
{
	e_type	type = get_type(input);
	(void)type;
}
