#pragma once

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
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
