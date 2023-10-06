#include "ScalarConverter.hpp"
#include <iostream>

int	test_get_type(const char *input, e_type expected);

int	tests_get_type()
{
	if (test_get_type("0", INT))
		return (1);
	if (test_get_type("0.0", DOUBLE))
		return (2);
	if (test_get_type("0.0f", FLOAT))
		return (3);
	if (test_get_type("0.0.0", UNKNOWN))
		return (4);
	if (test_get_type("0.0.0f", UNKNOWN))
		return (5);
	if (test_get_type(".0", DOUBLE))
		return (6);
	if (test_get_type(".0f", FLOAT))
		return (7);
	if (test_get_type("0.", DOUBLE))
		return (8);
	if (test_get_type("0.f", FLOAT))
		return (9);
	if (test_get_type("0.f0", UNKNOWN))
		return (9);
	if (test_get_type("0.0f0", UNKNOWN))
		return (10);
	if (test_get_type("a", CHAR))
		return (11);
	if (test_get_type("a0", UNKNOWN))
		return (12);
	if (test_get_type("f", CHAR))
		return (13);
	if (test_get_type("f0", UNKNOWN))
		return (14);
	if (test_get_type("0f", UNKNOWN))
		return (15);
	if (test_get_type("0f0", UNKNOWN))
		return (16);
	if (test_get_type("abc", UNKNOWN))
		return (17);
	if (test_get_type("abc0", UNKNOWN))
		return (18);
	if (test_get_type("0abc", UNKNOWN))
		return (19);
	if (test_get_type("++2", UNKNOWN))
		return (20);
	if (test_get_type("--2", UNKNOWN))
		return (21);
	if (test_get_type("+-2", UNKNOWN))
		return (22);
	if (test_get_type("2++", UNKNOWN))
		return (23);
	if (test_get_type("-2-", UNKNOWN))
		return (24);
	if (test_get_type("2-2", UNKNOWN))
		return (25);
	if (test_get_type("2.2.2", UNKNOWN))
		return (26);
	if (test_get_type("2.2.2f", UNKNOWN))
		return (27);
	if (test_get_type(" +2", UNKNOWN))
		return (28);
	if (test_get_type(" 2", UNKNOWN))
		return (29);
	if (test_get_type("2 ", UNKNOWN))
		return (30);
	if (test_get_type("2f", UNKNOWN))
		return (31);
	if (test_get_type("v2f", UNKNOWN))
		return (32);
	if (test_get_type(" ", CHAR))
		return (33);
	if (test_get_type("sd", UNKNOWN))
		return (34);
	return (0);
}
int	main()
{
	if (tests_get_type())
		return (1);
	return (0);
}