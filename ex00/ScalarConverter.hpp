#pragma once

enum e_type
{
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	UNKNOWN
};

class ScalarConverter
{
private:
	ScalarConverter(); // Default constructor
	ScalarConverter(const ScalarConverter &src); // Copy constructor
	~ScalarConverter(); // Destructor
	ScalarConverter	&operator=(const ScalarConverter &src); // Assignment operator
public:
	static void	convert(const char *input);
};
