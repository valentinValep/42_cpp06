#include "ScalarConverter.hpp"
#include "utils.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cerrno>

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

static int	is_double_integer(const char *input)
{
	int i = 0;

	if (!has_dot(input))
		return (0);
	while (input[i] != '.')
		i++;
	i++;
	while (input[i] && input[i] != 'f')
		if (input[i++] != '0')
			return (0);
	return (1);
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

// Float max : ./convert 340282346638528859811704183484516925440.f
static void	convert_float(const char *input)
{
	double	d = atof(input);
	if ((errno == ERANGE || d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max()) && has_dot(input))
	{
		std::cerr << "float overflow" << std::endl;
		return ;
	}
	float	f = static_cast<float>(d);

	if (f == 0 && input[0] == '-')
		f = -0.0f;
	// char output
	if (f < 0 || f > 255 || !ft_strcmp(input, "nanf"))
		std::cout << "char: impossible" << std::endl;
	else if (!ft_isprint(static_cast<int>(f)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	// int output
	if (f < -2147483648.f || f > 2147483647.f || !ft_strcmp(input, "nanf"))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << (is_double_integer(input)? ".0f" : "f") << std::endl;
	std::cout << "double: " << static_cast<double>(f) << (is_double_integer(input)? ".0" : "") << std::endl;
}

// Double max : ./convert 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.
static void	convert_double(const char *input)
{
	double	d = atof(input);
	if (errno == ERANGE && has_dot(input))
	{
		std::cerr << "double overflow" << std::endl;
		return ;
	}

	if (d == 0 && input[0] == '-')
		d = -0.0;
	// char output
	if (d < 0 || d > 255 || !ft_strcmp(input, "nan"))
		std::cout << "char: impossible" << std::endl;
	else if (!ft_isprint(static_cast<int>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	// int output
	if (d < -2147483648.0 || d > 2147483647.0  || !ft_strcmp(input, "nan"))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	// float output
	if ((d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
		&& has_dot(input))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << (is_double_integer(input)? ".0f" : "f") << std::endl;
	std::cout << "double: " << d << (is_double_integer(input)? ".0" : "") << std::endl;
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
	(void (*[])(const char *)){convert_char, convert_int, convert_float, convert_double}[type](input);
}
