#include "ScalarConverter.hpp"
#include <iostream>
#include <cstring>
#include <cstdlib>

int	test_get_type(const char *input, e_type expected);
int	ft_strcmp(const char *s1, const char *s2);
int	anti_overflow_atoi(const char *input, int *result);

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
	if (test_get_type("+2", INT))
		return (35);
	if (test_get_type("-2", INT))
		return (36);
	return (0);
}

int	test_ft_strcmp(const char *s1, const char *s2)
{
	int	ret = ft_strcmp(s1, s2);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	int	expected = strcmp(s1, s2);

	if (!((!ret && !expected) || ret / abs(ret) == expected / abs(expected)))
	{
		std::cerr << "ft_strcmp(\"" << s1 << "\", \"" << s2 << "\") != " << expected << " (" << ret << ")" << std::endl;
		return (1);
	}
	return (0);
}

int	tests_ft_strcmp()
{
	if (test_ft_strcmp("abc", "abc"))
		return (1);
	if (test_ft_strcmp("abc", "abd"))
		return (2);
	if (test_ft_strcmp("abd", "abc"))
		return (3);
	if (test_ft_strcmp("abc", "abcd"))
		return (4);
	if (test_ft_strcmp("abcd", "abc"))
		return (5);
	if (test_ft_strcmp(NULL, "abc"))
		return (6);
	if (test_ft_strcmp("abc", NULL))
		return (7);
	if (test_ft_strcmp(NULL, NULL))
		return (8);
	if (test_ft_strcmp("", "abc"))
		return (9);
	if (test_ft_strcmp("abc", ""))
		return (10);
	if (test_ft_strcmp("", ""))
		return (11);
	if (test_ft_strcmp("abc", "abc\0abc"))
		return (12);
	if (test_ft_strcmp("abc\0abc", "abc"))
		return (13);
	return (0);
}

int	test_anti_overflow_atoi(const char *input, int expected_result, int expected_return)
{
	int	result;
	int	ret = anti_overflow_atoi(input, &result);
	if (ret != expected_return || (!ret && result != expected_result))
	{
		std::cerr << "anti_overflow_atoi(\"" << input << "\", " << expected_result << ", " << expected_return << ") != " << result << ", " << ret << std::endl;
		return (1);
	}
	return (0);
}

int	tests_anti_overflow_atoi()
{
	if (test_anti_overflow_atoi("0", 0, 0))
		return (1);
	if (test_anti_overflow_atoi("42", 42, 0))
		return (2);
	if (test_anti_overflow_atoi("-42", -42, 0))
		return (3);
	if (test_anti_overflow_atoi("2147483647", 2147483647, 0))
		return (3);
	if (test_anti_overflow_atoi("-2147483648", -2147483648, 0))
		return (4);
	if (test_anti_overflow_atoi("2147483648", 0, 1))
		return (5);
	if (test_anti_overflow_atoi("-2147483649", 0, 1))
		return (6);
	if (test_anti_overflow_atoi("21474836470", 0, 1))
		return (7);
	if (test_anti_overflow_atoi("-21474836480", 0, 1))
		return (8);
	if (test_anti_overflow_atoi("34578951231", 0, 1))
		return (9);
	if (test_anti_overflow_atoi("-34578951231", 0, 1))
		return (10);
	if (test_anti_overflow_atoi("11111111111", 0, 1))
		return (11);
	if (test_anti_overflow_atoi("-11111111111", 0, 1))
		return (12);
	return (0);
}

int	main()
{
	if (tests_get_type())
		return (1);
	if (tests_ft_strcmp())
		return (2);
	if (tests_anti_overflow_atoi())
		return (3);
	return (0);
}