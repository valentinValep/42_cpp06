#include "ScalarConverter.hpp"
#include "utils.hpp"
#include <iostream>

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
	if (ft_strlen(input) == 1 && (input[0] < '0' || input[0] > '9') && ft_isprint(input[0]))
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
		return (input[ft_strlen(input) - 1] == 'f' ? FLOAT : DOUBLE);
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

static void	convert_char(const char *input)
{
	char	c = input[0];

	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

static void	convert_int(const char *input)
{
	int	i;

	if (anti_overflow_atoi(input, &i))
	{
		std::cerr << "int overflow" << std::endl;
		return ;
	}
	if (!ft_isprint(i))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convert(const char *input)
{
	e_type	type = get_type(input);
	if (type == UNKNOWN && input)
	{
		if (!ft_strcmp(input, "+inf") || !ft_strcmp(input, "-inf") || !ft_strcmp(input, "nan"))
			type = DOUBLE;
		else if (!ft_strcmp(input, "+inff") || !ft_strcmp(input, "-inff") || !ft_strcmp(input, "nanf"))
			type = FLOAT;
	}
	if (type == UNKNOWN)
	{
		std::cerr << "Undefine type" << std::endl;
		return ;
	}
	(void (*[])(const char *)){convert_char, convert_int, convert_char, convert_char}[type](input);
}
